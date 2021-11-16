cmake_minimum_required(VERSION 3.0.0)
project(markow_chains VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(markow_chains 
                src/main.cpp
                lib/markow_chains.cpp
                lib/markow_chains.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
