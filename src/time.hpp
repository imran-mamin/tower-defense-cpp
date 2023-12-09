
#pragma once

#include <cstdint>
#include <functional>

/* Ticks per second, or to put it into other words, frames per second. */
const std::uint32_t ticksPerSecond = 60;

class FiniteTimer {
 public:
  FiniteTimer(float ttlSeconds, const float updateIntervalSeconds)
      : ttlTicks_(ttlSeconds * ticksPerSecond),
        updateIntervalTicks_(updateIntervalSeconds * ticksPerSecond) {}

  bool Update() {
    // Removing callback due to reference issue, resolving to quick fix first
    // Returning true if tick hits updateInterval

    if (ttlTicks_ > 0) {
      ttlTicks_--;

      if (ttlTicks_ % updateIntervalTicks_ == 0) {
        return true;
      }
    }
    /* Timer finished. */
    else if (!finishCallbackCalled) {
      finishCallbackCalled = true;
    }

    return false;
  }

  bool Finished() const { return finishCallbackCalled; }

 private:
  std::uint32_t ttlTicks_;
  // Note: The user of timer must take the accuracy into account here.
  std::uint32_t updateIntervalTicks_;
  bool finishCallbackCalled = false;
};

class CircularTimer {
 public:
  CircularTimer(float ttlSeconds, const float updateIntervalSeconds,
                std::function<void(void)> updateCallback)
      : ttlTicksInBeginning_(ttlSeconds * ticksPerSecond),
        ttlTicks_(ttlTicksInBeginning_),
        updateIntervalTicks_(updateIntervalSeconds * ticksPerSecond),
        onUpdateCallback_(updateCallback) {}

  void Update() {
    if (ttlTicks_ > 0) {
      if (ttlTicks_ % updateIntervalTicks_ == 0) {
        onUpdateCallback_();
      }

      ttlTicks_--;
    } else {
      onUpdateCallback_();
      ttlTicks_ = 0;
    }
  }

 private:
  const std::uint32_t ttlTicksInBeginning_;
  std::uint32_t ttlTicks_;
  std::uint32_t updateIntervalTicks_;
  std::function<void(void)> onUpdateCallback_;
};
