#include "clock.hpp"
#include <iostream>

Clock::Clock()
{
    mCurrentTime = SDL_GetPerformanceCounter();
    mLastTime = 0;
    mDeltaTime = 0.0;
    mFrames = 0;
    mFPS = 0;
    mTotalTime = 0;
}

void Clock::tick()
{
    mLastTime = mCurrentTime;
    mCurrentTime = SDL_GetPerformanceCounter();

    // Calculate Delta Time
    mDeltaTime = (double)((mCurrentTime - mLastTime) * 1000 / (double)SDL_GetPerformanceFrequency());

    // Calculate FPS
    double secondsElapsed = (mCurrentTime - mLastTime) / (double)SDL_GetPerformanceFrequency();
    mTotalTime += secondsElapsed;
    mFrames++;

    if (mTotalTime > 1.0f)
    {
        mFPS = mFrames;
        mFrames = 0;
        mTotalTime = 0;
    }
}
