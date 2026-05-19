set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)

include(FetchContent)
FetchContent_Declare(benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG v1.9.5
)
FetchContent_MakeAvailable(benchmark)

add_executable(avx2_matmul_bench avx2_matmul_bench.cpp)
target_link_libraries(avx2_matmul_bench
    avx2_matmul
    benchmark::benchmark
)
