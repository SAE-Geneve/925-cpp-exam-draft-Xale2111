// Q08 — Une équipe possède une liste de joueurs (par pointeur).
#pragma once

#include <vector>




namespace q08 {

class Player;

class Team {
 public:
  void Add(Player* player) { members_.push_back(player); }

  // FIXME : a besoin du type Player COMPLET (appel de Score()).
  int TotalScore() const;

 private:
  std::vector<Player*> members_;
};

}  // namespace q08
