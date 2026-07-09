// Q08 — Tests : Widget lit correctement la largeur de son Panel.
// Cette cible est EXCLUDE_FROM_ALL : sur le code livré, widget.cc NE COMPILE
// PAS (Panel incomplet). Sur la solution, elle passe.
#include <gtest/gtest.h>

#include "q08_linkage/panel.h"
#include "q08_linkage/widget.h"

TEST(Q08, WidgetReadsPanelWidth) {
  const q08::Panel panel(120);
  q08::Widget widget;
  widget.SetPanel(&panel);
  EXPECT_EQ(widget.PanelWidth(), 120);
}

TEST(Q08, WidgetTracksReassignedPanel) {
  const q08::Panel small(10);
  const q08::Panel big(99);
  q08::Widget widget;
  widget.SetPanel(&small);
  EXPECT_EQ(widget.PanelWidth(), 10);
  widget.SetPanel(&big);
  EXPECT_EQ(widget.PanelWidth(), 99);
}
