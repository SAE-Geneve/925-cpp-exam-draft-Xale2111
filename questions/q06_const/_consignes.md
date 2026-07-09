# Q06 — Références : passer sans copier

**Type :** Fixer · **Temps conseillé :** ~8 min · **Points :** 5

## Contexte

`TotalAbove` parcourt un catalogue d'objets (`Item`, une classe maison) et somme la valeur de
ceux qui atteignent un seuil. Le calcul est correct, mais il **copie** les objets sans raison :
`Item` compte ses copies, et la démo en affiche beaucoup. Lancez `q06_const` pour le voir.

## Contraintes

- Ne changez que la façon de **passer/parcourir** les données ; la logique de calcul reste.
- Ne modifiez pas la classe `Item` ni les compteurs.

## À faire

- `TotalAbove` renvoie le bon total **sans copier aucun `Item`** : le compteur de copies doit
  rester à **0** après l'appel.
- Une référence n'instancie rien : passez le conteneur et parcourez ses éléments par référence const.

## Pour lancer

Dans CLion, sélectionnez la cible puis lancez-la (bouton ▶ ou raccourci) :
- **`q06_const`** — l'exécutable de démonstration (observez le comportement).
- **`q06_const_test`** — les tests de la question (doivent passer au vert).

N'oubliez pas de remplir `answers/q06_const.md`.
