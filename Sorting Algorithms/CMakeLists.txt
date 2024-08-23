cmake_minimum_required(VERSION 3.10)

project(Arquivos)

set(CMAKE_CXX_STANDARD 17)

add_executable(exporta exporta.cpp)

add_library(sort sort.cpp sort.h)

add_executable(ordena ordena.cpp)
target_link_libraries(ordena sort)




