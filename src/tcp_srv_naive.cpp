///////////////////////////// 23 - 04 /////////////////////////

#include <iostream>
#include <socket.hpp>
#include <sockaddress.hpp>
#include <sys/socket.h>


int main()
{
    // Aprire il socket
    npl::socket<AF_INET, SOCK_STREAM> sock;

    // Fare la bind
    npl::sockaddress<AF_INET> srv_addr(16000);
    //npl::sockaddress<AF_INET> srv_addr("172.29.231.198",16000);
    sock.bind(srv_addr);

    // Fare la listen
    sock.listen();

    for(;;)
    {
        // Bisogna fare l'accept
        auto [nwsock, clt] = sock.accept();
        std::cout<< "Remote client: "<< clt.host() << "\tPort: "<< clt.port()<< "\tconnected" <<std::endl;

        for(;;)
        {
            // Connessione creata e ora bisogna leggere e scrivere
            // si stanno leggendo caratteri, versione python
            auto buff = nwsock.read(256);
            if(buff.empty())
                break;
            std::transform(buff.begin(), buff.end(), buff.begin(),::toupper);
            nwsock.write(buff);
        }

        nwsock.close();
        std::cout<< "Remote client: "<< clt.host() << "\tPort: "<< clt.port()<< "\tdisconnected" <<std::endl;

    }

    sock.close();

    return EXIT_SUCCESS;
}