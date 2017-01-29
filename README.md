# Arduino-Line-Follower
Follows a white line on a black background. Must be calibrated before use depending on lighting of surroundings.

## Instructions
1)Setup bot as per XLR8 tutorial without interfacing with a Bluetooth Module, i.e. setup chassis, wheels, motors, a power source, motor driver circuit uing L239D, etc. Two wheels with a ball caster should suffice. [XLR8 Tutorial](https://stab-iitb.org/robotics-club/tutorials/XLR8/) <br><br>
2)Connect motor controllers to the Arduino (digital output pins). <br><br>
3)Setup three IR sensors and attach them sufficiently close to the motors. <br><br>
4)Reconfigure code to reflect actual pins and differerntiate between line and background. <br><br>
5)Burn the code on the Arduino
