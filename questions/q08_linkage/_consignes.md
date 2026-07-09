# Q08 — Forward declaration & type incomplet

**Type :** Fixer · **Temps conseillé :** ~8 min · **Points :** 5

## Contexte

`Widget` référence un `Panel` par pointeur. Son header `widget.h` se contente d'une **forward
declaration** de `Panel` (`class Panel;`) — ce qui suffit pour un `Panel*`. Mais `widget.cc`,
qui appelle `Panel::Width()`, ne compile pas : à cet endroit, `Panel` est un **type incomplet**.
La cible `q08_linkage` ne compile donc pas.

## Contraintes

- La forward declaration dans `widget.h` doit **rester** (on ne veut pas alourdir le header
  avec l'inclusion de `panel.h`).
- Ne modifiez pas `panel.h` / `panel.cc`.

## À faire

- Faites compiler `widget.cc` : le fichier qui **utilise** réellement les méthodes de `Panel`
  doit disposer de sa définition complète. Réfléchissez à l'endroit où inclure `panel.h`.
- `Widget::PanelWidth()` renvoie la largeur du panneau associé.

## Pour lancer

Dans CLion, sélectionnez la cible puis lancez-la (bouton ▶ ou raccourci) :
- **`q08_linkage`** — l'exécutable de démonstration (observez le comportement).
- **`q08_linkage_test`** — les tests de la question (doivent passer au vert).

N'oubliez pas de remplir `answers/q08_linkage.md`.
