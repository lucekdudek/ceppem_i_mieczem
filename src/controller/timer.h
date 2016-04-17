#ifndef TIMER_H
#define TIMER_H
#include <chrono>

class Timer {
public:
	Timer();
	~Timer();
	void start();
	int finish();
protected:
	std::chrono::high_resolution_clock::time_point timestamp;
};

#endif //TIMER_H
