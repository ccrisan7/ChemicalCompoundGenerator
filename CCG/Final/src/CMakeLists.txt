add_library(src STATIC main.cpp)

add_subdirectory(Atom)
add_subdirectory(Compound)

target_link_libraries(src PRIVATE Atom Compound)
target_link_libraries(src PRIVATE pthread)