// Q04 — Tests : résultat identique, zéro copie d'Enemy, un seul GetEnemies().
#include <gtest/gtest.h>

#include <vector>

#include "q04_ranges/pipeline.h"

namespace {

class Q04 : public ::testing::Test {
 protected:
  void SetUp() override {
    exam::LifetimeProbe<q04::Enemy>::counts.Reset();
    q04::g_get_enemies_calls = 0;
  }
};

}  // namespace

TEST_F(Q04, ScoresMatchReference) {
  // Vivants dans l'ordre de la vague : Goblin(212), Troll(530), Wisp(85),
  // Dragon(1890), Slime(48) — les 5 premiers, score = base * 2 + hp.
  const std::vector<int> expected{212, 530, 85, 1890, 48};
  EXPECT_EQ(q04::TopScores(), expected);
}

TEST_F(Q04, NoEnemyCopies) {
  (void)q04::TopScores();
  EXPECT_EQ(exam::LifetimeProbe<q04::Enemy>::counts.Copies(), 0)
      << "Le pipeline ne doit copier aucun Enemy : filtrez et transformez des "
         "références, matérialisez uniquement les int.";
}

TEST_F(Q04, SingleSnapshotOfTheWave) {
  (void)q04::TopScores();
  EXPECT_EQ(q04::g_get_enemies_calls, 1)
      << "TopScores() doit prendre UN snapshot de la vague, pas plusieurs.";
}
