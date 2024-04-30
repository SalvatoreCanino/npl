#ifndef _HEADER_HPP_
#define _HEADER_HPP_

#include "socket.hpp"
#include <cstdint>
#include <string>
#include <iostream>
#include <bits/stdc++.h> 

namespace npl {

    union mess_hdr
    {
        unsigned short len;
        uint8_t raw[2];
    };

    void wraphdr(npl::buffer& buff)
    {
        mess_hdr m { htons(buff.size()) };
        buff.insert(buff.begin() , m.raw, m.raw+2);
    }

    uint16_t readhdr(const npl::buffer buff)
    {
        mess_hdr m;
        std::copy(buff.begin(),buff.begin()+2,m.raw);
        return ntohs(m.len);
    }
}

#endif