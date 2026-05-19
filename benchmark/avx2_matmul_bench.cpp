#include <cstddef>
#include <vector>

#include <benchmark/benchmark.h>

#include "avx2_matmul.h"

constexpr size_t K = 2048;

static void bench(benchmark::State &state) {
  std::vector<float> A(6 * K, 3.2);
  std::vector<float> B(K * 16, 0.2);
  std::vector<float> C(6 * 16, 0);

  for (auto _ : state) {
    rank_k_reduce_6x16(nullptr, K, A.data(), B.data(), C.data());
  }
}

static void bench_scheduled(benchmark::State &state) {
  std::vector<float> A(6 * K, 3.2);
  std::vector<float> B(K * 16, 0.2);
  std::vector<float> C(6 * 16, 0);

  for (auto _ : state) {
    rank_k_reduce_6x16_scheduled(nullptr, K, A.data(), B.data(), C.data());
  }
}

BENCHMARK(bench);
BENCHMARK(bench_scheduled);

BENCHMARK_MAIN();
