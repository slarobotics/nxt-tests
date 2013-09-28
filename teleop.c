/*
* teleop.c -- Logitech Dual Action Control
* Open an issue if anything needs to be added or changed
* ------------------------------------------------------------
* teleop.c utilizes "tank drive" -- Which means each joystick controls
* an individual motor.
* ------------------------------------------------------------
* ------------------------------------Config of Motors-----------------------------
*    [I/O Port]              [Name]              [Type]              [Description]
*    Port B                  motorB              NXT                 Right motor
*    Port C                  motorC              NXT                 Left motor
* ---------------------------------------------------------------------------------
*/

#include "JoystickDriver.c"

void initControl()
{
  int threshold = 20;             /* Int 'threshold' will allow us to ignore low
                                    readings that keep our robot in perpetual motion.
                                    We need to tinker with the variable */

  while(true)                            // Infinite loop:
  {
    getJoystickSettings(joystick); // get joystick readings
    if(abs(joystick.joy1_y2) > threshold)   // If the right analog stick's Y-axis readings are either above or below the threshold:
    {
      motor[motorB] = joystick.joy1_y2;         // Motor B is assigned a power level equal to the right analog stick's Y-axis reading.
    }
    else                                    // Else if the readings are within the threshold:
    {
      motor[motorB] = 0;                        // Motor B is stopped with a power level of 0.
    }


    if(abs(joystick.joy1_y1) > threshold)   // If the left analog stick's Y-axis readings are either above or below the threshold:
    {
      motor[motorC] = joystick.joy1_y1;         // Motor C is assigned a power level equal to the left analog stick's Y-axis reading.
    }
    else                                    // Else if the readings are within the threshold:
    {
      motor[motorC] = 0;                        // Motor C is stopped with a power level of 0.
    }
  }
}


task main()
{



}
