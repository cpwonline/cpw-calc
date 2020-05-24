# Setting up libraries
set(WINDOWMAIN_SOURCES
    windowMain.cpp 
    ${HEADER}/windowMain.h
)
set(CALC_SOURCES
    calc.cpp 
    ${HEADER}/calc.h
)

# Setting up dependences
include(FindPkgConfig)
find_package(PkgConfig REQUIRED)
pkg_search_module(GTKMM REQUIRED gtkmm-3.0)
#include_directories(${GTKMM_INCLUDE_DIRS})
#link_directories(${GTKMM_LIBRARY_DIRS})

# Adding libraries and dependencies

#target_link_libraries(${PROJECT_NAME} ${GTKMM_LIBRARIES})

add_library(WINDOWMAIN STATIC ${WINDOWMAIN_SOURCES})
add_library(CALC STATIC ${CALC_SOURCES})
target_link_libraries(WINDOWMAIN ${GTKMM_LIBRARIES})
target_include_directories(WINDOWMAIN PUBLIC ${GTKMM_INCLUDE_DIRS})
target_compile_options(WINDOWMAIN PUBLIC ${GTKMM_CFLAGS_OTHERS})

# Adding a executable
add_executable(${PROJECT_NAME} cpw-calc.cpp)

# Link libraries
target_link_libraries(${PROJECT_NAME} PUBLIC WINDOWMAIN)
target_link_libraries(${PROJECT_NAME} PUBLIC CALC)
