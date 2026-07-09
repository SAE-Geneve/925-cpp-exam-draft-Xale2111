// Q08 — Démo : une équipe et ses joueurs qui se référencent mutuellement.
#include <print>

#include "player.h"
#include "team.h"

int main() {
  q08::Player alice("Alice", 10);
  q08::Player bob("Bob", 20);

  q08::Team team;
  team.Add(&alice);
  team.Add(&bob);
  alice.SetTeam(&team);
  bob.SetTeam(&team);

  std::println("Score de l'équipe : {} (attendu 30)", team.TotalScore());
  std::println("Score des coéquipiers d'Alice : {} (attendu 20)", alice.TeammatesScore());
  return 0;
}
