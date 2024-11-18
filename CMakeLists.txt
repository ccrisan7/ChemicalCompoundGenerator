cmake_minimum_required(VERSION 3.0)

set(myproject "atom")

# Project name
project(${myproject})

# Specify the required C++ standard
if(CMAKE_VERSION GREATER "3.1.2") 
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
else()
    if(CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
    endif()    
endif()

add_executable(${myproject} src/main.cpp)

add_subdirectory(src)

target_link_libraries(${myproject} src)

target_include_directories(${myproject} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Atom"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Compound")

configure_file(src/Data/atomic_data.txt ${CMAKE_BINARY_DIR}/atomic_data.txt COPYONLY)
