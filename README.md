[![compile vac](https://github.com/ameeuwsen/vac/actions/workflows/compile-vac.yml/badge.svg)](https://github.com/ameeuwsen/vac/actions/workflows/compile-vac.yml)
# Vehicle Accessory Controller (vac)
### Overview
Sketch to control lighting and other functions for custom vehicle wiring. Outputs should be wired to fuse protected relays to power devices. Resistors should be used to any inputs to protect against false digital reads.

### Important Notes
The sketch was designed and debugged against the [Arduino Portenta H7](https://store-usa.arduino.cc/products/portenta-h7?selectedStore=us). The sketch is stable and will work with any Arduino board, however debugging functions are specfic to Portenta and may not compile on other boards if debugging is enabled.

## Setup
- Edit lines 5-17 to match your input and output pins
- Load sketch

## Variables Overview
Inputs and outputs are predefined when instantiating the Vac class. For any inputs or outputs not needed simply leave a 0 for the pin number.
### Inputs:
| Variable Name | Description |
| ---------- | ---------- |
| turnLeft  | Input for left blinkers |
| passRight | Input for right blinkers |
| hazards   | Input for hazards (both blinkers simultaneously) |
| tails     | Input for tail lights |
| brakes    | Input for brake lights |
| heads     | Input for headlights |
### Outputs:
| Variable Name | Description |
| ---------- | ---------- |
| driverBlinkers | Output for driver side blinkers |
| passengerBlinkers  | Output for passenger side blinkers |
| tailLights   | Output for tail lights |
| brakeLights  | Output for brake lights |
| headLights   | Output for headlights |

## Customizations:
| Variable Name | Description |
| ---------- | ---------- |
| timing    | time in milliseconds between blinker states |
| autoTails | setting to link tail light output to headlight input |
| debug     | turn debugging (serial output) on and off (0 or 1). |

## Functions overview
Most of the code that executes is housed in a custom library that handles all timing/switching/sensing. The library is flexible enough to take inputs either created in the library itself on instantiation or using pins defined on the Arduino sketch side. Predefined functions for custimzation are listed below.

Below are fuctions that can be reused throughout the sketch 
### onOff(input, output) - 1 input ➡️ 1 output
This function is for simple switching by reading for a HIGH input and writing HIGH for one output. Defaults to LOW for output.

### onOffTwo(input, output, output2) - 1 input ➡️ 2 outputs
This function is for simple switching by reading for a HIGH input and writing a HIGH output for two defined outputs. Defaults to LOW for both outputs.

### blinkers() - used exclusively for blinker functions
This function assumes 4 blinker outputs that are defined in the library itself with provided values on class instantiation. The blink duration between on/off can be customized by editing the 'timing' variable in the Arduino sketch. A hazard switch feature is also included to turn on all blinkers when hazard switch is HIGH.

## Debugging
This program does come with limited debugging feedback. Simply set the debug value in Vac class declaration in Arduino sketch to desired value.

## Future updates
- [ ] Add comfort blinker timing function with definable timing and blinks
- [ ] Provide functionality for low and high beams

## Disclaimer
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
