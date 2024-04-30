#ifndef _SOCKET_HPP_
#define _SOCKET_HPP_
#include <cstddef>
#include <cstdint>
#include <system_error>
#include <unistd.h>
#include <vector>
#include <sys/socket.h>
#include "sockaddress.hpp"

namespace npl {

typedef std::vector<uint8_t> buffer;

template<int F, int type>
class socket {
private:
    int _sockfd;

public:
    explicit socket(int protocol = 0)
    {
        if ( ( _sockfd = ::socket(F,type,protocol)) == -1) {
            throw std::system_error(errno, std::generic_category(), "socket");
        }
    }

    socket(const socket& ) = delete;
    socket& operator=(const socket&) = delete;

    socket(socket&& rhs)
    : _sockfd(rhs._sockfd)
    {
        rhs._sockfd = -1;
    }

    socket& operator=(socket&& rhs)
    {
        if (*this != rhs)
        {
            this->close();
            _sockfd = rhs._sockfd;
            rhs._sockfd = -1;
        }
        return *this;
    }
    
    ~socket()
    {
        if (_sockfd != -1) {
            ::close(_sockfd);
        }
    }


    void close()
    {
        if (_sockfd != -1)
        {
            ::close(_sockfd);
            _sockfd = -1;
        }
    }


    void bind(const sockaddress<F>& addr)
    {
        if( (::bind(_sockfd, &addr.c_addr(), addr.len())) == -1)
        {
            throw std::system_error(errno, std::system_category(), "bind");
        }
    }


    void listen(int backlog = 5)
    {
        if( (::listen(_sockfd, backlog)) == -1)
        {
            throw std::system_error(errno, std::system_category(), "listen");
        }
    }

    std::pair< socket, sockaddress<F> > accept()
    {
        sockaddress<F> peer;
        socket acpt;

        if( (acpt._sockfd = ::accept(_sockfd, &peer.c_addr(), &peer.len())) == -1)
        {
            throw std::system_error(errno, std::system_category(), "accept");
        }

        return std::make_pair(std::move(acpt), peer);
    }

    void connect(const sockaddress<F>& remote)
    {
        if( (::connect(_sockfd, &remote.c_addr(), remote.len())) == -1)
        {
            throw std::system_error(errno, std::system_category(), "connect");
        }
    }

    ///////////////////////////////// I/O Methods ////////////////////////////////

    // socket connessi

    std::ptrdiff_t write(const buffer& buff) const
    {
        return ::write(_sockfd, &buff[0], buff.size());
    }

    // Versione alla C
    std::ptrdiff_t read(buffer& buff) const
    {
        return ::read(_sockfd, &buff[0], buff.size());
    }

    // Versione alla Python
    buffer read(size_t len)
    {
        buffer buff(len);
        int nbytes = ::read(_sockfd, &buff[0], buff.size());
        return buffer(buff.begin(), buff.begin()+nbytes);
    }

    std::ptrdiff_t readn(buffer& buf, ssize_t n ) const
    {
        std::ptrdiff_t num_read;
        std::ptrdiff_t tot_read = 0;

        while(tot_read < n)
        {
            num_read = ::read(_sockfd, &buf[tot_read], n - tot_read);

            if (num_read == 0)
                return tot_read;  // EOF reached;

            if (num_read == - 1)  // An error has happened
            {
                if (errno == EINTR) 
                    continue;     // Restart reading bytes in case of interrupt
                else 
                    return -1;  
            } 
            tot_read+= num_read;

        }
        return tot_read;
    }

    buffer readn(ssize_t len ) const
    {
        buffer buf(len);
        auto tot_read = this->readn(buf,len);
        return buffer(buf.begin(),buf.begin()+tot_read);
    }

    // socket connectionless

    std::ptrdiff_t sendto(const buffer& buff, const sockaddress<F>& remote, int flags = 0) const
    {
        return  ::sendto(_sockfd, &buff[0], buff.size(), flags, &remote.c_addr(), remote.len());
    }

    // Versione alla C
    std::ptrdiff_t recvfrom(buffer& buff, int flags, sockaddress<F>& remote) const
    {
        return recvfrom(_sockfd, &buff[0], buff.size(), flags, &remote.c_addr(), &remote.len());
    }

    // Versione alla Python
    std::pair< buffer, sockaddress<F> > recvfrom(int len, int flags = 0) const
    {
        buffer buff(len);
        sockaddress<F> peer;
        int nbytes = ::recvfrom(_sockfd, &buff[0], len, flags, &peer.c_addr(), &peer.len());
        return std::make_pair(buffer(buff.begin(), buff.begin() + nbytes), peer);

    }

     // Socket Options

    int broadcast_enable() 
    {
       int optval = 1;
       int out = ::setsockopt(_sockfd, SOL_SOCKET, SO_BROADCAST, &optval, sizeof(optval));
       if (out == -1) {
          throw std::system_error(errno,std::generic_category(),"broadcast_enable");
       }
       return out;
    }  

};
}

#endif