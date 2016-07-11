cmake_minimum_required (VERSION 2.6)
INCLUDE(CPack)

project (MilightServer)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.55.0 COMPONENTS system thread unit_test_framework REQUIRED)

if(UNIX)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")
endif()


find_package(Doxygen)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

set( CMAKE_LIBRARY_OUTPUT_DIRECTORY, lib)
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)
add_subdirectory(tests)

install(FILES DESTINATION bin)
