// Q20 — Rendu d'une grille colorée. La construction de la géométrie est
// isolée dans une fonction pure, testable sans fenêtre ni contexte GL.
#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/VertexArray.hpp>

#include "grid.h"

namespace q20 {

// Taille d'une cellule en pixels (pour le placement des sommets).
inline constexpr float kCellSize = 16.0f;

// Couleur d'une cellule selon sa valeur de tuile (0 = sol, autres = murs/types).
sf::Color CellColor(std::uint8_t tile_value);

// Construit la géométrie de la grille sous forme de triangles.
// NE PAS MODIFIER la signature : les tests l'appellent directement, sans fenêtre.
// 6 sommets par cellule (2 triangles), positions en pixels (cellule * kCellSize).
sf::VertexArray BuildGridVertices(const exam::Grid& grid);

}  // namespace q20
