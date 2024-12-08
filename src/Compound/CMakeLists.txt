add_library(Compound STATIC metal.cpp)

target_include_directories(Compound PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(Compound Atom)