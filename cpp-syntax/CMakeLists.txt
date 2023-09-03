# local env cmake version
cmake_minimum_required(VERSION 3.26)

# project to learn cpp syntax, even usage of STL
project(cpp-syntax LANGUAGES CXX)

# specify c++ version as c++17
set(CMAKE_CXX_STANDARD 17)

# enable -Wall, -Wextra and -Werror
add_compile_options(-Wall -Wextra -Werror)

# add the executable​s
add_executable(tuple
    tuple.cpp
)

add_executable(map
    map.cpp
)
