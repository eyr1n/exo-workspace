cmake_minimum_required(VERSION 3.22)
project(exo-workspace LANGUAGES C CXX)

add_subdirectory(src/exo_workspace)

enable_testing()
add_subdirectory(test)
add_subdirectory(benchmark)
