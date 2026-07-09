// LECTURE SEULE — ne pas modifier (voir README).
#pragma once

#include <cassert>
#include <cstdint>
#include <string_view>
#include <vector>

#include "tile_pos.h"

namespace exam {

// Grille 2D simple : 0 = case libre, toute autre valeur = mur / type de tuile.
class Grid {
 public:
  Grid() = default;
  Grid(int width, int height, std::uint8_t fill = 0)
      : width_(width), height_(height), cells_(static_cast<std::size_t>(width) * height, fill) {}

  [[nodiscard]] int Width() const { return width_; }
  [[nodiscard]] int Height() const { return height_; }

  [[nodiscard]] bool InBounds(TilePos p) const {
    return p.x >= 0 && p.x < width_ && p.y >= 0 && p.y < height_;
  }

  [[nodiscard]] std::uint8_t At(TilePos p) const {
    assert(InBounds(p));
    return cells_[Index(p)];
  }

  void Set(TilePos p, std::uint8_t value) {
    assert(InBounds(p));
    cells_[Index(p)] = value;
  }

  [[nodiscard]] bool IsWalkable(TilePos p) const { return InBounds(p) && At(p) == 0; }

  // Construit une grille depuis un dessin ASCII : '.' = libre, '#' = mur,
  // les chiffres '0'..'9' = valeur de tuile. Lignes séparées par '\n'.
  [[nodiscard]] static Grid FromString(std::string_view rows) {
    std::vector<std::string_view> lines;
    while (!rows.empty()) {
      const auto nl = rows.find('\n');
      const auto line = rows.substr(0, nl);
      if (!line.empty()) lines.push_back(line);
      if (nl == std::string_view::npos) break;
      rows.remove_prefix(nl + 1);
    }
    if (lines.empty()) return {};
    Grid grid(static_cast<int>(lines[0].size()), static_cast<int>(lines.size()));
    for (int y = 0; y < grid.Height(); ++y) {
      assert(static_cast<int>(lines[y].size()) == grid.Width());
      for (int x = 0; x < grid.Width(); ++x) {
        const char c = lines[y][x];
        std::uint8_t value = 0;
        if (c == '#') value = 1;
        if (c >= '0' && c <= '9') value = static_cast<std::uint8_t>(c - '0');
        grid.Set({x, y}, value);
      }
    }
    return grid;
  }

 private:
  [[nodiscard]] std::size_t Index(TilePos p) const {
    return static_cast<std::size_t>(p.y) * width_ + p.x;
  }

  int width_ = 0;
  int height_ = 0;
  std::vector<std::uint8_t> cells_;
};

}  // namespace exam
