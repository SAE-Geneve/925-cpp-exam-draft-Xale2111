// Q06 — Démo : le calcul copie inutilement les objets du catalogue.
#include <print>

#include "catalog.h"
#include "counters.h"

int main() {
  std::vector<q06::Item> catalog;
  catalog.reserve(3);
  catalog.emplace_back("alpha", 100);
  catalog.emplace_back("beta", 20);
  catalog.emplace_back("gamma", 60);

  using Probe = exam::LifetimeProbe<q06::ItemTag>;
  Probe::counts.Reset();
  const int total = q06::TotalAbove(catalog, 50);

  std::println("Total (>= 50) = {} (attendu 160)", total);
  std::println("Copies d'Item pendant le calcul : {} (attendu 0)", Probe::counts.Copies());
  return 0;
}
