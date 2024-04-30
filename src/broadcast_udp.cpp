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
    sock.broadcast_enable();

    // Invia messaggi in automatico
    New_Broadcast_Server nbs { 
        .name = "Collegati qui", 
        .address = "172.168.1.0", 
        .port = 18000 
    };

    json jnbs = nbs;

    // così si può serializzare e inviare
    std::string sjnbs = jnbs.dump();

    //std::cout << sjnbs << std::endl;

    npl::sockaddress<AF_INET> broadcast("255.255.255.255", 20000);
    
    for(;;)
    {
        sock.sendto(npl::buffer(sjnbs.begin(),sjnbs.end()), broadcast);
        sleep(2);
    }

    sock.close();
    return EXIT_SUCCESS;

}