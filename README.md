# C++ Study Project

A series of weekly C++ exercises focused on systems programming and performance.

Written in C++20, compiled with GCC.

## Topics

| Week | Topic |
|------|-------|
| week1-0709 | Algorithms: two pointers, trees |
| week2-1509 | Memory layout (AoS vs SoA), SIMD intrinsics, mutex with exchange |
| week3-2209 | Multithreading: mutex, atomics, seqlock |
| week4-0210 | Lock-free data structures: SPSC bounded queue |

## Build

**Requirements:** GCC 11+, CMake 3.20+

week2 benchmarks require Google Benchmark:
```bash
sudo apt install libbenchmark-dev
```

**Build all:**
```bash
cmake -B build
cmake --build build
```

**Run examples:**
```bash
./build/week1_cs
./build/week1_rs
./build/week1_tree
./build/week2_aos
./build/week2_soa
(...see CMakeLists.txt for the rest of the executable names..)
```
