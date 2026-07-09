// LECTURE SEULE — ne pas modifier (voir README).
// API C simulée d'acquisition/libération de handles de textures, instrumentée
// pour les tests (compte les handles vivants, détecte les doubles libérations).
#pragma once

namespace exam {

using TextureHandle = int;

// Acquiert un handle (incrémente le compteur de handles vivants).
[[nodiscard]] TextureHandle AcquireHandle();

// Libère un handle. Libérer un handle inconnu/déjà libéré est signalé
// (DoubleReleaseDetected) au lieu de provoquer un crash.
void ReleaseHandle(TextureHandle handle);

// Remet l'API à zéro (à appeler en début de scénario de test).
void ResetTextureApi();

// Nombre de handles actuellement vivants (acquis et non libérés).
[[nodiscard]] int TextureApiLive();

// Vrai si une double libération a été détectée depuis le dernier reset.
[[nodiscard]] bool DoubleReleaseDetected();

}  // namespace exam
