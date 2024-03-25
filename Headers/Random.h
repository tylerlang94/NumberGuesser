#ifndef RANDOM_MT_H
#define RANDOM_MT_H

#include <chrono>
#include <random>
//
// Generates random number given the range
//
namespace Random {
inline std::mt19937 generate() {
  std::random_device rd{};

  std::seed_seq ss{
      static_cast<std::seed_seq::result_type>(
          std::chrono::steady_clock::now().time_since_epoch().count()),
      rd(),
      rd(),
      rd(),
      rd(),
      rd(),
      rd(),
      rd()};

  return std::mt19937{ss};
}

inline std::mt19937 mt{generate()}; // generates a seeded std::mt19937 and
                                    // copies it into our global object

inline int get(int min, int max) {
  return std::uniform_int_distribution<>{min, max}(mt);
}

template <typename T> T get(T min, T max) {
  return std::uniform_int_distribution<T>{min, max}(mt);
}

template <typename R, typename S, typename T> R get(S min, T max) {
  return get<R>(static_cast<R>(min), static_cast<R>(max));
}
} // namespace Random

#endif
