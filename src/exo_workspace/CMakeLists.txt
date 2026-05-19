set(Exo_DIR "${PROJECT_SOURCE_DIR}/exo/src/exo/cmake")

find_package(Exo REQUIRED)

add_exo_library(
    NAME avx2_matmul
    SOURCES avx2_matmul.py
    PYTHONPATH "${CMAKE_CURRENT_SOURCE_DIR}"
)
target_compile_options(avx2_matmul PRIVATE -march=native)
