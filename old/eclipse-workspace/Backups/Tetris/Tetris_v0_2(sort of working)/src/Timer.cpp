#include "Timer.h"

Timer::Timer()
{
	startTicks = 0;
	pausedTicks = 0;

	started = false;
	paused = false;
}

void Timer::start()
{
	startTicks = SDL_GetTicks();
	pausedTicks = 0;
	started = true;
	paused = false;
}

void Timer::stop()
{
	started = false;
	paused = false;
	startTicks = 0;
	pausedTicks = 0;
}

void Timer::pause()
{
	if ( started && !paused )
	{
		paused = true;

		pausedTicks = SDL_GetTicks() - startTicks;
		startTicks = 0;
	}
}

void Timer::unpause()
{
	if ( started && paused )
	{
		paused = false;

		startTicks = SDL_GetTicks() - pausedTicks;

		pausedTicks = 0;
	}
}

Uint32 Timer::getTicks()
{
	if ( started )
	{
		if ( paused )
		{
			return pausedTicks;
		}
		else
		{
			return SDL_GetTicks() - startTicks;
		}
	}

	return 0;
}

bool Timer::isStarted() { return started; }

bool Timer::isPaused() { return paused; }

















