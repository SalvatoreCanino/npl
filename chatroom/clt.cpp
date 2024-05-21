#include "mex.hpp"
#include "newAdd.hpp"
#include "socket.hpp"
#include "sockaddress.hpp"
#include <cstddef>
#include <iostream>
#include <thread>
#include <sys/socket.h>


using nlohmann::json;


int main(){

    npl::socket<AF_INET, SOCK_DGRAM> sock;
    npl::sockaddress<AF_INET> broadcast("255.255.255.255", 20000);
    sock.bind(broadcast);

    auto [buff, client] = sock.recvfrom(512);

    std::string srx = std::string(buff.begin()+1, buff.end()-1);
    std::cout<< srx<<std::endl;

    New_Broadcast_Server rx;
    from_stringAdd(srx, rx);

    sock.close();

    npl::socket<AF_INET, SOCK_DGRAM> sock1;
    npl::sockaddress<AF_INET> nwaddr(rx.address, rx.port);

    std::string mex;
    m_format mtx;
    npl::buffer bb(512);

    for(;;){
        std::cout<<"Type of Mex: (Controll or Data)"<<std::endl;
        std::getline(std::cin, mex);

        if (!(mex.compare("C")) || !(mex.compare("D"))) {
            std::cout<<"Wrog Code"<<std::endl;
            continue;
        }

        if(mex.compare("C")){
            mtx.type = msg_type::C;
            std::cout<<"Insert the Code"<<std::endl;
            std::getline(std::cin, mtx.code);
            if(mtx.code.compare("join"))
            {
                std::cout<<"Insert Name"<<std::endl;
                std::getline(std::cin, mtx.from); 
            }
            if(mtx.code.compare("pm"))
            {
                std::cout<<"Insert Name to Contact"<<std::endl;
                std::getline(std::cin, mtx.to); 
                std::cout<<"Insert the Text to Send"<<std::endl;
                std::getline(std::cin, mtx.text);
            }
        }

        if(mex.compare("D")){
            mtx.type = msg_type::D;
            std::cout<<"Insert the Text to Send"<<std::endl;
            std::getline(std::cin, mtx.text); 
        }

        from_string(mex, mtx);

        npl::buffer buff1(mex.begin(),mex.end());
        sock1.sendto(buff1, nwaddr);

        sock1.recvfrom(bb, nwaddr);
        std::cout<<std::string(bb.begin(),bb.end())<<std::endl;

    }
    sock1.close();
    return EXIT_SUCCESS;
}