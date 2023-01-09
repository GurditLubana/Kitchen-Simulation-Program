cmake_minimum_required(VERSION 3.21)
project(Assignment2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment2 main.cpp Node.h Node.cpp List.cpp List.h Queue.cpp Queue.h stack.cpp stack.h Event.cpp Event.h Arrival.cpp Arrival.h Prepare.cpp Prepare.h CompleteService.cpp CompleteService.h Execution.cpp Execution.h PriorityQueue.cpp PriorityQueue.h)
