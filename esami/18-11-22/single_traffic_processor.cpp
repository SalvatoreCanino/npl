#include <cstring>
#include <iostream>
#include <pcap/pcap.h>
#include <string>
#include <thread>
#include "packet.hpp"
#include "pcap.hpp"
#include <algorithm>

std::atomic<int> nip_o = 0;
std::atomic<int> ntcp_o = 0;
std::atomic<int> nip = 0;
std::atomic<int> ntcp = 0;

struct func_elabora{

    void operator()(const struct pcap_pkthdr *hdr, const u_char *pkt_ptr)
    {
        npl::packet<hdr::ether> frame(pkt_ptr, hdr->caplen);
        
        if(frame.has<hdr::ipv4>() != 0)
        {
            auto ip = frame.get<hdr::ipv4>().front();
            auto ip_o = ip.options();  
            nip++;

            if(!ip_o.empty())
            {
                nip_o++;
            }

            if(frame.has<hdr::tcp>() != 0)
            {
                auto tcp = frame.get<hdr::tcp>().front();
                auto tcp_o = tcp.options();
                ntcp++;

                if(!tcp_o.empty())
                {
                    ntcp_o++;
                }
            }
        }
    }
};

void show()
{
    auto last_ts = std::chrono::steady_clock::now();

    for(;;)
    {   
        auto now = std::chrono::steady_clock::now();
        auto delta = std::chrono::duration_cast<std::chrono::seconds>(now-last_ts).count();

        if(delta > 5)
        {   
            std::cout<<"--------------Percentuale--------------"<<std::endl;
            if(nip != 0){
                float ipper = (nip_o/nip)*100;
                std::cout<<"IP_Option:  "<<nip_o<<"/"<<nip<<"  =  "<< ipper <<"%"<<std::endl;
            }
            if( ntcp != 0){
                float tcpper = (ntcp_o/ntcp)*100;
                std::cout<<"TCP_Option: "<<ntcp_o<<"/"<<ntcp<<"  =  "<< tcpper<<"%"<<std::endl;
            }
            std::cout<<"---------------------------------------"<<std::endl;
            last_ts = std::chrono::steady_clock::now();
        }
    }
}



int main(int argc, char* argv[]){

  if (argc < 3) {
    std::cout << "Usage: " << argv[0] << " -i <iface> | -f <filename>" << std::endl;
    return EXIT_FAILURE;
  }

  func_elabora elab;
  std::string flag(argv[1]);
  std::string dev(argv[2]);

  if (flag == "-f") {
    npl::pcap::reader<offline> tap(dev);
    std::thread t(show);
    tap.loop(elab);
    bool b = true;
    for(;;){ if(b){std::cout<<"FIN"<<std::endl; b=false;}}
  } 
  else {
    npl::pcap::reader<live> tap(dev);
    tap.open();
    std::thread t(show);
    tap.loop(elab);
  }
  return EXIT_SUCCESS;
}