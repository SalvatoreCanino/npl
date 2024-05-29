#include "sockaddress.hpp"
#include "socket.hpp"
#include <iostream>
#include <sys/socket.h>
#include "mex_format.hpp"

using nlohmann::json;

int main()
{
    npl::sockaddress<AF_INET> srv_addr(12000);
    npl::socket<AF_INET, SOCK_DGRAM> sock;

    std::string snd, rcv;
    json j;
    mex m;

    for(;;)
    {   
        std::cout<<"Type of Mex:  ";
        std::cin>>m.type;
        to_json(j, m);
        snd = j.dump();

        npl::buffer buff(snd.begin(),snd.end());
        sock.sendto(buff, srv_addr);

        auto [bb, srv] = sock.recvfrom(512);
        rcv = std::string(bb.begin(),bb.end());
        j = json::parse(rcv);
        from_json(j, m);
        std::cout<<m.text<<std::endl;
    }

    sock.close();
    return EXIT_SUCCESS;
}