# Q06 — Const correctness : au-delà du `const_cast`

## 1. Problème(s) identifié(s)

<!-- 2-3 phrases. Quels étaient les bugs/défauts, y compris ceux non mentionnés par l'énoncé ? -->
dans la boucle `for`, on passe les items par copie. On finit par compter les copies en boucle. La liste d'items est aussi passée en copie

## 2. Correction choisie et pourquoi

<!-- 3-4 phrases. Justifiez techniquement votre choix. -->
Il faut passer la liste par référence en utilisant le & et dans la boucle for, il faut récupérer l'item par référence également. On passe dee Item item à Item& item. 