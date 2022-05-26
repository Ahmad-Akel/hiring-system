cmake_minimum_required(VERSION 3.22)
project(SemPrace_Akel C)

set(CMAKE_C_STANDARD 99)

add_executable(SemPrace_Akel main.c Sources/agenda.c Headers/agenda.h Headers/kandidat.h Sources/kandidat.c Headers/pozice.h Sources/pozice.c Headers/pohovor.h Sources/pohovor.c Headers/enum.h)
