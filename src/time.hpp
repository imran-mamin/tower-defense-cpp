
#pragma once

#include <cstdint>
#include <functional>

/* Ticks per second, or to put it into other words, frames per second. */
const std::uint32_t ticksPerSecond = 60;

class Timer {
   public:
    Timer(float ttlSeconds, std::uint32_t updatesPerSecond, std::function<void(float)> updateCallback, std::function<void()> onFinishCallback) : ttlTicksInBeginning_(ttlSeconds * ticksPerSecond),
	ttlTicks_(ttlTicksInBeginning_), updateRate_(updatesPerSecond), onUpdateCallback_(updateCallback), onFinishCallback_(onFinishCallback) {}

	void Update() {
		if (ttlTicks_ > 0) {
			/* Call the update function. Parameter (float) is in the range [1.0, 0). */
			if (ttlTicks_ % updateRate_ == 0) {
				onUpdateCallback_((ttlTicks_ * 1.0) / ttlTicksInBeginning_);
			}

			ttlTicks_--;
		}
		/* Timer finished. */
		else if (!finishCallbackCalled) {
			onFinishCallback_();
			finishCallbackCalled = true;
		}
	}

   private:
	const std::uint32_t ttlTicksInBeginning_;
	std::uint32_t ttlTicks_;
	std::uint32_t updateRate_;
	std::function<void(float)> onUpdateCallback_;
	std::function<void()> onFinishCallback_;
	bool finishCallbackCalled = false;
};

