cmake_minimum_required(VERSION 3.20)
project(cpp-exercises)

set(CMAKE_CXX_STANDARD 20)

find_package(benchmark CONFIG REQUIRED)

add_executable(week1_cs week1-0709/convertString.cpp)
add_executable(week1_tree week1-0709/dfs-bfs.cpp)
add_executable(week1_rs week1-0709/replaceSpaces.cpp)

add_executable(week2_aos week2-1509/ask_bid_array_of_struct.cpp)
target_link_libraries(week2_aos PRIVATE benchmark::benchmark)

add_executable(week2_soa week2-1509/ask_bid_struct_of_array.cpp)
target_link_libraries(week2_soa PRIVATE benchmark::benchmark)
target_compile_options(week2_soa PRIVATE -march=native)

add_executable(week2_mutex_atomic_exchange week2-1509/mutex_atomic_exchange.cpp)
add_executable(week2_mutex_compare_exchange week2-1509/mutext_compare_exchange_weak.cpp)

add_executable(week3_rw week3-2209/readers_writer_shared_mutex.cpp)
add_executable(week3_seqlock week3-2209/seqlock.cpp)
add_executable(week3_sm week3-2209/shared_mutex_atomic.cpp)

add_executable(week4_ExchangeLatency week4-0210/ExchangeLatency.cpp)
add_executable(week4_GetSetSetAll week4-0210/GetSetSetAll.cpp)
add_executable(week4_spsc week4-0210/spsc.cpp)
