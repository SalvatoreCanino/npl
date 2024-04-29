#include "sockaddress.hpp"
#include "socket.hpp"
#include "header.hpp"
#include <iostream>
#include <sys/socket.h>


int main(int argc, char* argv[])
{
    //////////////////////////// 23 - 04 ////////////////////////////

    if(argc < 3)
    {
        std::cout<< "Usage: "<<argv[0]<<"\t<tcp_srv>\t<port>"<<std::endl;
        return EXIT_FAILURE;
    }

    std::string srv_ip = argv[1];

    int port = atoi(argv[2]);

    npl::sockaddress<AF_INET> srv_addr(srv_ip, port);

    npl::socket<AF_INET, SOCK_STREAM> sock;

    sock.connect(srv_addr);

    std::string mex;

    while(1)
    {
        std::getline(std::cin, mex);
        
        npl::buffer buff(mex.begin(),mex.end());
        npl::wrap(buff);

        std::cout<<"buff:\t"<<std::string(buff.begin(),buff.end())<<std::endl;

        sock.write(buff);

        auto bb = sock.readn(2);
        auto buff2 = sock.readn(npl::readhdr(bb));

        std::cout<<"buff2:\t"<<std::string(buff2.begin(),buff2.end())<<std::endl;
    }

    sock.close();
    return EXIT_SUCCESS;
}