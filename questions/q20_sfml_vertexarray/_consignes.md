# Q20 — SFML : d'un draw call par cellule à un VertexArray

**Type :** Refactoriser · **Temps conseillé :** ~8 min · **Points :** 5

## Contexte

Le rendu de la grille 64×64 dessine un `sf::RectangleShape` par cellule, soit 4096 draw calls par
frame. Refactorisez le rendu pour tout envoyer au GPU en **un seul** `sf::VertexArray`.

## Contraintes

- SFML 3 : utilisez `sf::Vector2f`, `sf::PrimitiveType::Triangles` (les `Quads` n'existent plus).
- Ne modifiez que la zone `REFACTOR` de `main.cpp` et l'implémentation de `BuildGridVertices` ;
  ne changez pas la signature fournie.

## À faire

- Implémentez `BuildGridVertices(const exam::Grid&) -> sf::VertexArray` (signature imposée) :
  un `sf::VertexArray` en `sf::PrimitiveType::Triangles`, **6 sommets par cellule** (2 triangles),
  couleur par sommet issue de `CellColor`.
- Réécrivez la boucle de rendu de `main.cpp` pour dessiner ce `VertexArray` en **un seul** draw call.
- Les positions sont en pixels : la cellule `(x, y)` occupe `[x·kCellSize, (x+1)·kCellSize]` en X
  et l'équivalent en Y.

## Pour lancer

Dans CLion, sélectionnez la cible puis lancez-la (bouton ▶ ou raccourci) :
- **`q20_sfml_vertexarray`** — l'exécutable de démonstration (observez le comportement).
- **`q20_sfml_vertexarray_test`** — les tests de la question (doivent passer au vert).

N'oubliez pas de remplir `answers/q20_sfml_vertexarray.md`.
