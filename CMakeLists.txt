# cmake min version
cmake_minimum_required(VERSION 2.8)
# project/binary name
project(vrp_solver)

# set cmake standard, turn off non-standard extensions
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)

# set compiler flags for debug/release
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
    set(CMAKE_CXX_FLAGS_DEBUG
        "${CMAKE_CXX_FLAGS} -Wall -Werror -g -O0")
    set(CMAKE_CXX_FLAGS_RELEASE
        "${CMAKE_CXX_FLAGS} -Wall -Werror -O3")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS_DEBUG
        "${CMAKE_CXX_FLAGS} -Wall -Werror -g -O0")
    set(CMAKE_CXX_FLAGS_RELEASE
        "${CMAKE_CXX_FLAGS} -Wall -Werror -O3")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS_DEBUG
        "${CMAKE_CXX_FLAGS} /Wall /WX /O0")
    set(CMAKE_CXX_FLAGS_RELEASE
        "${CMAKE_CXX_FLAGS} /Wall /WX /O3")
endif()

# add directory with library
add_subdirectory(lib)

# create binary executable
add_executable(${PROJECT_NAME} main.cpp)

# link libraries to binary
target_link_libraries(${PROJECT_NAME} vrp)
