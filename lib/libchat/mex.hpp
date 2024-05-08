#ifndef _MEX_HPP_
#define _MEX_HPP_


#include "json.hpp"

using nlohmann::json;

struct m_format
{
    std::string code;
    std::string to;
    std::string from;
    std::string text;
};

void to_json(json& j, const m_format& s)
{
    j = json {{"code", s.code}, {"to", s.to}, {"from", s.from}, {"text", s.text} };
}


void from_json(const json& j, m_format& s)
{
    j.at("code").get_to(s.code);
    j.at("to").get_to(s.to);
    j.at("from").get_to(s.from);
    j.at("text").get_to(s.text);
}






#endif