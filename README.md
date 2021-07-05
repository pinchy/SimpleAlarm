# SimpleAlarm
Simple Alarm object that extends SimpleTime and adds alarm-like features.  Tested on ESP32 . Adds alarm trigger and persistent alarm state between power cycles

Dependencies:
Requires the Preferences Library for storing persistent alarm state between shutdowns,
https://github.com/espressif/arduino-esp32/blob/master/libraries/Preferences/examples/StartCounter/StartCounter.ino

## Example with NTPClient:

    void setup()
    {
      /* your other setup here */

      NTPClient timeClient(ntpUDP, "au.pool.ntp.org", 39600, 60000);
      SimpleAlarm simpleAlarm = SimpleAlarm();

      simpleAlarm.set(8,30,0);  // set alarm to 8:30am
      simpleAlarm.save();  // save alarm to memory
      simpleAlarm.load(); // load alarm from memory
      simpleAlarm.enable();  // enable alarm
    }

    void loop()
    {
      /* your other loop here */

      timeClient.update();
      SimpleTime time(timeClient.getHours(), timeClient.getMinutes(), timeClient.getSeconds());

      if(simpleAlarm.check(time))
      {
        // Alarm activated
      }
    }


## Example with callbacks

    void alarm()
    {
        // Alarm Activated callback function
    }

    void setup()
    {
      /* your other setup here */

      NTPClient timeClient(ntpUDP, "au.pool.ntp.org", 39600, 60000);
      SimpleAlarm simpleAlarm = SimpleAlarm();

      simpleAlarm.setCallBack(alarm);
      simpleAlarm.set(8,30,0);  // set alarm to 8:30am
      simpleAlarm.enable();  // enable alarm
    }

    void loop()
    {
      /* your other loop here */

      timeClient.update();
      SimpleTime time(timeClient.getHours(), timeClient.getMinutes(), timeClient.getSeconds());
      simpleAlarm.check(time));
    }