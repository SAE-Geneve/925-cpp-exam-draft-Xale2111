// Q02 — Vecteur 2D générique du moteur (positions monde en float,
// coordonnées de tuiles en int).
#pragma once

#include <cmath>

namespace q02 {

template <typename T>
struct Vec2 {
  T x{};
  T y{};

  // TODO 1a : pour les T ENTIERS, Length doit retourner un flottant correct
  // (pas une longueur tronquée). Pour les T flottants, le comportement actuel
  // est le bon. (if constexpr, spécialisation, ou surcharge contrainte — au
  // choix, à justifier dans answers/q02.md.)
  float Length() const {
    return static_cast<float>(std::sqrt(static_cast<float>(x * x + y * y)));
  }

  // TODO 1b : normaliser un vecteur entier n'a pas de sens — cet appel ne doit
  // PAS COMPILER pour un Vec2<int> (contrainte ou static_assert au choix),
  // avec un message compréhensible.
  Vec2 Normalized() const {
    static_assert(std::is_floating_point_v<T>, "Vec2<int> n'est pas normalisable.");
    const T len = Length();
    return {x / len, y / len};
  }


  bool operator==(const Vec2& /*other*/) const {
    return true;  // TODO : stub visiblement faux
  }
};

}  // namespace q02
