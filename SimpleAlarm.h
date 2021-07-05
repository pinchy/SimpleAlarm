#ifndef SIMPLEALARM_H
#define SIMPLEALARM_H

#include <Arduino.h>
#include <SimpleTime.h>

#ifdef ARDUINO_ARCH_ESP32
#include <Preferences.h>    
#endif

class SimpleAlarm : public SimpleTime
{
    private:
        bool _enabled;
        bool _activated;
        
        #ifdef ARDUINO_ARCH_ESP32
        Preferences _mem;
        #endif

    public:
        SimpleAlarm(void);

        #ifdef ARDUINO_ARCH_ESP32
        /*
         * Load the alarm from permanent memory, to surive a reboot. (ESP32 ONLY)
         */
        void load();

        /*
         * Save the alarm to permanent memory, to surive a reboot (ESP32 ONLY)
         */
        void save();
        #endif
        
        /* Compares the passed time with the alarm set time and triggers when
         * the hours, minutes and seconds match.  If the alarm is enabled, then
         * the function returns true.  Only returns true once during the active
         * second.
         */
        bool check(SimpleTime t);
        bool check(int hours, int minutes, int seconds);

        /* 
         * Enables the alarm
         */
        void enable();

        /* 
         * Disavles the alarm
         */
        void disable();

        /* 
         * Returns the current alarm enabled state (boolean)
         */
        bool isEnabled(void);
};

#endif 