#include "socket.hpp"
#include <sys/socket.h>
#include <iostream>

int main()
{
    ///////////////////////////// 15 - 04 //////////////////////////

    npl::socket<AF_INET, SOCK_STREAM> sock;
    npl::sockaddress<AF_INET> addr("localhost",1000);
    npl::sockaddress<AF_INET> addr1("localhost","https");
    npl::sockaddress<AF_INET> addr2("www.google.com",2000);
    
    npl::sockaddress<AF_INET> addr3(10000);

    std::cout << "IP: " << addr.host() << "   Port: " << addr.port() << std::endl;
    std::cout << "IP: " << addr1.host() << "   Port: " << addr1.port() << std::endl;
    std::cout << "IP: " << addr2.host() << "   Port: " << addr2.port() << std::endl;
    std::cout << "IP: " << addr3.host() << "   Port: " << addr3.port() << std::endl;

    std::cout << addr1.getnameinfo().first <<'\t'<< addr1.getnameinfo().second << std::endl;

    //////////////////////////// 22 - 04 ////////////////////////////

    


    
}