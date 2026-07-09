// LECTURE SEULE — ne pas modifier (voir README).
#pragma once

namespace exam {

// Position entière sur une grille de tuiles.
// NOTE : volontairement minimale. Si une question nécessite l'égalité ou le
// hachage de TilePos, c'est à la question de les fournir (dans SON dossier).
struct TilePos {
  int x = 0;
  int y = 0;
};

}  // namespace exam
