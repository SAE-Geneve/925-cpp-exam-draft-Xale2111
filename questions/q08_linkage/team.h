// Q08 — Une équipe possède une liste de joueurs (par pointeur).
#pragma once

#include <vector>

#include "player.h"  // FIXME : dépendance circulaire (player.h inclut team.h).

namespace q08 {

class Team {
 public:
  void Add(Player* player) { members_.push_back(player); }

  // FIXME : a besoin du type Player COMPLET (appel de Score()).
  int TotalScore() const {
    int sum = 0;
    for (const Player* player : members_) sum += player->Score();
    return sum;
  }

 private:
  std::vector<Player*> members_;
};

}  // namespace q08
