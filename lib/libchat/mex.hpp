#ifndef _MEX_HPP_
#define _MEX_HPP_


#include "json.hpp"

using nlohmann::json;

enum class msg_type {C,D};

struct m_format
{
    msg_type type;
    std::string code;
    std::string to;
    std::string from;
    std::string text;
};

void to_json(json& j, const m_format& m_form)
{
    j = json {{"msg_type", m_form.type}, {"code", m_form.code}, {"to", m_form.to}, {"from", m_form.from}, {"text", m_form.text} };
}

void to_string(std::string& s, const m_format& m_form)
{
    json j;
    to_json(j, m_form);
    s = j.dump();
}

void from_json(const json& j, m_format& m_form)
{
    j.at("msg_type").get_to(m_form.type);
    j.at("code").get_to(m_form.code);
    j.at("to").get_to(m_form.to);
    j.at("from").get_to(m_form.from);
    j.at("text").get_to(m_form.text);
}

void from_string(const std::string& s, m_format& m_form)
{
    json j = json::parse(s);
    from_json(j, m_form);  
}

#endif