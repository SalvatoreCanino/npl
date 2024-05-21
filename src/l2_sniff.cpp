#include <cstdlib>
#include <iostream>
#include <ostream>
#include <sys/socket.h>
#include "headers.hpp"
#include "packet.hpp"
#include "sockaddress.hpp"
#include "socket.hpp"
#include <net/ethernet.h>


int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <iface>" << std::endl;
        return EXIT_FAILURE;
    }


    npl::socket<AF_PACKET, SOCK_RAW> sock(ntohs(ETH_P_ALL));
    npl::sockaddress<AF_PACKET> device(argv[1]);
    sock.bind(device);
    sock.set_promisc(argv[1]);


    for(;;)
    {
        auto buf = sock.recv(2000);
        npl::packet<hdr::ether> p(buf.data(), buf.size());

        auto all = p.dump();
        for (auto x : all) {
            std::cout<< PROTOCOL_NAME.at(x.first)<<"\t:\t";
        }
        std::cout<<std::endl;
    }

    return EXIT_SUCCESS;
}