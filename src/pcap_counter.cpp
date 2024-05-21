#include "packet.hpp"
#include "pcap.hpp"
#include <iostream>
#include <pcap/pcap.h>
#include <string>
#include <thread>

// Funtore
struct func_elabora {
  std::atomic<int> _cnt = 0;

  void operator()(const struct pcap_pkthdr *h, const u_char *bytes) {
    _cnt++;
    npl::packet<hdr::ether> pkt(bytes, h->caplen);
    // pkt.display();
    // std::cout << std::endl;
  }
};

void print_counter(const func_elabora& fun)
{
  for(;;)
  {
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout<< "Counter value: "<<fun._cnt<<std::endl;
  }
}

int main(int argc, char *argv[]) {

  if (argc < 3) {
    std::cout << "Usage: " << argv[0] << " -i <iface> "
              << " r <rule>" << std::endl;
    return EXIT_FAILURE;
  }

  std::string flag(argv[1]);
  std::string dev(argv[2]);

  func_elabora elab;

  if (flag != "-i") {
    return EXIT_FAILURE;
  } else {

    npl::pcap::reader<live> tap(dev);
    tap.open();
    if (argc == 4) {
      tap.filter(argv[3]);
      tap.print_bpf_program();
    }

    std::thread t(print_counter, std::ref(elab));
    t.detach();

    tap.loop(elab);
  }
  //std::cout << "Number of processed packets: " << elab._cnt << std::endl;
}