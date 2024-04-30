#include "socket.hpp"
#include <sys/socket.h>
#include <iostream>
#include "json.hpp"

using nlohmann::json;

struct student
{
    unsigned long id;
    std::string name;

};

void to_json(json& j, const student& s)
{
    j = json {  { "id", s.id}, { "name", s.name}  };
}


void from_json(const json& j, student& s)
{
    j.at("id").get_to(s.id);
    j.at("name").get_to(s.name);
}


int main()
{
    /*
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

    std::cout << addr1.getnameinfo().first <<'\t'<< addr1.getnameinfo().second << std::endl;*/


    ///////////////////////////// 29 - 04 ///////////////////////////

    student io {.id = 548074, .name = "Salvatore"};

    json jo = io;

    // così si può serializzare e inviare
    std::string sjo = jo.dump();

    std::cout << sjo << std::endl;

    // stringa ricevuta
    json rx = json::parse(sjo);

    std::cout<< "Name: "<< rx.at("name").get<std::string>()<<"Id: "<<rx.at("id").get<unsigned long>()<<std::endl;


}