cmake_minimum_required(VERSION 3.21)
project(Akel_SemPrace C)

set(CMAKE_C_STANDARD 99)

add_executable(Akel_SemPrace main.c Headers/enums.h Headers/kandidat.h Headers/pozice.h Headers/pohovor.h Headers/agenda.h Source/agenda.c Source/pozice.c Source/pohovor.c Source/kandidat.c)
