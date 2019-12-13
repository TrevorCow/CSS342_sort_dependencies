cmake_minimum_required(VERSION 3.10)
project(sort_dependencies)

set(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS  "-DDEBUG")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -DRESERVE_CAPACITY")

# path to static library
Set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

# path to library
Set(CMAKE_LIBRARY_PATH ${CMAKE_SOURCE_DIR}/src)

# path to executable
Set(CMAKE_BINARY_DIR  ${CMAKE_SOURCE_DIR}/bin)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# we use this to get code coverage
if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

# set up google test
include(googletest/googletest.cmake)
fetch_googletest(
        ${PROJECT_SOURCE_DIR}/googletest
        ${LIBRARY_OUTPUT_PATH}/googletest
)
enable_testing()

add_subdirectory(src)
add_subdirectory(test)
