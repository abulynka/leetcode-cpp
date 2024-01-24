cmake_minimum_required(VERSION 3.22.1)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)

add_custom_target(a
        COMMAND make all -j 8
        COMMENT "Building everything from leetcode project"
)

add_custom_target(src
        COMMAND make -j 8
        WORKING_DIRECTORY ./src
        COMMENT "Building leetcode"
)

add_custom_target(test
        COMMAND make -j 8
        WORKING_DIRECTORY ./test
        COMMENT "Building leetcode tests"
)

add_compile_options(-fsanitize=address -Werror)
add_link_options(-fsanitize=address)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)
