#include <chrono>

class TimeInterval{
public:
	std::chrono::high_resolution_clock::time_point start_time;
	std::chrono::high_resolution_clock::time_point end_time;

public:
	TimeInterval();
	void start();
	void stop();
	float GetInterval();
};

TimeInterval::TimeInterval() {}

void TimeInterval::start() {
	start_time = std::chrono::high_resolution_clock::now();
}

void TimeInterval::stop() {
	end_time = std::chrono::high_resolution_clock::now();
}

float TimeInterval::GetInterval() {
	std::chrono::duration<float, std::micro> duration = end_time - start_time;
	return duration.count();
}