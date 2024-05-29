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

using nlohmann::json;

npl::sockaddress<AF_INET> srv_addr(12000);
npl::socket<AF_INET, SOCK_DGRAM> sock;

struct func_elabora{

    struct flow{
        std::string src_ip;
        std::string dst_ip;
        int src_port;
        int dst_port;
        int len;
    };

    void to_json(json& j, const flow& f)
    {
        j = json{
            {"src_ip", f.src_ip},
            {"dst_ip", f.dst_ip},
            {"src_port", f.src_port},
            {"dst_port", f.dst_port},
            {"len", f.len}
        };
    }

    void operator()(const struct pcap_pkthdr *hdr, const u_char *pkt_ptr)
    {
        flow f;
        npl::packet<hdr::ether> frame(pkt_ptr, hdr->caplen);
        auto ip = frame.get<hdr::ipv4>().front();

        f.src_ip = ip.src();
        f.dst_ip = ip.dst();
        f.len = ip.len();

        auto tcp = frame.get<hdr::tcp>().front();

        f.src_port = tcp.srcport();
        f.dst_port = tcp.dstport();

        json j;
        to_json(j, f);
        std::string mex = j.dump();

        npl::buffer buff(mex.begin(),mex.end());
        sock.sendto(buff, srv_addr);

        //std::cout<<mex<<std::endl;

    }

};


int main(int argc, char* argv[]){

  if (argc < 3) {
    std::cout << "Usage: " << argv[0] << " -i <iface> | -f <filename>" << std::endl;
    return EXIT_FAILURE;
  }

  func_elabora elab;
  std::string rule = "tcp";
  std::string flag(argv[1]);
  std::string dev(argv[2]);

  if (flag == "-f") {
    npl::pcap::reader<offline> tap(dev);
    tap.filter(rule);
    tap.loop(elab);
  } 
  else {
    npl::pcap::reader<live> tap(dev);
    tap.open();
    tap.filter(rule);
    //tap.print_bpf_program();
    tap.loop(elab);
  }
  return EXIT_SUCCESS;
}