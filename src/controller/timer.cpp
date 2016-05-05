#include "timer.h"

Timer::Timer()
{
	start();
}

Timer::~Timer()
{

}

void Timer::start()
{
	timestamp = std::chrono::high_resolution_clock::now();
}

int Timer::finish()
{
	std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
	int time = std::chrono::duration_cast<std::chrono::nanoseconds>(now - timestamp).count();
	return time;
}
