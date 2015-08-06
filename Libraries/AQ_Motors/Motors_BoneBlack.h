
#ifndef MOTORS_BONE_BLACK_H
#define MOTORS_BONE_BLACK_H

#include "Motors.h"

#if defined(AeroQuadBoneBlack)

  #define MOTORPIN0    P8_46
  #define MOTORPIN1    P8_45
  #define MOTORPIN2    P8_44
  #define MOTORPIN3    P8_43
  #define MOTORPIN4    P8_42
  #define MOTORPIN5    P8_41
  #define MOTORPIN6    P8_40
  #define MOTORPIN7    P8_39

void initializeMotors(NB_Motors numbers)
{
  numberOfMotors = numbers;

  // Set PWM time period to 2040 microseconds, approx. 490Hz.
  setTimePeriod(MOTORPIN0, 2040);
  setTimePeriod(MOTORPIN1, 2040);
  setTimePeriod(MOTORPIN2, 2040);
  setTimePeriod(MOTORPIN3, 2040);
  if (numberOfMotors == SIX_Motors || numberOfMotors == EIGHT_Motors)
  {
    setTimePeriod(MOTORPIN4, 2040);
    setTimePeriod(MOTORPIN5, 2040);
    if (numberOfMotors == EIGHT_Motors)
    {
      setTimePeriod(MOTORPIN6, 2040);
      setTimePeriod(MOTORPIN7, 2040);
    }
  }

  commandAllMotors(1000);
}

void writeMotors()
{
  setPulseWidth(MOTORPIN0, motorCommand[MOTOR1]);
  setPulseWidth(MOTORPIN1, motorCommand[MOTOR2]);
  setPulseWidth(MOTORPIN2, motorCommand[MOTOR3]);
  setPulseWidth(MOTORPIN3, motorCommand[MOTOR4]);
  if (numberOfMotors == SIX_Motors || numberOfMotors == EIGHT_Motors)
  { 
    setPulseWidth(MOTORPIN4, motorCommand[MOTOR5]);
    setPulseWidth(MOTORPIN5, motorCommand[MOTOR6]);
    if (numberOfMotors == EIGHT_Motors)
    {
      setPulseWidth(MOTORPIN6, motorCommand[MOTOR7]);
      setPulseWidth(MOTORPIN7, motorCommand[MOTOR8]);
    }
  }
}

void commandAllMotors(int command)
{
  setPulseWidth(MOTORPIN0, command);
  setPulseWidth(MOTORPIN1, command);
  setPulseWidth(MOTORPIN2, command);
  setPulseWidth(MOTORPIN3, command);
  if (numberOfMotors == SIX_Motors || numberOfMotors == EIGHT_Motors)
  { 
    setPulseWidth(MOTORPIN4, command);
    setPulseWidth(MOTORPIN5, command);
    if (numberOfMotors == EIGHT_Motors)
    {
      setPulseWidth(MOTORPIN6, command);
      setPulseWidth(MOTORPIN7, command);
    }
  }
}

#endif

#endif