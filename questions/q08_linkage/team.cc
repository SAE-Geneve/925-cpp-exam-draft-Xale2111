// Q08 — Implémentation de Team.
// (Pour l'instant, tout est défini inline dans team.h — d'où le cycle.)
#include "team.h"
#include "player.h"  // FIXME : dépendance circulaire (player.h inclut team.h).
int q08::Team::TotalScore() const {
  int sum = 0;
  for (const Player* player : members_) sum += player->Score();
  return sum;
}
