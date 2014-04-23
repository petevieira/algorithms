cmake_minimum_required(VERSION 2.6)

project(algorithms)

#-----------------------------------------------
#                COMPILE SETTINGS
#-----------------------------------------------
set(CMAKE_BUILD_TYPE "Debug")
list(APPEND CMAKE_CXX_FLAGS "-std=c++0x -Wall")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

include_directories(include)

#-----------------------------------------------
#                BUILD TESTS
#-----------------------------------------------
# Get test files
file(GLOB algs "src/*.cc")
LIST(SORT algs)

# Build test programs
message(STATUS "\n-- UNIT TEST: ")
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
foreach(utest_src_file ${algs})
    get_filename_component(test_base ${utest_src_file} NAME_WE)
    message(STATUS "Adding test ${test_base}")
    add_executable(${test_base} ${utest_src_file})
    target_link_libraries(${test_base})
    add_test(${test_base} ${EXECUTABLE_OUTPUT_PATH}/${test_base})
    add_custom_target(${test_base}.run ${test_base} ${ARGN})
    add_dependencies(check ${test_base})
endforeach(utest_src_file)
