#ifndef TIMER_H_
#define TIMER_H_

#include <chrono>

class TimerMS
{
private:
    std::chrono::time_point<std::chrono::steady_clock> start;
    std::chrono::time_point<std::chrono::steady_clock> end;

protected:

    static TimerMS* timer_;

    TimerMS() {}
public:

    static const int EXPIRED_WAIT_TIME_MS = 250;

    static TimerMS *GetInstance();

    void StartTime();
    void EndTime();
    long long ResultTime();

    void operator=(const TimerMS &) = delete;
    TimerMS(TimerMS &other) = delete;
};


#endif