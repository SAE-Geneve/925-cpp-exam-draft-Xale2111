// Q08 — Implémentation de Player.
// (Pour l'instant, tout est défini inline dans player.h — d'où le cycle.)
#include "player.h"
#include "team.h"  // FIXME : dépendance circulaire (team.h inclut player.h).
int q08::Player::TeammatesScore() const {
  return team_->TotalScore() - score_;
}
