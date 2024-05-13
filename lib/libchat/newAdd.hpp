#ifndef _NEWADD_HPP_
#define _NEWADD_HPP_

struct New_Broadcast_Server{
    std::string name;
    std::string address;
    unsigned short port;
};

void to_jsonAdd(json& j, const New_Broadcast_Server& nbs)
{
    j = json {  { {"name", nbs.name}, {"address", nbs.address}, {"port", nbs.port} }};
}

void to_stringAdd(std::string & s, const New_Broadcast_Server& nbs)
{
    json j;
    to_jsonAdd(j, nbs);
    s = j.dump();
}

void from_jsonAdd(const json& j, New_Broadcast_Server& nbs)
{
    j.at("name").get_to(nbs.name);
    j.at("address").get_to(nbs.address);
    j.at("port").get_to(nbs.port);
}

void from_stringAdd(const std::string& s, New_Broadcast_Server& nbs)
{
    json j = json::parse(s);
    from_jsonAdd(j, nbs);
}

#endif