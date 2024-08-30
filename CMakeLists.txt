cmake_minimum_required(VERSION 3.22)
project(dmoj_offline)

set(CMAKE_CXX_STANDARD 17)

set(ProblemList 16bitswonly ecoo13r1p1)

foreach(item IN LISTS ProblemList)
    add_executable(ProblemInput_${item} problem/${item}/input.cpp)
    add_executable(Problem_${item} problem/${item}/main.cpp)
    add_executable(Contest_${item} contest/${item}/main.cpp)
endforeach()

add_executable(Engine engine/main.cpp)


