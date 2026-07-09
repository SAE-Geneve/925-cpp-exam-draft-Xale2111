// Q02 — Tests : Vec2 générique, longueurs, égalité.
#include <gtest/gtest.h>

#include <type_traits>

#include "q02_vec2/vec2.h"

using q02::Vec2;

TEST(Q02, FloatLength) {
  EXPECT_FLOAT_EQ((Vec2<float>{3.0f, 4.0f}.Length()), 5.0f);
}

TEST(Q02, FloatNormalized) {
  const auto dir = Vec2<float>{3.0f, 4.0f}.Normalized();
  EXPECT_FLOAT_EQ(dir.x, 0.6f);
  EXPECT_FLOAT_EQ(dir.y, 0.8f);
}

TEST(Q02, IntLengthIsExactFloatingPoint) {
  const Vec2<int> diag{1, 1};
  const auto length = diag.Length();
  EXPECT_TRUE(std::is_floating_point_v<std::decay_t<decltype(length)>>)
      << "Length() d'un Vec2 entier doit retourner un flottant.";
  EXPECT_NEAR(static_cast<double>(length), 1.41421356, 1e-4)
      << "Longueur tronquée : la racine doit être calculée en flottant.";
}

TEST(Q02, DefaultedEquality) {
  EXPECT_TRUE((Vec2<int>{1, 2} == Vec2<int>{1, 2}));
  EXPECT_FALSE((Vec2<int>{1, 2} == Vec2<int>{1, 3}));
  EXPECT_FALSE((Vec2<int>{1, 2} == Vec2<int>{9, 2}));
}
