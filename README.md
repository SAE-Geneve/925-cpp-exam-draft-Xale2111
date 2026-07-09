# Examen pratique C++ — Module 925 (SAE Genève)

**Durée : 3h · 20 questions · 100 points (20 × 5)**

Chaque question est **indépendante** : un dossier, un exécutable, un test, une justification écrite.

## Prérequis

- **Visual Studio 2022** (toolchain MSVC x64) — l'IDE n'est pas requis, seule la toolchain l'est.
- **CLion** (Windows).
- **vcpkg** installé, avec la variable d'environnement **`VCPKG_ROOT`** pointant vers son dossier
  (ex. `C:\dev\vcpkg`). Vérifiez dans un terminal : `echo %VCPKG_ROOT%`.

## Setup pas-à-pas

1. Clonez votre repo d'examen (lien classroom50).
2. Ouvrez le dossier dans **CLion** : il détecte le `CMakeLists.txt` racine.
3. Dans le profil CMake (Settings → Build, Execution, Deployment → CMake), renseignez la
   **toolchain vcpkg** en options CMake :
   `-DCMAKE_TOOLCHAIN_FILE=%VCPKG_ROOT%/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=x64-windows`
4. Premier configure : vcpkg installe SFML et GoogleTest — **comptez plusieurs minutes**, c'est normal.
5. Buildez la cible **`q02_vec2`** et lancez **`q02_vec2_test`** pour vérifier que tout fonctionne
   (le test échoue : c'est attendu, c'est votre travail de le faire passer).

> ⚠️ **Q01 et Q08 ne compilent pas** dans l'état livré — c'est volontaire, ce sont des questions à
> réparer. Elles sont exclues du « Build All » pour ne pas bloquer le reste.

## Workflow d'examen

Pour **chaque** question (dossier `questions/<qNN_sujet>/`) :

1. Lisez le fichier **`_consignes.md`** du dossier (il apparaît en tête, avant le code).
2. Corrigez / complétez / refactorisez le code du dossier de la question.
3. Validez en buildant puis lançant la cible de test **`<qNN_sujet>_test`** dans CLion
   (ex. `q02_vec2_test`). En ligne de commande :
   ```
   cmake --build <dossier-build> --target q02_vec2_test
   ctest --test-dir <dossier-build> -R q02_vec2
   ```
4. **Remplissez `answers/qNN.md`** — la justification écrite compte dans le barème.

## Règles

- **`common/` est en LECTURE SEULE.** Toute modification y est considérée comme une tentative de
  contournement et annule la question concernée.
- **Ne modifiez jamais les zones marquées `// NE PAS MODIFIER`** (les tests le détectent).
- Ne modifiez pas les fichiers de `tests/`.
- Balisage dans le code : `// FIXME` (à corriger), `// TODO` (à compléter),
  `// REFACTOR-START` / `// REFACTOR-END` (zone à réécrire).

## Barème

- **5 points par question** : tests automatiques (3 pts) + justification écrite `answers/qNN.md` (2 pts).
  Le détail de la pondération sera communiqué avec les résultats.
- Un test partiellement vert rapporte des points partiels : corrigez ce que vous pouvez.

## Timing conseillé

~8 minutes par question, puis **20 minutes de relecture** finale (tests + justifications).
Ne restez pas bloqué : toutes les questions sont indépendantes, passez à la suivante.

## Rendu (classroom50)

1. Vérifiez que tout est commité : `git status` doit être **propre**.
2. `git add -A && git commit -m "Rendu final"` puis `git push`.
3. Revérifiez sur l'interface web que votre dernier commit est bien visible.
   **Seul ce qui est poussé avant la fin de l'épreuve est corrigé.**
