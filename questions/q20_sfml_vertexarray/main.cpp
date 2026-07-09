// Q20 — Démo visuelle : rendu d'une grille 64×64.
// Actuellement : un sf::RectangleShape par cellule => 4096 draw calls / frame.
#include <SFML/Graphics.hpp>

#include <optional>

#include "grid.h"
#include "grid_vertices.h"

int main() {
  exam::Grid grid(64, 64);
  for (int y = 0; y < grid.Height(); ++y) {
    for (int x = 0; x < grid.Width(); ++x) {
      if ((x + y) % 7 == 0) grid.Set({x, y}, 1);
      else if ((x * y) % 13 == 0) grid.Set({x, y}, 2);
    }
  }

  sf::RenderWindow window(sf::VideoMode({1024u, 1024u}), "Q20 — Grille");
  window.setFramerateLimit(60);

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) window.close();
    }

    window.clear();
    // REFACTOR-START
    // Un RectangleShape par cellule : 64*64 = 4096 draw calls par frame.

    /*
    for (int y = 0; y < grid.Height(); ++y) {
      for (int x = 0; x < grid.Width(); ++x) {
        sf::RectangleShape cell({q20::kCellSize, q20::kCellSize});
        cell.setPosition({x * q20::kCellSize, y * q20::kCellSize});
        cell.setFillColor(q20::CellColor(grid.At({x, y})));
        window.draw(cell);
      }
      }
    }*/

    window.draw(q20::BuildGridVertices(grid));
    // REFACTOR-END
    window.display();
  }
  return 0;
}
