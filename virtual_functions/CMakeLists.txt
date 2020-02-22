cmake_minimum_required(VERSION 3.12)
project(virtual_functions)

set(CMAKE_CXX_STANDARD 14)

add_executable(virtual_functions main.cpp Subscriber.h Contract.h Prepayment.h)