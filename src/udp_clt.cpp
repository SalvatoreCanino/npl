#include "sockaddress.hpp"
#include "socket.hpp"
#include <iostream>
#include <sys/socket.h>


int main(int argc, char* argv[])
{
    //////////////////////////// 22 - 04 ////////////////////////////

    if(argc < 3)
    {
        std::cout<< "Usage: "<<argv[0]<<"\t<udp_srv>\t<port>"<<std::endl;
        return EXIT_FAILURE;
    }

    std::string srv_ip = argv[1];

    int port = atoi(argv[2]);

    npl::sockaddress<AF_INET> srv_addr(srv_ip, port);

    npl::socket<AF_INET, SOCK_DGRAM> sock;

    std::string mex;

    while(1)
    {
        std::getline(std::cin, mex);
        npl::buffer buff(mex.begin(),mex.end());
        sock.sendto(buff, srv_addr);

        auto [bb, srv] = sock.recvfrom(512);
        std::cout<<std::string(bb.begin(),bb.end())<<std::endl;
    }

    sock.close();
    return EXIT_SUCCESS;
}