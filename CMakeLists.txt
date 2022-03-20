cmake_minimum_required(VERSION 3.16)

project(ObserverModel)
option(RUN_TESTS "Run tests as part of the build process." ON)
set(INSTALL_GTEST OFF)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# globlely add include directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_subdirectory(third)

set(CMAKE_VERBOSE_MAKEFILE OFF)

set(CMAKE_INSTALL_PREFIX /home/jimery/.local)
# set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib:$ORIGIN/../lib64")
set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)
# set_target_properties(myexe PROPERTIES INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

add_subdirectory(src)

if(RUN_TESTS)
    include(UnitTest)
    enable_testing()
    add_subdirectory(test)
endif()

