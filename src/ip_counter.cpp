#include "packet.hpp"
#include "pcap.hpp"
#include <boost/lockfree/lockfree_forward.hpp>
#include <boost/lockfree/policies.hpp>
#include <cstring>
#include <iostream>
#include <pcap/pcap.h>
#include <string>
#include <thread>
#include <boost/lockfree/spsc_queue.hpp>

typedef std::pair<std::string, int> ip_entry;

struct md_producer{

  boost::lockfree::spsc_queue<ip_entry, boost::lockfree::capacity<1024>> queue;

  void operator()(const struct pcap_pkthdr *hdr, const u_char *pkt_ptr )
  {
    npl::packet<hdr::ether> frame(pkt_ptr, hdr->caplen);
    
    auto ip = frame.get<hdr::ipv4>()[0];
    ip_entry md = std::make_pair(ip.src(), ip.len());

    queue.push(md);
    
  }
  
};

void md_consumer(md_producer& md_func)
{
  //std::unordered_map<std::string, std::pair<int, int>> ip_volume_map;
  typedef std::pair<std::string, std::pair<int, int>> vec_entry;


  struct {
    // Così la mappa è lo stato del funtore
    std::unordered_map<std::string, std::pair<int, int>> ip_volume_map;

    void operator()(const ip_entry& entry)
    {
      ip_volume_map[entry.first].first++;
      ip_volume_map[entry.first].second += entry.second;
    }

  } fill_map;

  
  // Lambda func per fare il compare
  auto cmp = [](vec_entry x, vec_entry y){
    return (x.second.second > y.second.second);
  };

  auto last_ts = std::chrono::steady_clock::now();

  for(;;)
  {

    md_func.queue.consume_all(fill_map);

    /*
    if(!md_func.queue.empty())
    {
      ip_entry md;
      md_func.queue.pop(md);

      ip_volume_map[md.first].first++;
      ip_volume_map[md.first].second += md.second;
    }*/

    auto now = std::chrono::steady_clock::now();
    auto delta = std::chrono::duration_cast<std::chrono::seconds>(now-last_ts).count();

    if(delta > 5)
    {
      std::vector<vec_entry> volume_vec;

      // Trasferisco i dati dalla mappa ad un vettore
      for(auto& x : fill_map.ip_volume_map)
      {
        volume_vec.push_back(x);
      }

      // Ordino
      std::sort(volume_vec.begin(), volume_vec.end(), cmp);

      std::cout<<"---------Top Ten--------"<<std::endl;
      std::cout<<"IP \t\t\t pkts \t bytes"<<std::endl;

      for(auto i=0; i<std::min<int>(10, volume_vec.size()); i++)
      {
        std::cout<< volume_vec[i].first<<" \t\t "<<volume_vec[i].second.first<<" \t "<<volume_vec[i].second.second<<std::endl;
      }
      std::cout<<"------------------------"<<std::endl;

      last_ts = std::chrono::steady_clock::now();

    }
    
  }

}

int main(int argc, char* argv[])
{

  if (argc < 3) {
    std::cout << "Usage: " << argv[0] << " -i <iface> "
              << "( r <rule> )" << std::endl;
    return EXIT_FAILURE;
  }

  std::string dev(argv[2]);
/*
  if (!strcmp(argv[1], "-i")) {
    return EXIT_FAILURE;
  } */

  std::string rule = "ip";

  npl::pcap::reader<live> tap(dev);
  tap.open();
  if (argc > 3) {
    rule += "and";
    rule += argv[3];
  }

  tap.filter(rule);
  
  md_producer extract_metadata;

  std::thread t(md_consumer, std::ref(extract_metadata));

  tap.loop(extract_metadata);

  return EXIT_SUCCESS;
}
















