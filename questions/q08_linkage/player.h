// Q08 — Un joueur appartient à une équipe (par pointeur).
#pragma once

#include <string>

#include "team.h"  // FIXME : dépendance circulaire (team.h inclut player.h).

namespace q08 {

class Player {
 public:
  Player(std::string name, int score) : name_(std::move(name)), score_(score) {}

  int Score() const { return score_; }
  const std::string& Name() const { return name_; }
  void SetTeam(Team* team) { team_ = team; }

  // FIXME : a besoin du type Team COMPLET (appel de TotalScore()).
  int TeammatesScore() const { return team_->TotalScore() - score_; }

 private:
  std::string name_;
  int score_;
  Team* team_ = nullptr;
};

}  // namespace q08
