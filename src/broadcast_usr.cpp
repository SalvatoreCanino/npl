#include "sockaddress.hpp"
#include "socket.hpp"
#include <iostream>
#include <algorithm>
#include <sys/socket.h>
#include <unistd.h>
#include "json.hpp"

///////////////////////////// 30 - 04 /////////////////////////////

using nlohmann::json;

struct New_Broadcast_Server{
    std::string name;
    std::string address;
    unsigned short port;
};

void to_json(json& j, const New_Broadcast_Server& s)
{
    j = json {  { {"name", s.name}, {"address", s.address}, {"port", s.port} }};
}


void from_json(const json& j, New_Broadcast_Server& s)
{
    j.at("name").get_to(s.name);
    j.at("address").get_to(s.address);
    j.at("port").get_to(s.port);
}

int main(){

     // Aprire il socket
    npl::socket<AF_INET, SOCK_DGRAM> sock;

    npl::sockaddress<AF_INET> broadcast("255.255.255.255", 20000);

    sock.bind(broadcast);

    auto [buff, client] = sock.recvfrom(512);

    std::string srx = std::string(buff.begin()+1, buff.end()-1);
    std::cout<< srx<<std::endl;

    json jrx = json::parse(srx);

    New_Broadcast_Server rx;

    from_json(jrx, rx);

    npl::sockaddress<AF_INET> nwaddr(rx.address, rx.port);

    sock.close();

    npl::socket<AF_INET, SOCK_DGRAM> sock1;

    std::string mex;

    for(;;){

        std::getline(std::cin, mex);
        npl::buffer buff(mex.begin(),mex.end());
        sock1.sendto(buff, nwaddr);

        auto [bb, srv] = sock1.recvfrom(512);
        std::cout<<std::string(bb.begin(),bb.end())<<std::endl;

    }
    sock1.close();
    return EXIT_SUCCESS;
}