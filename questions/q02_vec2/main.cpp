// Q02 — Démo : longueurs et normalisation, monde (float) et grille (int).
#include <print>

#include "vec2.h"

int main() {
  const q02::Vec2<float> velocity{3.0f, 4.0f};
  std::println("Vitesse : longueur = {} (attendu 5)", velocity.Length());
  const auto dir = velocity.Normalized();
  std::println("Direction normalisée : ({}, {}) (attendu (0.6, 0.8))", dir.x, dir.y);

  const q02::Vec2<int> tile_offset{1, 1};
  std::println("Décalage de tuile (1,1) : longueur = {} (attendu ~1.414...)",
               tile_offset.Length());
  return 0;
}
