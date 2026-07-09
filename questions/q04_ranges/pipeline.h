// Q04 — Calcul des scores affichés dans le HUD : les 5 premiers ennemis
// vivants de la vague, avec leur score transformé (base * 2 + hp).
#pragma once

#include <vector>

#include "enemies.h"

namespace q04 {

// REFACTOR-START
// Cible : un pipeline std::ranges (views::filter | views::transform |
// views::take, matérialisé avec std::ranges::to). La signature est conservée.
inline std::vector<int> TopScores() {
  // Snapshot complet de la vague...
  std::vector<Enemy> all = GetEnemies();

  // ... copie des vivants dans un vecteur intermédiaire...
  std::vector<Enemy> alive;
  for (const Enemy& enemy : all) {
    if (enemy.Hp() > 0) {
      alive.push_back(enemy);
    }
  }

  // ... puis calcul des scores dans un troisième vecteur.
  std::vector<int> scores;
  for (const Enemy& enemy : alive) {
    scores.push_back(enemy.BaseScore() * 2 + enemy.Hp());
  }
  if (scores.size() > 5) {
    scores.resize(5);
  }
  return scores;
}
// REFACTOR-END

}  // namespace q04
