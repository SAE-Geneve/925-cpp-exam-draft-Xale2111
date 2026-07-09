// Q20 — Tests : géométrie de la grille, SANS fenêtre ni contexte GL.
// Cette cible linke SFML (graphics) mais ne crée jamais de RenderWindow.
#include <gtest/gtest.h>

#include <cmath>

#include "grid.h"
#include "q20_sfml_vertexarray/grid_vertices.h"

TEST(Q20, PrimitiveIsTrianglesWithSixVerticesPerCell) {
  const exam::Grid grid(4, 3);
  const sf::VertexArray va = q20::BuildGridVertices(grid);
  EXPECT_EQ(va.getPrimitiveType(), sf::PrimitiveType::Triangles);
  EXPECT_EQ(va.getVertexCount(), 4u * 3u * 6u)
      << "6 sommets (2 triangles) par cellule attendus.";
}

TEST(Q20, TrianglesTileTheWholeGrid) {
  const exam::Grid grid(5, 4);
  const sf::VertexArray va = q20::BuildGridVertices(grid);
  ASSERT_EQ(va.getVertexCount() % 3u, 0u);

  double area = 0;
  for (std::size_t k = 0; k + 2 < va.getVertexCount(); k += 3) {
    const auto a = va[k].position;
    const auto b = va[k + 1].position;
    const auto c = va[k + 2].position;
    area += std::abs((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)) / 2.0;
  }
  const double expected = 5.0 * 4.0 * q20::kCellSize * q20::kCellSize;
  EXPECT_NEAR(area, expected, 1e-2) << "Les triangles ne pavent pas exactement la grille.";
}

TEST(Q20, CellCornersArePresent) {
  const exam::Grid grid(2, 2);
  const sf::VertexArray va = q20::BuildGridVertices(grid);
  const auto has_vertex_at = [&](float x, float y) {
    for (std::size_t k = 0; k < va.getVertexCount(); ++k) {
      if (va[k].position.x == x && va[k].position.y == y) return true;
    }
    return false;
  };
  // Coins de la cellule (1,0) : de (16,0) à (32,16).
  EXPECT_TRUE(has_vertex_at(16.0f, 0.0f));
  EXPECT_TRUE(has_vertex_at(32.0f, 16.0f));
}

TEST(Q20, VertexColorsFollowTileValue) {
  exam::Grid grid(2, 1);
  grid.Set({0, 0}, 0);
  grid.Set({1, 0}, 1);
  const sf::VertexArray va = q20::BuildGridVertices(grid);

  int ground = 0;
  int wall = 0;
  for (std::size_t k = 0; k < va.getVertexCount(); ++k) {
    if (va[k].color == q20::CellColor(0)) ++ground;
    if (va[k].color == q20::CellColor(1)) ++wall;
  }
  EXPECT_EQ(ground, 6) << "6 sommets de la couleur du sol attendus.";
  EXPECT_EQ(wall, 6) << "6 sommets de la couleur du mur attendus.";
}
