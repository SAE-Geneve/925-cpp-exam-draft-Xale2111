// Q04 — Données du spawner d'ennemis.
// ----- NE PAS MODIFIER (tout le fichier) -----
#pragma once

#include <string>
#include <utility>
#include <vector>

#include "counters.h"

namespace q04 {

struct Enemy {
  Enemy(std::string name, int hp, int base_score)
      : name_(std::move(name)), hp_(hp), base_score_(base_score) {}

  const std::string& Name() const { return name_; }
  int Hp() const { return hp_; }
  int BaseScore() const { return base_score_; }

 private:
  std::string name_;
  int hp_ = 0;
  int base_score_ = 0;
  // Sonde : les tests comptent les copies d'Enemy via ce membre.
  [[no_unique_address]] exam::LifetimeProbe<Enemy> probe_;
};

// Compteur d'appels — les tests le lisent.
inline int g_get_enemies_calls = 0;

// La vague d'ennemis courante. Retourne PAR VALEUR : chaque appel reconstruit
// la liste complète (c'est un snapshot du spawner, pas un cache).
inline std::vector<Enemy> GetEnemies() {
  ++g_get_enemies_calls;
  std::vector<Enemy> wave;
  wave.reserve(9);
  wave.emplace_back("Goblin", 12, 100);
  wave.emplace_back("Orc", 0, 300);
  wave.emplace_back("Troll", 30, 250);
  wave.emplace_back("Wisp", 5, 40);
  wave.emplace_back("Dragon", 90, 900);
  wave.emplace_back("Skeleton", -3, 60);
  wave.emplace_back("Slime", 8, 20);
  wave.emplace_back("Knight", 44, 150);
  wave.emplace_back("Rat", 2, 5);
  return wave;
}

}  // namespace q04
// ----- fin NE PAS MODIFIER -----
