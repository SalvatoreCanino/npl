///////////////////////////// 23 - 04 /////////////////////////

#include <iostream>
#include <sockaddress.hpp>
#include <socket.hpp>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  // Aprire il socket
  npl::socket<AF_INET, SOCK_STREAM> sock;

  // Fare la bind
  npl::sockaddress<AF_INET> srv_addr(16000);
  // npl::sockaddress<AF_INET> srv_addr("172.29.231.198",16000);
  sock.bind(srv_addr);

  // Fare la listen
  sock.listen();

  for (;;) {
    // Bisogna fare l'accept
    auto [nwsock, clt] = sock.accept();

    // Bisogna fare la fork
    auto pid = fork();

    std::cout << "Remote client: " << clt.host() << "\tPort: " << clt.port()
              << "\tconnected" << std::endl;

    if (pid == 0) // Children process
    {
      for (;;) {
        // Connessione creata e ora bisogna leggere e scrivere
        // si stanno leggendo caratteri, versione python
        auto buff = nwsock.read(256);
        if (buff.empty())
          break;
        std::transform(buff.begin(), buff.end(), buff.begin(), ::toupper);
        nwsock.write(buff);
      }

        nwsock.close();
        std::cout << "Remote client: " << clt.host() << "\tPort: " << clt.port()
                << "\tdisconnected" << std::endl;
        exit(EXIT_SUCCESS);
    }
    //Parent process
    nwsock.close();

  }

  sock.close();

  return EXIT_SUCCESS;
}