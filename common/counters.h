// LECTURE SEULE — ne pas modifier (voir README).
// Instrumentation utilisée par les tests : compteurs d'allocations dynamiques
// et compteurs de cycle de vie (copies / moves / destructions).
#pragma once

#include <atomic>
#include <cstddef>

namespace exam {

// Compteurs d'allocations globales. operator new/delete sont remplacés dans
// counters.cpp : toute cible qui référence AllocCounter (via exam_common)
// compte ses allocations. Mesurer un delta autour de la section observée :
//   const auto before = AllocCounter::allocations.load();
//   ... code mesuré ...
//   const auto delta = AllocCounter::allocations.load() - before;
struct AllocCounter {
  static std::atomic<std::size_t> allocations;
  static std::atomic<std::size_t> deallocations;
  static std::atomic<std::size_t> bytes_allocated;
  static void Reset();
};

// Compteurs de cycle de vie d'un type instrumenté.
struct LifetimeCounts {
  int default_ctor = 0;
  int copy_ctor = 0;
  int move_ctor = 0;
  int copy_assign = 0;
  int move_assign = 0;
  int dtor = 0;

  [[nodiscard]] int Copies() const { return copy_ctor + copy_assign; }
  [[nodiscard]] int Moves() const { return move_ctor + move_assign; }
  [[nodiscard]] int Alive() const { return default_ctor + copy_ctor + move_ctor - dtor; }
  void Reset() { *this = {}; }
};

// Sonde de cycle de vie : à utiliser comme membre ou base d'un type de test.
// Le paramètre Tag isole les compteurs de chaque scénario de test.
template <typename Tag>
struct LifetimeProbe {
  static inline LifetimeCounts counts{};

  LifetimeProbe() { ++counts.default_ctor; }
  LifetimeProbe(const LifetimeProbe&) { ++counts.copy_ctor; }
  LifetimeProbe(LifetimeProbe&&) noexcept { ++counts.move_ctor; }
  LifetimeProbe& operator=(const LifetimeProbe&) {
    ++counts.copy_assign;
    return *this;
  }
  LifetimeProbe& operator=(LifetimeProbe&&) noexcept {
    ++counts.move_assign;
    return *this;
  }
  ~LifetimeProbe() { ++counts.dtor; }
};

}  // namespace exam
