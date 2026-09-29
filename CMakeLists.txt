cmake_minimum_required(VERSION 3.15)
project(ImageFilters CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# params for compiler

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# NOTE: filters/*.cpp are globbed at configure time
# to add a new filter .cpp, re-run cmake to pick it up before building.
file(GLOB FILTER_SOURCES ${CMAKE_SOURCE_DIR}/src/filters/*.cpp)

set(SOURCES
    src/driver.cpp
    src/writer.cpp
	src/image.cpp
    ${FILTER_SOURCES}
)

add_executable(ImageFilters ${SOURCES})

target_compile_options(ImageFilters PRIVATE
    -Wall
    -Wextra
    -Wconversion
    -Wsign-conversion
    -Wshadow
    -Wpedantic
)

# SYSTEM suppresses warnings from /lib
target_include_directories(ImageFilters SYSTEM PRIVATE 
    ${CMAKE_SOURCE_DIR}/lib      # for 3rd party headers
)


target_include_directories(ImageFilters PRIVATE
    ${CMAKE_SOURCE_DIR}/include      # for dev defined headers
)
