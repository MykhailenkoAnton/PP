#include "Timer.h"

TimerMS * TimerMS::timer_ = nullptr;

TimerMS * TimerMS::GetInstance()
{
    if(timer_ == nullptr)
    {
        timer_ = new TimerMS();
    }
    return timer_;
}

long long TimerMS::ResultTime()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

void TimerMS::StartTime()
{
    start = std::chrono::steady_clock::now();
}

void TimerMS::EndTime()
{
    end = std::chrono::steady_clock::now();
}