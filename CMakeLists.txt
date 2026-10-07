cmake_minimum_required(VERSION 4.3)
project(risc_uarchitecture)

set(CMAKE_CXX_STANDARD 23)

add_executable(risc_uarchitecture main.cpp
        riscv-emulator/risc.hpp)
