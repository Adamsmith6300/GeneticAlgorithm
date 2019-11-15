cmake_minimum_required(VERSION 3.15)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(GeneticAlgorithm main.cpp City.cpp City.hpp Tour.cpp Tour.hpp main.hpp Population.cpp Population.hpp)