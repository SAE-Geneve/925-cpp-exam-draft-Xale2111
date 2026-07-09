// Q02 — Ce fichier NE DOIT PAS compiler une fois la question résolue :
// Normalized() est interdit sur un Vec2 entier.
#include "q02_vec2/vec2.h"

void MustNotCompile() {
  const q02::Vec2<int> tile{3, 4};
  (void)tile.Normalized();
}
