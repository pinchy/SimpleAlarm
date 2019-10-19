#ifndef SIMPLEALARM_H
#define SIMPLEALARM_H

#include <Time.h>
#include <Arduino.h>

class SimpleAlarm : public Time
{
    private:
        bool _enabled;
        bool _activated;

    public:
        SimpleAlarm(void);
        bool check(int hours, int minutes, int seconds);
        void enable();
        void disable();
};

#endif 