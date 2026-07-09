// LECTURE SEULE — ne pas modifier (voir README).
#include "gpu_buffer.h"

#include <unordered_set>

namespace exam {
namespace {

BufferId g_next_id = 1;
bool g_double_release = false;
std::unordered_set<BufferId> g_live;

}  // namespace

BufferId AcquireBuffer() {
  const BufferId id = g_next_id++;
  g_live.insert(id);
  return id;
}

void ReleaseBuffer(BufferId id) {
  const auto it = g_live.find(id);
  if (it == g_live.end()) {
    g_double_release = true;
    return;
  }
  g_live.erase(it);
}

void ResetBufferApi() {
  g_next_id = 1;
  g_double_release = false;
  g_live.clear();
}

int BufferApiLive() { return static_cast<int>(g_live.size()); }

bool BufferDoubleReleaseDetected() { return g_double_release; }

}  // namespace exam
