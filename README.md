# Vehicle Accessory Controller (vac)
Sketch to control various lighting and other functions for custom vehicle wiring setups.

## Variables Overview
A number of inputs and outputs are predefined when instantiating the Vac class.
### Inputs:
| Variable Name | Description |
| ---------- | ---------- |
| turnLeft  | Input for left blinkers |
| passRight | Input for right blinkers |
| hazards   | Input for hazards (both blinkers simultaneously) |
| tails     | Input for tail lights |
| brakes    | Input for brake lights |
| heads     | Input for head lights |
### Outputs:
| Variable Name | Description |
| ---------- | ---------- |
| driverFrontBlinker | Output for driver side front blinker |
| driverRearBlinker | Output for driver side rear blinker |
| driverBrakeLight  | Output for driver side brake light |
| driverTailLight   | Output for driver side tail light |
| passFrontBlinker  | Output for passenger front blinker light |
| passRearBlinker   | Output for passenger rear blinker light |
| passBrakeLight    | Output for passenger side brake light |
| passTailLight     | Output for passenger side tail light |
| driverHeadLight   | Output for driver side head light |
| passHeadLight     | Output for passenger side head light |

## Customizations:
| Variable Name | Description |
| ---------- | ---------- |
| timing    | time in milliseconds between blinker states |
| autoTails | setting to link tail light output to headlight input |
| debug     | turn debugging (serial output) on and off (0 or 1). |

## Functions overview
Most of the code that executes is housed in a custom library that handles all timing/switching/sensing. The library is flexible enough to take inputs either created in the library itself on instantiation or using pins defined on the Arduino sketch side. Predefined functions are listed below.
### onOff(input, output) - 1 input ➡️ 1 output
This function is for simple switching by reading for a HIGH input and writing HIGH for one output. Defaults to LOW for output.

### onOffTwo(input, output, output) - 1 input ➡️ 2 outputs
This function is for simple switching by reading for a HIGH input and writing a HIGH output for two defined outputs. Defaults to LOW for both outputs.

### blinkers() - used exclusively for blinker functions
This function assumes 4 blinker outputs that are defined in the library itself with provided values on class instantiation. The blink duration between on/off can be customized by editing the 'timing' variable in the Arduino sketch. A hazard switch feature is also included to turn on all blinkers when hazard switch is HIGH.

## Setup
- Edit lines 5-17 to match your input and output wiring
- Load sketch

## Debugging
This program does come with limited debugging feedback. Simply set the debug value in Vac class declaration in Arduino sketch to desired value.

## @TODO
- Add comfort blinker timing function with definable timing and blinks
- Enhance debugging mode to allow for serial only programming - account for random float values on digitalReads.
- Consolidate onOff functions into one by using variable array for outputs - one input controlling any number of outputs.
- Provide functionality for low and high beams