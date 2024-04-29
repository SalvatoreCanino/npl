#include "sockaddress.hpp"
#include "socket.hpp"
#include <iostream>
#include <algorithm>
#include <sys/socket.h>

int main(){

    //////////////////////////// 22 - 04 ////////////////////////////


    // Aprire il socket
    npl::socket<AF_INET, SOCK_DGRAM> sock;

    // Fare la bind
    //npl::sockaddress<AF_INET> srv_addr(15000);
    npl::sockaddress<AF_INET> srv_addr("172.29.231.198",15000);
    sock.bind(srv_addr);

    for(;;)
    {
        // Aspetto le richieste
        auto [buff, client] = sock.recvfrom(512);
        std::cout << "Received request from IP: "<< client.host()<< "\tPort: "<< client.port()<<std::endl; 

        // Rispondo
        std::transform(buff.begin(), buff.end(), buff.begin(),::toupper);
        sock.sendto(buff, client);

    }

    sock.close();
    return EXIT_SUCCESS;
}