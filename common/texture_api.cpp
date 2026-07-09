// LECTURE SEULE — ne pas modifier (voir README).
#include "texture_api.h"

#include <unordered_set>

namespace exam {
namespace {

int g_next_handle = 1;
bool g_double_release = false;
std::unordered_set<TextureHandle> g_live_handles;

}  // namespace

TextureHandle AcquireHandle() {
  const TextureHandle handle = g_next_handle++;
  g_live_handles.insert(handle);
  return handle;
}

void ReleaseHandle(TextureHandle handle) {
  const auto it = g_live_handles.find(handle);
  if (it == g_live_handles.end()) {
    g_double_release = true;  // handle inconnu ou déjà libéré
    return;
  }
  g_live_handles.erase(it);
}

void ResetTextureApi() {
  g_next_handle = 1;
  g_double_release = false;
  g_live_handles.clear();
}

int TextureApiLive() { return static_cast<int>(g_live_handles.size()); }

bool DoubleReleaseDetected() { return g_double_release; }

}  // namespace exam
