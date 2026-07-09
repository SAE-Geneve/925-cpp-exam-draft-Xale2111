// Q04 — Démo : scores du HUD et coût réel du calcul.
#include <print>

#include "pipeline.h"

int main() {
  exam::LifetimeProbe<q04::Enemy>::counts.Reset();
  q04::g_get_enemies_calls = 0;

  const auto scores = q04::TopScores();

  std::print("Scores HUD : ");
  for (const int s : scores) std::print("{} ", s);
  std::println("");
  std::println("Appels à GetEnemies() : {} (idéal : 1)", q04::g_get_enemies_calls);
  std::println("Copies d'Enemy : {} (idéal : 0)",
               exam::LifetimeProbe<q04::Enemy>::counts.Copies());
  return 0;
}
