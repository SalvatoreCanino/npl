#include "mex.hpp"
#include "newAdd.hpp"
#include "socket.hpp"
#include "sockaddress.hpp"
#include <iostream>
#include <thread>
#include <sys/socket.h>
#include <map>

typedef std::map< std::string, sockaddr > SrvMap;

using nlohmann::json;

void broadcasting(){
    npl::socket<AF_INET, SOCK_DGRAM> sock;
    sock.broadcast_enable();
    npl::sockaddress<AF_INET> broadcast("255.255.255.255", 20000);

    New_Broadcast_Server nchat { 
        .name = "Collegati qui", 
        .address = "0.0.0.0", 
        .port = 10010 
    };
    
    json jnchat;

    to_jsonAdd(jnchat, nchat);

    std::string snchat = jnchat.dump();

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
        json jm = json::parse(sm);

        to_json(jm, m);

        switch (m.code) {
            case "join":
                

                if(srvMap.size()<5){
                    srvMap[m.from] = client.c_addr();
                }
                

                break;
            case "leave":
            case "who":
            case "pm":
            default:
        
        }

        srvMap[m.from] = client.c_addr();


    }

}

int main(){

    std::thread tb(broadcasting);
    std::thread server(chatroom);
    
    tb.join();
    server.join();
    
}

    



