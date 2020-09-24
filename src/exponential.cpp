#include <benchmark/benchmark.h>
#include <stan/math.hpp>
#include <utility>
#include "toss_me.hpp"
#include "callback_bench_impl.hpp"

auto init = [](benchmark::State& state) {
  using stan::math::var;
  using stan::math::exp;
  using stan::math::promote_scalar;

  Eigen::VectorXd y_val = exp(Eigen::VectorXd::Random(state.range(0)));
  Eigen::VectorXd beta_val = exp(Eigen::VectorXd::Random(state.range(0)));

  return std::make_tuple(CAST_VAR(y_val),
			 CAST_VAR(beta_val));
};

auto init_data = [](benchmark::State& state) {
  using stan::math::var;
  using stan::math::exp;
  using stan::math::promote_scalar;

  Eigen::VectorXd y_val = exp(Eigen::VectorXd::Random(state.range(0)));
  Eigen::VectorXd beta_val = exp(Eigen::VectorXd::Random(state.range(0)));

  return std::make_tuple(y_val,
			 CAST_VAR(beta_val));
};

static void exponential_lpdf(benchmark::State& state) {
  auto run = [](const auto&... args) {
    return exponential_lpdf(args...);
  };

  callback_bench_impl(init, run, state);
}

static void exponential_cdf(benchmark::State& state) {
  auto run = [](const auto&... args) {
    return exponential_cdf(args...);
  };

  callback_bench_impl(init, run, state);
}

static void exponential_lcdf(benchmark::State& state) {
  auto run = [](const auto&... args) {
    return exponential_lcdf(args...);
  };

  callback_bench_impl(init, run, state);
}

static void exponential_lccdf(benchmark::State& state) {
  auto run = [](const auto&... args) {
    return exponential_lccdf(args...);
  };

  callback_bench_impl(init, run, state);
}

static void exponential_lpdf_data(benchmark::State& state) {
  auto run = [](const auto&... args) {
    return exponential_lpdf(args...);
  };

  callback_bench_impl(init_data, run, state);
}

static void exponential_cdf_data(benchmark::State& state) {
  auto run = [](const auto&... args) {
    return exponential_cdf(args...);
  };

  callback_bench_impl(init_data, run, state);
}

static void exponential_lcdf_data(benchmark::State& state) {
  auto run = [](const auto&... args) {
    return exponential_lcdf(args...);
  };

  callback_bench_impl(init_data, run, state);
}

static void exponential_lccdf_data(benchmark::State& state) {
  auto run = [](const auto&... args) {
    return exponential_lccdf(args...);
  };

  callback_bench_impl(init_data, run, state);
}

// The start and ending sizes for the benchmark
int start_val = 2;
int end_val = 1024;
BENCHMARK(toss_me);
BENCHMARK(exponential_lpdf)->RangeMultiplier(2)->Range(start_val, end_val)->UseManualTime();
BENCHMARK(exponential_cdf)->RangeMultiplier(2)->Range(start_val, end_val)->UseManualTime();
BENCHMARK(exponential_lcdf)->RangeMultiplier(2)->Range(start_val, end_val)->UseManualTime();
BENCHMARK(exponential_lccdf)->RangeMultiplier(2)->Range(start_val, end_val)->UseManualTime();
BENCHMARK(exponential_lpdf_data)->RangeMultiplier(2)->Range(start_val, end_val)->UseManualTime();
BENCHMARK(exponential_cdf_data)->RangeMultiplier(2)->Range(start_val, end_val)->UseManualTime();
BENCHMARK(exponential_lcdf_data)->RangeMultiplier(2)->Range(start_val, end_val)->UseManualTime();
BENCHMARK(exponential_lccdf_data)->RangeMultiplier(2)->Range(start_val, end_val)->UseManualTime();
BENCHMARK_MAIN();
