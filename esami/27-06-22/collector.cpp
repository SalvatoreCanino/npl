#include <cstring>
#include <iostream>
#include <pcap/pcap.h>
#include <string>
#include <thread>
#include "packet.hpp"
#include "pcap.hpp"
#include "json.hpp"
#include "sockaddress.hpp"
#include "socket.hpp"
#include <iostream>
#include <algorithm>
#include <sys/socket.h>
#include <boost/lockfree/lockfree_forward.hpp>
#include <boost/lockfree/policies.hpp>
#include <boost/lockfree/spsc_queue.hpp>
#include <boost/algorithm/string.hpp>

using nlohmann::json;
typedef std::tuple<std::string, std::string, std::string, std::string, int> tcp_entry;
boost::lockfree::spsc_queue<tcp_entry, boost::lockfree::capacity<1024>> queue;

struct flow{
    std::string src_ip;
    std::string dst_ip;
    int src_port;
    int dst_port;
    int len;
};

void from_json(const json& j, flow& f)
{
    j.at("src_ip").get_to(f.src_ip);
    j.at("dst_ip").get_to(f.dst_ip);
    j.at("src_port").get_to(f.src_port);
    j.at("dst_port").get_to(f.dst_port);
    j.at("len").get_to(f.len);
}

struct {

    std::unordered_map<std::string , int> hitters;

    void operator()(const tcp_entry& entry)
    {
        std::string k;
        k += get<0>(entry) + '\t';
        k += get<1>(entry) + '\t';
        k += get<2>(entry) + '\t';
        k += get<3>(entry) + '\t';
        
        hitters[k] += get<4>(entry);
    }

}tomap;

void print_hitters()
{
    // Lambda func per fare il compare
    auto cmp = [](tcp_entry x, tcp_entry y){
        return (get<4>(x) > get<4>(y));
    };

    auto last_ts = std::chrono::steady_clock::now();

    std::vector<tcp_entry> volume_vec;

    std::vector<std::string> strs;

    for(;;)
    {
        queue.consume_all(tomap);
        auto now = std::chrono::steady_clock::now();
        auto delta = std::chrono::duration_cast<std::chrono::seconds>(now-last_ts).count();

        if(delta > 20)
        {
            // Trasferisco i dati dalla mappa ad un vettore
            for (auto [k, v] : tomap.hitters) 
            {
                tcp_entry dato;
    
                boost::split(strs, k, boost::is_any_of("\t"));

                get<0>(dato) = strs.at(0);
                get<1>(dato) = strs.at(1);
                get<2>(dato) = strs.at(2);
                get<3>(dato) = strs.at(3);
                get<4>(dato) = v;
                volume_vec.push_back(dato);
            }

            if(!volume_vec.empty()){
                std::sort(volume_vec.begin(), volume_vec.end(), cmp);
                std::cout<<"---------Top Five--------"<<std::endl;
                std::cout<<"IPs \t\t IPd \t\t PortS \t\t PortD"<<std::endl;

                for(auto i=0; i<std::min<int>(5, volume_vec.size()); i++)
                {
                    std::cout<< get<0>(volume_vec[i]) << "\t" << get<1>(volume_vec[i]) << "\t" << get<2>(volume_vec[i]) << "\t\t"<< get<3>(volume_vec[i])<<std::endl;
                }
                std::cout<<"------------------------"<<std::endl;
                volume_vec.clear();
            }
            last_ts = std::chrono::steady_clock::now();            
        }
    
    }

}

int main(){

    npl::socket<AF_INET, SOCK_DGRAM> sock;
    npl::sockaddress<AF_INET> srv_addr(12000);
    sock.bind(srv_addr);

    std::thread t(print_hitters);
    t.detach();

    for(;;)
    {
        auto [buff, client] = sock.recvfrom(512);
        std::string mex(buff.begin(), buff.end());
        json j = json::parse( mex );
        flow f;
        from_json(j, f);

        //std::cout<<f.src_ip<<'\t'<<f.dst_ip<<'\t'<<f.src_port<<'\t'<<f.dst_port<<'\t'<<f.len<<std::endl;

        tcp_entry md = std::make_tuple(f.src_ip, f.dst_ip, std::to_string(f.src_port), std::to_string(f.dst_port), f.len);

        //std::cout<<get<0>(md)<<'\t'<<get<1>(md)<<std::endl;

        queue.push(md);
    }
    sock.close();
    return EXIT_SUCCESS;
}