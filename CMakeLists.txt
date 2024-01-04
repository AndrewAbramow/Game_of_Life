cmake_minimum_required(VERSION 3.20)

project(life_sim CXX)

add_executable(life_sim game.cpp main.cpp)

add_compile_options(life_sim PUBLIC cxx_std_20)