// Q20 — Construction de la géométrie de la grille.
#include "grid_vertices.h"

namespace q20 {

sf::Color CellColor(std::uint8_t tile_value) {
  switch (tile_value) {
    case 0:
      return sf::Color(40, 40, 40);  // sol
    case 1:
      return sf::Color(200, 120, 60);  // mur
    default:
      return sf::Color(60, 160, 200);  // autre type de tuile
  }
}

// FIXME : à implémenter dans le cadre du refactor (voir main.cpp, où le rendu
// se fait actuellement avec un sf::RectangleShape par cellule). Cette fonction
// doit produire la géométrie complète en un seul VertexArray de triangles.
sf::VertexArray BuildGridVertices(const exam::Grid& /*grid*/) {
  return sf::VertexArray(sf::PrimitiveType::Triangles);  // vide pour l'instant
}

}  // namespace q20
