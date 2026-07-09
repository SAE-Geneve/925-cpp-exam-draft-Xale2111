# Q02 — `Vec2<T>` : comportements par famille de types

## 1. Problème(s) identifié(s)

<!-- 2-3 phrases. Quels étaient les bugs/défauts, y compris ceux non mentionnés par l'énoncé ? -->

1a :
La méthode Length() renvoie toujours le type T. si on utilise un int, on obtient un int avec perte des infos après la virgule. 


1b :
Aucune vérification n'est effectuée sur le type de T. On peut donc Normalizer un Vector2<int>

## 2. Correction choisie et pourquoi

<!-- 3-4 phrases. Justifiez techniquement votre choix. -->

1a :
il faut renvoyer un float au lieu de T (même si c'est un int, on renvoie un float). Il faut forcer le type de retour de la méthode.

1b :
il faut rajouter un static_assert pour empecher le programme de compilier un Vec2<int>. Le static_assert va forcer l'utilisation de float.
