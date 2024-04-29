#include <iostream>
#include <sockaddress.hpp>
#include <socket.hpp>
#include <thread>
#include "header.hpp"
#include <sys/socket.h>

///////////////////////////// 23 - 04 /////////////////////////

void capital_echo(npl::socket<AF_INET, SOCK_STREAM>&& connected, const npl::sockaddress<AF_INET>& client) 
{
  std::cout << "Remote client: " << client.host() << "\tPort: " << client.port()<< "\tconnected" << std::endl;

  for (;;) {
    // Connessione creata e ora bisogna leggere e scrivere
    // si stanno leggendo caratteri, versione python
    auto buff = connected.read(256);
    if (buff.empty())
      break;
    std::transform(buff.begin()+2, buff.end(), buff.begin()+2, ::toupper);
    std::cout<<npl::readhdr(buff)<<std::endl;
    connected.write(buff);
  }
  connected.close();
  std::cout << "Remote client: " << client.host() << "\tPort: " << client.port()<< "\tdisconnected" << std::endl;
}

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

    // Creo il trhead
    std::thread t(capital_echo, std::move(nwsock), clt);
    t.detach();



  }

  sock.close();

  return EXIT_SUCCESS;
}