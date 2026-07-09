# Q02 — `Vec2<T>` : comportements par famille de types

**Type :** Compléter · **Temps conseillé :** ~8 min · **Points :** 5

## Contexte

Le moteur utilise le même `Vec2<T>` pour les positions monde (`float`) et les coordonnées
de grille (`int`). Le code générique actuel traite tous les `T` pareil — ce qui produit des
longueurs tronquées et des normalisations absurdes côté entier. Les `TODO` de `vec2.h`
balisent ce qui manque.

## Contraintes

- Une seule définition générique par fonctionnalité (pas de copies par type).
- Ne modifiez pas `main.cpp` ni les tests.

## À faire

- `Vec2<float>` : `Length` et `Normalized` corrects (comportement actuel conservé).
- `Vec2<int>` : `Length()` retourne un **flottant** exact (ex. `(1,1)` → ≈ 1.414).
- `Vec2<int>{}.Normalized()` **ne compile pas**, avec un diagnostic clair.
- `operator==` utilise l'égalité **par défaut** du langage.

## Pour lancer

Dans CLion, sélectionnez la cible puis lancez-la (bouton ▶ ou raccourci) :
- **`q02_vec2`** — l'exécutable de démonstration (observez le comportement).
- **`q02_vec2_test`** — les tests de la question (doivent passer au vert).

N'oubliez pas de remplir `answers/q02_vec2.md`.
