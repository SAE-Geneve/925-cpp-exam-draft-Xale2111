# Q04 — Ranges : du triple vecteur au pipeline

**Type :** Refactoriser · **Temps conseillé :** ~8 min · **Points :** 5

## Contexte

Le HUD affiche les scores des 5 premiers ennemis vivants de la vague. Le calcul actuel
fonctionne, mais il matérialise trois vecteurs et recharge la vague plusieurs fois — sur
une grosse vague, ça se voit à la frame. Lancez `q04_ranges` pour voir les compteurs.

## Contraintes

- Ne modifiez pas `enemies.h` (zone « NE PAS MODIFIER »).
- La signature de `TopScores()` est conservée (elle retourne un vecteur possédant
  ses données — réfléchissez à la durée de vie de ce que vos vues regardent).

## À faire

- La zone `REFACTOR` de `pipeline.h` devra être réécrite en **pipeline ranges** :
  `views::filter | views::transform | views::take`, matérialisé avec `std::ranges::to`.
- Le résultat est **identique** à la version actuelle.
- **Aucune copie d'`Enemy`** pendant le calcul (le compteur doit rester à 0).
- `GetEnemies()` est appelée **exactement une fois** par appel de `TopScores()`.

## Pour lancer

Dans CLion, sélectionnez la cible puis lancez-la (bouton ▶ ou raccourci) :
- **`q04_ranges`** — l'exécutable de démonstration (observez le comportement).
- **`q04_ranges_test`** — les tests de la question (doivent passer au vert).

N'oubliez pas de remplir `answers/q04_ranges.md`.
