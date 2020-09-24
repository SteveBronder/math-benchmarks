#include <benchmark/benchmark.h>
#include <stan/math.hpp>
#include <utility>
#include "toss_me.hpp"
#include "callback_bench_impl.hpp"

static void matrix_power(benchmark::State& state) {
  using stan::math::var;
  using stan::math::promote_scalar;
  
  auto init = [](benchmark::State& state) {
    Eigen::MatrixXd x_val = Eigen::MatrixXd::Random(state.range(0), state.range(0));

    return std::make_tuple(CAST_VAR(x_val), 3);
  };

  auto run = [](const auto&... args) {
    return sum(matrix_power(args...));
  };

  callback_bench_impl(init, run, state);
}

// The start and ending sizes for the benchmark
int start_val = 2;
int end_val = 256;
BENCHMARK(toss_me);
BENCHMARK(matrix_power)->RangeMultiplier(2)->Range(start_val, end_val)->UseManualTime();
BENCHMARK_MAIN();
