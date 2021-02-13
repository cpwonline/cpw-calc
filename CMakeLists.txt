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
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Set up prefix
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	set(CMAKE_INSTALL_PREFIX "/usr/local" CACHE PATH "..." FORCE)
endif()

# Main executable and config file
add_executable(${PROJECT_NAME} "src/cpw-calc.cpp")
configure_file("cpw-calcConfig.h.in" "cpw-calcConfig.h")

# Use PkgConfig
include(FindPkgConfig)
find_package(PkgConfig REQUIRED)
pkg_search_module(GTKMM REQUIRED gtkmm-3.0)

# Inclusions directories
include_directories(
	${PROJECT_BINARY_DIR}
	"${PROJECT_SOURCE_DIR}/include"
)

# Add and linking libraries
## Library
add_library(Calc SHARED "src/calc.cpp")
## Library
add_library(WindowMain SHARED "src/windowMain.cpp")
target_include_directories(WindowMain PUBLIC ${GTKMM_INCLUDE_DIRS})
target_link_libraries(WindowMain ${GTKMM_LIBRARIES})

# Add and linking libraries for Executable
target_link_libraries(${PROJECT_NAME} PUBLIC Calc WindowMain)

# Install rules
install(TARGETS Calc DESTINATION CMAKE_INSTALL_LIBDIR)
install(TARGETS WindowMain DESTINATION CMAKE_INSTALL_LIBDIR)
install(TARGETS ${PROJECT_NAME} DESTINATION CMAKE_INSTALL_BINDIR)
install(FILES "${PROJECT_SOURCE_DIR}/include/windowMain.h" DESTINATION CMAKE_INSTALL_INCLUDEDIR)
install(FILES "${PROJECT_SOURCE_DIR}/include/calc.h" DESTINATION CMAKE_INSTALL_INCLUDEDIR)
install(FILES "${PROJECT_BINARY_DIR}/Config.h" DESTINATION CMAKE_INSTALL_INCLUDEDIR)
install(FILES "${PROJECT_SOURCE_DIR}/share/cpw-calc_128x128.png" DESTINATION CMAKE_INSTALL_DATADIR)

# Tests
#enable_testing()
#add_executable(test_main "tests/test_main.cc")
#add_test(nombre_del_test test_main)

# Other options
file(
	COPY "${CMAKE_CURRENT_SOURCE_DIR}/share/cpw-calc_128x128.png"
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)