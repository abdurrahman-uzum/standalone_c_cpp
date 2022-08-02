#ifndef TIMER_H_
#define TIMER_H_

#include <SDL.h>


class Timer
{
	public:
		Timer();

		void start();
		void stop();
		void pause();
		void unpause();
		Uint32 getTicks();

		bool isStarted();
		bool isPaused();


	private:
		int startTicks;
		int pausedTicks;
		bool started;
		bool paused;

};



#endif /* TIMER_H_ */
