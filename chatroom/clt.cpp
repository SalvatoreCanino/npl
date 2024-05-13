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
    npl::buffer bb(512);

    for(;;){

        std::getline(std::cin, mex);
        npl::buffer buff1(mex.begin(),mex.end());
        sock1.sendto(buff1, nwaddr);

        sock1.recvfrom(bb, nwaddr);
        std::cout<<std::string(bb.begin(),bb.end())<<std::endl;

    }
    sock1.close();
    return EXIT_SUCCESS;
}