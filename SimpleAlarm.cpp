#include "SimpleAlarm.h"

SimpleAlarm::SimpleAlarm(void) : SimpleTime()
{
    this->_enabled = false;
}

#ifdef ARDUINO_ARCH_ESP32
void SimpleAlarm::load()
{
    this->_mem.begin("simplealarm", false);
    this->set(this->_mem.getUInt("hours"), this->_mem.getUInt("minutes"), this->_mem.getUInt("seconds"));
    this->_enabled = this->_mem.getUInt("enabled");
}

void SimpleAlarm::save()
{
    this->_mem.begin("simplealarm", false);
    this->_mem.putUInt("hours", this->getHours());
    this->_mem.putUInt("minutes", this->getMinutes());
    this->_mem.putUInt("seconds", this->getSeconds());
}
#endif


bool SimpleAlarm::check(SimpleTime t)
{
    return this->check(t.getHours(), t.getMinutes(), t.getSeconds());
}

bool SimpleAlarm::check(int hours, int minutes, int seconds)
{
    if(!this->_enabled) return false;

    if(this->getHours() == hours && this->getMinutes() == minutes)
    {
        if(this->getSeconds() == seconds && !this->_activated)
        {
            this->_activated = true;
            if(this->_callback != nullptr) this->_callback;
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

    #ifdef ARDUINO_ARCH_ESP32
    this->_mem.begin("simplealarm", false);
    this->_mem.putUInt("enabled", this->_enabled);
    #endif
}

void SimpleAlarm::disable(void)
{
    this->_enabled = false;

    #ifdef ARDUINO_ARCH_ESP32
    this->_mem.begin("simplealarm", false);
    this->_mem.putUInt("enabled", this->_enabled);
    #endif
}