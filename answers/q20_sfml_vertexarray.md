# Q20 — SFML : d'un draw call par cellule à un VertexArray

## 1. Problème(s) identifié(s)

<!-- 2-3 phrases. Quels étaient les bugs/défauts, y compris ceux non mentionnés par l'énoncé ? -->

On fait un draw call pour chaque vertex de la grid. On aimerait faire un draw call pour chaque cellule de la grid.

## 2. Correction choisie et pourquoi

<!-- 3-4 phrases. Justifiez techniquement votre choix. -->
Il faut utiliser un VertexArray dans lequel on regroupe tous les vertex, puis on fait un draw call pour cet array. 
Cela permet de limiter l'appel au draw call.