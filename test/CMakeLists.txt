include(FetchContent)
FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
add_executable(avx2_matmul_test avx2_matmul_test.cpp)
target_link_libraries(avx2_matmul_test
    avx2_matmul
    GTest::gtest_main
    GTest::gmock
)
gtest_discover_tests(avx2_matmul_test)
