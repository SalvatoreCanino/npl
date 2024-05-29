#ifndef _MEX_FORMAT_
#define _MEX_FORMAT_

#include "json.hpp"

using nlohmann::json;

struct mex{

    std::string type;
    std::string text;
    
};

void to_json(json& j, const mex& m)
{
    j = { {"type", m.type}, {"text", m.text} };
}

void from_json(const json& j, mex& m)
{
    j.at("type").get_to(m.type);
    j.at("text").get_to(m.text);
}

#endif