/*
 Puff.cpp - Library for outputting to 8-wire manifolds.
 Created by Aaron R. Meeuwsen, November 28, 2013.
 Released into the public domain.
 */

#include "Arduino.h"
#include "vac.h"

Vac::Vac(byte _driverBlinkers,
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
         int _blinkerTiming,
         byte _autoTails,
         byte _debug) {

    // Set variables
    driverBlinkers = _driverBlinkers;
    passengerBlinkers = _passengerBlinkers;
    tailLights = _tailLights;
    brakeLights = _brakeLights;
    headLights = _headLights;
    turnLeft = _turnLeft;
    turnRight = _turnRight;
    hazards = _hazards;
    tails = _tails;
    brakes = _brakes;
    heads = _heads;
    blinkerTiming = _blinkerTiming;
    autoTails = _autoTails;
    debug = _debug;
}   

void Vac::setup() {
    pinMode(driverBlinkers, OUTPUT);
    pinMode(passengerBlinkers, OUTPUT);
    pinMode(tailLights, OUTPUT);
  	pinMode(brakeLights, OUTPUT);
  	pinMode(headLights, OUTPUT);
  	pinMode(turnLeft, INPUT);
  	pinMode(turnRight, INPUT);
  	pinMode(hazards, INPUT);
  	pinMode(tails, INPUT);
  	pinMode(brakes, INPUT);
    pinMode(heads, INPUT);
    blinkerState = 0;

    if(debug == 1) {
        Serial.begin(15200);
        pinMode(LEDR, OUTPUT);
        pinMode(LEDG, OUTPUT);
        pinMode(LEDB, OUTPUT);
        digitalWrite(LEDR, HIGH);
        digitalWrite(LEDG, HIGH);
        digitalWrite(LEDB, HIGH);
  }
}

void Vac::onOff(byte input, byte output) {
    if(digitalRead(input) == HIGH) {
        digitalWrite(output, HIGH);
    } else  {
        digitalWrite(output, LOW);
    }
}

void Vac::onOffTwo(byte input, byte output, byte output2) {
    if(digitalRead(input) == HIGH) {
        digitalWrite(output, HIGH);
        digitalWrite(output2, HIGH);
    } else  {
        digitalWrite(output, LOW);
        digitalWrite(output2, HIGH);
    }
}

void Vac::blinkerControl() {
    turningLeft = digitalRead(turnLeft);
    turningRight = digitalRead(turnRight);
    hazarding = digitalRead(hazards);

    // Hazards.
    if(hazarding && blinkerState == 0) {
        digitalWrite(driverBlinkers, HIGH);
        digitalWrite(passengerBlinkers, HIGH);
        blinkerTimer = millis();
        blinkerState = 1;
        if(debug == 1) {
            Serial.println("Hazards initial on");
            digitalWrite(LEDR, LOW);
        }
    } else if(hazarding && blinkerState == 1) {
        if(millis() < blinkerTimer + blinkerTiming) {
            // Do nothing (keep blinkers on).
        } else {
            // Turn blinkers off.
            digitalWrite(driverBlinkers, LOW);
            digitalWrite(passengerBlinkers, LOW);
            blinkerTimer = millis();
            blinkerState = 2;
            if(debug == 1) {
                Serial.println("Hit blink timing, hazards off");
                digitalWrite(LEDR, HIGH);
            }
        }
    } else if(hazarding && blinkerState == 2) {
        if(millis() < blinkerTimer + blinkerTiming) {
            // Do nothing (keep blinkers off).
        } else {
            // Turn blinkers on.
            digitalWrite(driverBlinkers, HIGH);
            digitalWrite(passengerBlinkers, HIGH);
            blinkerTimer = millis();
            blinkerState = 1;
            if(debug == 1) {
                Serial.println("Hit blink timing, hazards on");
                digitalWrite(LEDR, LOW);
            }
        }
    } else if(turningLeft && blinkerState == 0) {
        digitalWrite(driverBlinkers, HIGH);
        blinkerTimer = millis();
        blinkerState = 1;
        if(debug == 1) {
            Serial.println("Left blinkers initial on");
            digitalWrite(LEDB, LOW);
        }
    } else if(turningLeft && blinkerState == 1) {
        if(millis() < blinkerTimer + blinkerTiming) {
            // Do nothing (keep blinkers on).
        } else {
            // Turn blinkers off.
            digitalWrite(driverBlinkers, LOW);
            blinkerTimer = millis();
            blinkerState = 2;
            if(debug == 1) {
                Serial.println("Hit blink timing, left blinkers off");
                digitalWrite(LEDB, HIGH);
            }
        }
    } else if(turningLeft && blinkerState == 2) {
        if(millis() < blinkerTimer + blinkerTiming) {
            // Do nothing (keep blinkers off).
        } else {
            // Turn blinkers on.
            digitalWrite(driverBlinkers, HIGH);
            blinkerTimer = millis();
            blinkerState = 1;
            if(debug == 1) {
                Serial.println("Hit blink timing, left blinkers on");
                digitalWrite(LEDB, LOW);
            }
        }
    } else if(turningRight && blinkerState == 0) {
        digitalWrite(passengerBlinkers, HIGH);
        blinkerTimer = millis();
        blinkerState = 1;
        if(debug == 1) {
            Serial.println("Right blinkers initial on");
            digitalWrite(LEDG, LOW);
        }
    } else if(turningRight && blinkerState == 1) {
        if(millis() < blinkerTimer + blinkerTiming) {
            // Do nothing (keep blinkers on).
        } else {
            // Turn blinkers off.
            digitalWrite(passengerBlinkers, LOW);
            blinkerTimer = millis();
            blinkerState = 2;
            if(debug == 1) {
                Serial.println("Hit blink timing, right blinkers off");
                digitalWrite(LEDG, HIGH);
            }
        }
    } else if(turningRight && blinkerState == 2) {
        if(millis() < blinkerTimer + blinkerTiming) {
            // Do nothing (keep blinkers off).
        } else {
            // Turn blinkers on.
            digitalWrite(passengerBlinkers, HIGH);
            blinkerTimer = millis();
            blinkerState = 1;
            if(debug == 1) {
                Serial.println("Hit blink timing, right blinkers on");
                digitalWrite(LEDG, LOW);
            }
        }
    } else {
        // Cleanup timer and blinkers.
        digitalWrite(driverBlinkers, LOW);
        digitalWrite(passengerBlinkers, LOW);
        blinkerState = 0;
        if(debug == 1) {
            Serial.println("Switch off, blinkers off");
            digitalWrite(LEDR, HIGH);
            digitalWrite(LEDB, HIGH);
            digitalWrite(LEDG, HIGH);
        }
    }
}

void Vac::headLightsControl() {
    if(heads && headLightsState == 0) {
        digitalWrite(headLights, HIGH);
        headLightsState = 1;
    }  else if(heads && headLightsState == 1) {
        // Do nothing headlights are already on.
    } else {
        digitalWrite(headLights, LOW);
        headLightsState = 0;
    }
}

void Vac::tailLightsControl() {
    if(headLightsState && autoTails) {
        digitalWrite(tailLights, HIGH);
    } else {
        digitalWrite(tailLights, LOW);
    }

    if(tails && tailLightsState == 0) {
        digitalWrite(tails, HIGH);
        tailLightsState = 1;
    } else if(tails && tailLightsState == 1) {
        // Do nothing, tail lights already on.
    } else {
        digitalWrite(tailLights, LOW);
        tailLightsState = 0;
    }
}

void Vac::logger() {
    if(debug == 1) {
        Serial.println();
    }
}
