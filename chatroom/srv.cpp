#include "mex.hpp"
#include "newAdd.hpp"
#include "socket.hpp"
#include "sockaddress.hpp"
#include <cstddef>
#include <iostream>
#include <thread>
#include <sys/socket.h>
#include <map>

typedef std::unordered_map< std::string, npl::sockaddress<AF_INET> > SrvMap;

using nlohmann::json;

void broadcasting()
{
    npl::socket<AF_INET, SOCK_DGRAM> sock;
    sock.broadcast_enable();
    npl::sockaddress<AF_INET> broadcast("255.255.255.255", 20000);

    New_Broadcast_Server nchat { 
        .name = "Collegati qui", 
        .address = "0.0.0.0", 
        .port = 10010 
    };
    
    std::string snchat;
    to_stringAdd(snchat, nchat);

    for(;;)
    {
        sock.sendto(npl::buffer(snchat.begin(),snchat.end()), broadcast);
        sleep(2);
    }
}

void chatroom()
{
    npl::socket<AF_INET, SOCK_DGRAM> sock;
    sock.broadcast_enable();
    npl::sockaddress<AF_INET> srvaddr(10010);
    sock.bind(srvaddr);
    m_format m;
    SrvMap srvMap;

    for(;;){

        auto [buff, client] = sock.recvfrom(512);

        std::string sm = std::string(buff.begin()+1,buff.end()-1);
        
        to_string(sm, m);

        if(m.type == msg_type::C){

            std::string risposta;

            if(m.code.compare("join"))
            {
                risposta = "refusal";
                const auto& a = srvMap.emplace( 
                    std::piecewise_construct,
                    std::forward_as_tuple(m.from),
                    std::forward_as_tuple(client));
                
                if(a.second){
                    risposta = "welcome";
                    sock.sendto(npl::buffer(risposta.begin(),risposta.end()),client);
                    m_format responce{
                        .type = msg_type::D,
                        .text = m.from
                    };
                    to_string(risposta, responce);
                }

                sock.sendto(npl::buffer(risposta.begin(),risposta.end()),srvaddr);
                continue;
            }

            if(m.code.compare("leave") || m.code.compare("bye"))
            {
                auto a = srvMap.erase(m.from);
                if(!a)
                {
                    risposta = "not in the chat";
                    sock.sendto(npl::buffer(risposta.begin(),risposta.end()),client);
                }

                sock.sendto(npl::buffer(risposta.begin(),risposta.end()),srvaddr);
                continue;
            }

            if(m.code.compare("who"))
            {
                for( auto t : srvMap )
                {
                    risposta += t.first;
                    risposta += '\n';
                }

                sock.sendto(npl::buffer(risposta.begin(),risposta.end()),srvaddr);
                continue;
            }

            if(m.code.compare("pm"))
            {
                to_string(risposta, m);
                sock.sendto(npl::buffer(risposta.begin(),risposta.end()), srvMap[m.to]);
                continue;
            }
        
            risposta = "Wrong Code";
            sock.sendto(npl::buffer(risposta.begin(),risposta.end()), client);
            continue;
        }

        if (m.type == msg_type::D) 
        {
            sock.sendto(npl::buffer(m.text.begin(),m.text.end()), srvaddr);
            continue;
        }
        
    }

}

int main(){

    std::thread tb(broadcasting);
    std::thread server(chatroom);
    
    tb.join();
    server.join();
    
}
