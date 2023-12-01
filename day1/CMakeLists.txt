project(AdventOfCode_Day1)

configure_file(example.txt ${CMAKE_CURRENT_BINARY_DIR}/example.txt COPYONLY)
configure_file(input.txt ${CMAKE_CURRENT_BINARY_DIR}/input.txt COPYONLY)

add_executable(AdventOfCode_Day1 main_day1.cpp)