/* This example drives each motor connected to the A-Star
32U4 Robot Controller forward, then backward.  The yellow
user LED is on when a motor is set to a positive speed and
off when a motor is set to a negative speed. */

#include <AStar32U4.h>

AStar32U4Motors motors;

void setup()
{
  // Uncomment to flip a motor's direction:
  //motors.flipM1(true);
  //motors.flipM2(true);
}

void loop()
{
  // Run motor 1 forward.
  ledYellow(1);
  for (int speed = 0; speed <= 400; speed++)
  {
    motors.setM1Speed(speed);
    delay(2);
  }
  for (int speed = 400; speed >= 0; speed--)
  {
    motors.setM1Speed(speed);
    delay(2);
  }

  // Run motor 1 backward.
  ledYellow(0);
  for (int speed = 0; speed >= -400; speed--)
  {
    motors.setM1Speed(speed);
    delay(2);
  }
  for (int speed = -400; speed <= 0; speed++)
  {
    motors.setM1Speed(speed);
    delay(2);
  }

  // Run motor 2 forward.
  ledYellow(1);
  for (int speed = 0; speed <= 400; speed++)
  {
    motors.setM2Speed(speed);
    delay(2);
  }
  for (int speed = 400; speed >= 0; speed--)
  {
    motors.setM2Speed(speed);
    delay(2);
  }

  // Run motor 2 backward.
  ledYellow(0);
  for (int speed = 0; speed >= -400; speed--)
  {
    motors.setM2Speed(speed);
    delay(2);
  }
  for (int speed = -400; speed <= 0; speed++)
  {
    motors.setM2Speed(speed);
    delay(2);
  }

  delay(500);
}
