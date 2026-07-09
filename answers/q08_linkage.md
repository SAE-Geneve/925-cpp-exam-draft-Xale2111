# Q08 — Durée de vie, ODR et édition de liens

## 1. Problème(s) identifié(s)

<!-- 2-3 phrases. Quels étaient les bugs/défauts, y compris ceux non mentionnés par l'énoncé ? -->
Il y a une référence circulaire entre deux classes. Player appel team.h et Team appel player.h. Les fichiers s'appellent en boucle.
## 2. Correction choisie et pourquoi

<!-- 3-4 phrases. Justifiez techniquement votre choix (inline vs autre, retour par valeur, static local). -->
Pour éviter que chaque fichier .h s'appelle en boucle, il faut déplacer les include dans les .cc
Pour quand même avoir dire à la class Player que Team existe, on fait une forward déclaration en appellant class Team; avant. Puis, dans le fichier player.cc, on appelle le include de team.h. Il faut ensuite déplacer le contenu de TotalScore() dans le .cc.
Même logique pour Team avec player.cc.