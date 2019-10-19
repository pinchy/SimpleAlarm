#include "SimpleAlarm.h"
#include <Arduino.h>

SimpleAlarm::SimpleAlarm(void) : Time()
{
    this->_enabled = false;
}

bool SimpleAlarm::check(int hours, int minutes, int seconds)
{
    if(!this->_enabled) return false;

    if(this->getHours() == hours && this->getMinutes() == minutes)
    {
        if(this->getSeconds() == seconds && !this->_activated)
        {
            this->_activated = true;
            return true;
        }
        else
        {
            this->_activated = false;
        }
    }
    return false;
}

bool SimpleAlarm::isEnabled(void)
{
    return this->_enabled;
}

void SimpleAlarm::enable(void)
{
    this->_enabled = true;
}

void SimpleAlarm::disable(void)
{
    this->_enabled = false;
}