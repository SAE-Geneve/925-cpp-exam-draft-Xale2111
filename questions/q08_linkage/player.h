// Q08 — Un joueur appartient à une équipe (par pointeur).
#pragma once

#include <string>
#include <optional>


namespace q08 {

class Team;

class Player {
 public:
  Player(std::string name, int score) : name_(std::move(name)), score_(score) {}

  int Score() const { return score_; }
  const std::string& Name() const { return name_; }
  void SetTeam(Team* team) { team_ = team; }

  // FIXME : a besoin du type Team COMPLET (appel de TotalScore()).
  int TeammatesScore() const;

 private:
  std::string name_;
  int score_;
  Team* team_ = nullptr;
};

}  // namespace q08
