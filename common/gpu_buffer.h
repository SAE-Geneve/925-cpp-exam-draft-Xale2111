// LECTURE SEULE — ne pas modifier (voir README).
// API simulée d'allocation de buffers GPU, instrumentée pour les tests
// (compte les buffers vivants, détecte les doubles libérations). Aucune
// mémoire réelle n'est manipulée : pas d'UB même en cas de bug côté étudiant.
#pragma once

namespace exam {

using BufferId = int;

// Acquiert un buffer (id non nul, unique).
[[nodiscard]] BufferId AcquireBuffer();

// Libère un buffer. Libérer un id inconnu/déjà libéré est signalé
// (BufferDoubleReleaseDetected) au lieu de corrompre quoi que ce soit.
void ReleaseBuffer(BufferId id);

void ResetBufferApi();
[[nodiscard]] int BufferApiLive();
[[nodiscard]] bool BufferDoubleReleaseDetected();

}  // namespace exam
