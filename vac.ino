#include "vac.h"

//Define pins here according to comments
Vac vac(
0,   // driverBlinkers    = Output for driver side blinkers
0,   // passengerBlinkers = Output for passenger side blinkers
0,   // tailLights        = Output for tail lights
0,   // brakeLights       = Output for brake lights
0,   // headLights        = Output for head lights
0,   // turnLeft          = Input for left blinkers
0,   // turnRight         = Input for right blinkers
0,   // hazards           = Input for hazards (all blinkers)
0,   // tails             = Input for tail lights
0,   // brakes            = Input for brake lights
0,   // heads             = Input for head lights
500, // timing            = The time in milliseconds between blinker blinks
1,   // autoTails         = (1 = tailLights on with headLights) (0 manual)
1    // Debug: 1 = on | 0 = off
);
       
void setup() {
  vac.setup();
}

void loop() {
  // Check for blinkers (includes hazards).
  vac.blinkerControl();

  // Check for head lights.
  vac.headLightsControl();

  // Check for tail lights.
  vac.tailLightsControl();

  // Check for brake lights.
  vac.onOff(vac.brakes, vac.brakeLights);
}
