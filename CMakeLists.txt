cmake_minimum_required(VERSION 3.29)
project(Taller1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Taller1 main.cpp
        MaterialBiblioagrafico.cpp
        MaterialBiblioagrafico.h
        Libro.cpp
        Libro.h
        Revista.cpp
        Revista.h
        Usuario.cpp
        Usuario.h
        Sistema.cpp
        Sistema.h)
