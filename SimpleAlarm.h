#ifndef SIMPLEALARM_H
#define SIMPLEALARM_H

#include <SimpleTime.h>
#include <Arduino.h>
#include <Preferences.h>    

class SimpleAlarm : public SimpleTime
{
    private:
        bool _enabled;
        bool _activated;
        Preferences _mem;

    public:
        SimpleAlarm(void);

        /*
         * Load the alarm from permanent memory, to surive a reboot.
         */
        void load();

        /*
         * Save the alarm to permanent memory, to surive a reboot.
         */
        void save();
        
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