#include <cstddef>
#include <vector>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "avx2_matmul.h"

constexpr size_t K = 2048;

TEST(Avx2MatmulTest, CorrectnessTest) {
  std::vector<float> A(6 * K, 3.2);
  std::vector<float> B(K * 16, 0.2);
  std::vector<float> C_ref(6 * 16, 0);
  std::vector<float> C_exo(6 * 16, 0);

  rank_k_reduce_6x16(nullptr, K, A.data(), B.data(), C_ref.data());
  rank_k_reduce_6x16_scheduled(nullptr, K, A.data(), B.data(), C_exo.data());

  EXPECT_THAT(C_exo, ::testing::Pointwise(::testing::FloatEq(), C_ref));
}
