cmake_minimum_required(VERSION 3.0.0)
project(npl VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD_REQUIRED 20)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

include_directories(lib/libnpl)
include_directories(lib/nlohmann)
include_directories(lib/libchat)
include_directories(esami/18-07-22)

add_executable(main src/main.cpp)
add_executable(conc src/conc.cpp)
add_executable(endianless src/endianless.cpp)
add_executable(udp_srv src/udp_srv.cpp)
add_executable(udp_clt src/udp_clt.cpp)
add_executable(tcp_srv_naive src/tcp_srv_naive.cpp)
add_executable(tcp_srv_fork src/tcp_srv_fork.cpp)
add_executable(tcp_srv_multhread src/tcp_srv_multhread.cpp)
add_executable(tcp_clt src/tcp_clt.cpp)
add_executable(broadcast_udp src/broadcast_udp.cpp)
add_executable(broadcast_usr src/broadcast_usr.cpp)
add_executable(unix_srv src/unix_srv.cpp)
add_executable(unix_clt src/unix_clt.cpp)
add_executable(l3_sniff src/l3_sniff.cpp)
add_executable(l2_sniff src/l2_sniff.cpp)
add_executable(l2_mt_sniff src/l2_mt_sniff.cpp)

add_executable(cPcap_sniff src/cPcap_sniff.cpp)
target_link_libraries(cPcap_sniff pcap)

add_executable(pcap_sniff src/pcap_sniff.cpp)
target_link_libraries(pcap_sniff pcap)

add_executable(pcap_counter src/pcap_counter.cpp)
target_link_libraries(pcap_counter pcap)
target_link_libraries(pcap_counter -pthread)

add_executable(ip_counter src/ip_counter.cpp)
target_link_libraries(ip_counter pcap)
target_link_libraries(ip_counter -pthread)

add_executable(connection_counter src/connection_counter.cpp)
target_link_libraries(connection_counter pcap)
target_link_libraries(connection_counter -pthread)

add_executable(bloom_filter src/bloom_filter.cpp)

add_executable(srv chatroom/srv.cpp)
add_executable(clt chatroom/clt.cpp)

add_executable(probes esami/27-06-22/probes.cpp)
target_link_libraries(probes pcap)
add_executable(collector esami/27-06-22/collector.cpp)

add_executable(fortune_clt esami/18-07-22/fortune_clt.cpp)
add_executable(fortune_srv esami/18-07-22/fortune_srv.cpp)


include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
