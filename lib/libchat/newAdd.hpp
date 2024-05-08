#ifndef _NEWADD_HPP_
#define _NEWADD_HPP_

struct New_Broadcast_Server{
    std::string name;
    std::string address;
    unsigned short port;
};

void to_jsonAdd(json& j, const New_Broadcast_Server& s)
{
    j = json {  { {"name", s.name}, {"address", s.address}, {"port", s.port} }};
}


void from_jsonAdd(const json& j, New_Broadcast_Server& s)
{
    j.at("name").get_to(s.name);
    j.at("address").get_to(s.address);
    j.at("port").get_to(s.port);
}

#endif