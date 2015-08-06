
#ifndef CAMERA_STABILIZER_BONE_BLACK_H
#define CAMERA_STABILIZER_BONE_BLACK_H

#if defined(AeroQuadBoneBlack)

#include "CameraStabilizer.h"

#define SERVOPIN0 P8_30  // Pitch
#define SERVOPIN1 P8_30  // Roll
#define SERVOPIN2 P8_30  // Yaw

void initializeCameraControl()
{
  cameraControlMove(1500,1500,1500);
}

void cameraControlMove(int servoPitch, int servoRoll, int servoYaw)
{
  setPulseWidth(SERVOPIN0, servoPitch);
  setPulseWidth(SERVOPIN1, servoRoll);
  setPulseWidth(SERVOPIN2, servoYaw);
}

#endif

#endif