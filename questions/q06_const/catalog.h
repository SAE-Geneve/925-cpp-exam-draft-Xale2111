// Q06 — Calcul sur un catalogue d'objets. `Item` est une classe maison
// instrumentée : elle compte ses propres copies. Le calcul en fait trop.
#pragma once

#include <string>
#include <vector>

#include "counters.h"

namespace q06 {

struct ItemTag {};

// Classe maison : un objet possède un nom et une valeur. Elle hérite d'une
// sonde qui compte les copies/déplacements (voir common/counters.h).
struct Item : exam::LifetimeProbe<ItemTag> {
  std::string name;
  int value = 0;
  Item(std::string item_name, int item_value)
      : name(std::move(item_name)), value(item_value) {}
};

// Somme la valeur des objets dont la valeur atteint au moins `threshold`.
// FIXME : `items` est reçu PAR VALEUR (copie tout le conteneur à l'appel), et
// la boucle copie CHAQUE `Item`. Aucune de ces copies n'est nécessaire.
inline int TotalAbove(std::vector<Item> items, int threshold) {
  int total = 0;
  for (Item item : items) {
    if (item.value >= threshold) total += item.value;
  }
  return total;
}

}  // namespace q06
