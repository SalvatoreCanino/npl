#ifndef _SOCKADRRESS_HPP_
#define _SOCKADRRESS_HPP_

#include "socket.hpp"
#include <cstddef>
#include<cstring>
#define INET_ADDRSTRLEN  16 

#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <vector>

namespace npl {

template <int F>
class sockaddress;

template <>
class sockaddress<AF_INET> {
private:
    socklen_t _len;
    sockaddr_in _addr;

public:
    
    explicit sockaddress(in_port_t port = 0)
    :_len(sizeof(sockaddr_in))
    {
        ::memset(&_addr, 0, _len);
        _addr.sin_family = AF_INET;
        _addr.sin_addr.s_addr = htonl(INADDR_ANY);
        _addr.sin_port = htons(port);
        
    }

    sockaddress(const sockaddr_in &_addr);

    sockaddress(const in_addr &ip, in_port_t port);

    sockaddress(const std::string& host, const in_port_t port)
    : _len(sizeof(sockaddr_in))
    {
        struct addrinfo hint, *result;
        hint.ai_family = AF_INET;
        hint.ai_socktype = 0;
        hint.ai_protocol = 0;
        hint.ai_flags = 0;
        if( ::getaddrinfo(host.c_str(), std::to_string(port).c_str(), &hint , &result ) != 0 )
        {
            throw std::system_error(errno, std::generic_category(), "getaddressinfo");
        }

        _addr = *reinterpret_cast<struct sockaddr_in*>(result->ai_addr);

        freeaddrinfo(result);

    }


    sockaddress(const std::string& host, const std::string& service)
    : _len(sizeof(sockaddr_in))
    {
        struct addrinfo hint, *result;
        hint.ai_family = AF_INET;
        hint.ai_socktype = 0;
        hint.ai_protocol = 0;
        hint.ai_flags = 0;
        if( ::getaddrinfo(host.c_str(), service.c_str(), &hint, &result) != 0 )
        {
            throw std::system_error(errno, std::generic_category(), "getaddressinfo");
        }

        _addr = *reinterpret_cast<struct sockaddr_in*>(result->ai_addr);

        freeaddrinfo(result);
    }
    
    sockaddress(const sockaddress&)            = default;
    sockaddress& operator=(const sockaddress&) = default;
    sockaddress(sockaddress&&)                 = default;
    sockaddress& operator=(sockaddress&&)      = default;
    ~sockaddress()                             = default;

    unsigned short port() const
    {
        return ntohs(_addr.sin_port);
    }


    std::string host() const    // Return the IP address in the dotted form
    {
        char dst_str[INET_ADDRSTRLEN];
        if(::inet_ntop(AF_INET, &_addr.sin_addr.s_addr, dst_str, INET_ADDRSTRLEN) == NULL)
        {
            throw std::system_error(errno, std::generic_category(), "inet_ntop");
        }
        return static_cast<std::string>(dst_str);

    }


    unsigned short family() const
    {
        return static_cast<unsigned short>(_addr.sin_family);
    }

    socklen_t len() const     // Note: const is part of the signature!
    {
        return _len;
    }


    socklen_t& len()
    {
        return _len;
    }

    const sockaddr& c_addr() const
    { 
        return reinterpret_cast<const sockaddr&>(_addr);    
    }                            

    sockaddr& c_addr()
    {
        return reinterpret_cast<sockaddr&>(_addr);
    }

    std::pair<std::string, std::string> getnameinfo() const
    {
        char h[NI_MAXHOST],s[NI_MAXSERV];
        if( ::getnameinfo(&c_addr(), len(), (char*)&h, NI_MAXHOST, (char*)&s, NI_MAXSERV, 0) != 0 )
        {
            throw std::system_error(errno, std::generic_category(), "getnameinfo");
        }    
    
        return std::make_pair(std::string(h) ,std::string(s));
    }


};

}


#endif