// LECTURE SEULE — ne pas modifier (voir README).
#include "counters.h"

#include <cstdlib>
#include <new>

namespace exam {

std::atomic<std::size_t> AllocCounter::allocations{0};
std::atomic<std::size_t> AllocCounter::deallocations{0};
std::atomic<std::size_t> AllocCounter::bytes_allocated{0};

void AllocCounter::Reset() {
  allocations = 0;
  deallocations = 0;
  bytes_allocated = 0;
}

}  // namespace exam

// Remplacement global de operator new/delete pour compter les allocations.
// (Tiré dans l'exécutable dès qu'un symbole de ce fichier est référencé.)
void* operator new(std::size_t size) {
  ++exam::AllocCounter::allocations;
  exam::AllocCounter::bytes_allocated += size;
  if (void* ptr = std::malloc(size == 0 ? 1 : size)) return ptr;
  throw std::bad_alloc{};
}

void* operator new[](std::size_t size) { return ::operator new(size); }

void operator delete(void* ptr) noexcept {
  if (ptr != nullptr) {
    ++exam::AllocCounter::deallocations;
    std::free(ptr);
  }
}

void operator delete(void* ptr, std::size_t) noexcept { ::operator delete(ptr); }
void operator delete[](void* ptr) noexcept { ::operator delete(ptr); }
void operator delete[](void* ptr, std::size_t) noexcept { ::operator delete(ptr); }
