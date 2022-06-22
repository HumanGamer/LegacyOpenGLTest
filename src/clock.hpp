#ifndef __CLOCK_H__
#define __CLOCK_H__

#include <SDL.h>

class Clock
{
public:
    Clock();
    void tick();

    inline double getDeltaTime() const { return mDeltaTime; }
    inline int getFPS() const { return mFPS; }

private:
    Uint64 mCurrentTime;
    Uint64 mLastTime;
    double mDeltaTime;
    int mFrames;
    int mFPS;
    double mTotalTime;
};

#endif // __CLOCK_H__
