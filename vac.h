/*
  Puff.h - Library for arduino 8-wire manifold air ride systems.
  Script also includes functions for leveling with rotary position sensors.
  Created by Aaron R. Meeuwsen, November 28, 2013.
  Released into the public domain.
*/

#include "Arduino.h"

#ifndef Vac_h
#define Vac_h

class Vac {
public:
    Vac(byte _driverBlinkers,
         byte _passengerBlinkers,
         byte _tailLights, 
		 byte _brakeLights,
		 byte _headLights,
         byte _turnLeft,
         byte _turnRight,
         byte _hazards,
         byte _tails,
         byte _brakes,
         byte _heads,
         byte _blinkerTiming,
         byte _autoTails,
         byte _debug);

    byte driverBlinkers;
    byte passengerBlinkers;
    byte tailLights;
    byte brakeLights;
    byte headLights;
    byte turnLeft;
    byte turnRight;
    byte hazards;
    byte tails;
    byte brakes;
    byte heads;
    int blinkerTiming;
    byte autoTails;
    byte debug;

    // Program variables.
    byte turningLeft;
    byte turningRight;
    byte hazarding;
    unsigned long blinkerTimer;

    // Program states
    byte blinkerState;
    byte headLightsState;
    byte tailLightsState;

    // Initial setup function.
    void setup();
    
    // Single input, single output.
    void onOff(byte input, byte output);

    // Single input, double output.
    void onOffTwo(byte input, byte output, byte output2);

    // Blinker control function.
    void blinkerControl();

    // Headlights control function.
    void headLightsControl();

    // Taillights control function.
    void tailLightsControl();

    // Logging callback function.
    void logger();

private:
};
#endif