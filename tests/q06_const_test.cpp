// Q06 — Tests : le calcul ne copie pas les objets du catalogue.
#include <gtest/gtest.h>

#include <vector>

#include "counters.h"
#include "q06_const/catalog.h"

namespace {

using Probe = exam::LifetimeProbe<q06::ItemTag>;

std::vector<q06::Item> MakeCatalog() {
  std::vector<q06::Item> catalog;
  catalog.reserve(4);
  catalog.emplace_back("alpha", 100);
  catalog.emplace_back("beta", 20);
  catalog.emplace_back("gamma", 60);
  catalog.emplace_back("delta", 45);
  return catalog;
}

}  // namespace

TEST(Q06, TotalAboveIsCorrect) {
  const auto catalog = MakeCatalog();
  EXPECT_EQ(q06::TotalAbove(catalog, 50), 160);   // 100 + 60
  EXPECT_EQ(q06::TotalAbove(catalog, 0), 225);    // 100 + 20 + 60 + 45
  EXPECT_EQ(q06::TotalAbove(catalog, 1000), 0);
}

TEST(Q06, NoItemCopiesDuringComputation) {
  auto catalog = MakeCatalog();
  Probe::counts.Reset();
  const int total = q06::TotalAbove(catalog, 50);
  EXPECT_EQ(total, 160);
  EXPECT_EQ(Probe::counts.Copies(), 0)
      << "Passez le conteneur ET les éléments par référence const : aucune copie n'est "
         "nécessaire pour lire les valeurs.";
}
