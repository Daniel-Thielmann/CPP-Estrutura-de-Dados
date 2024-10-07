cmake_minimum_required(VERSION 3.10)

project(Arquivos)

set(CMAKE_CXX_STANDARD 17)

add_executable(exporta exporta.cpp
        Menu.cpp
        ArvoreVP.cpp
        compress.cpp
        Hash.cpp)
add_library(movie Movie.cpp Movie.h
        ArvoreVP.cpp
        compress.cpp
        Hash.cpp)
add_library(sort sort.cpp sort.h
        ArvoreVP.cpp
        compress.cpp
        Hash.cpp)
target_link_libraries(exporta movie)
target_link_libraries(exporta sort)





