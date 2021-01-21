# Basic
cmake_minimum_required(VERSION 3.10)
project("cpw-calc" VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Build type
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Compiler options
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Main executable and config file
add_executable(${PROJECT_NAME} "src/cpw-calc.cpp")
configure_file(Config.h.in Config.h)

# Use PkgConfig
include(FindPkgConfig)
find_package(PkgConfig REQUIRED)
pkg_search_module(GTKMM REQUIRED gtkmm-3.0)

# Add and linking libraries
## Library
add_library(Calc SHARED "src/calc.cpp")
target_include_directories(Calc PUBLIC include)
## Library
add_library(WindowMain SHARED "src/windowMain.cpp")
target_include_directories(WindowMain PUBLIC include ${GTKMM_INCLUDE_DIRS})
target_link_libraries(WindowMain ${GTKMM_LIBRARIES})

# Add and linking libraries for Executable
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PUBLIC Calc WindowMain)

# Install rules
install(TARGETS Calc DESTINATION lib)
install(TARGETS WindowMain DESTINATION lib)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "include/windowMain.h" DESTINATION include)
install(FILES "include/calc.h" DESTINATION include)
install(FILES "${PROJECT_BINARY_DIR}/Config.h" DESTINATION include)

# Set up prefix
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	set(CMAKE_INSTALL_PREFIX "/usr/local" CACHE PATH "..." FORCE)
endif()

# Tests
#enable_testing()
#add_executable(test_main "tests/test_main.cc")
#add_test(nombre_del_test test_main)