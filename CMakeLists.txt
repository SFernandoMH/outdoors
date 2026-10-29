cmake_minimum_required(VERSION 3.28)
project(OUTDOORS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ruta a la carpeta extraída, relativa al proyecto
set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML-3.1.0/lib/cmake/SFML")

find_package(SFML 3 REQUIRED COMPONENTS Graphics)

file(GLOB_RECURSE FUENTES src/*.cpp)
add_executable(OUTDOORS ${FUENTES}
        src/Player.cpp
        include/Player.h)
target_include_directories(OUTDOORS PRIVATE include)
target_link_libraries(OUTDOORS PRIVATE SFML::Graphics)