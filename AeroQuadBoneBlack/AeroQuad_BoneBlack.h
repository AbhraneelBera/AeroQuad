#ifndef AEROQUAD_BONE_BLACK_H
#define AEROQUAD_BONE_BLACK_H

#define ADC_NUMBER_OF_BITS	12

// Serial declaration
# define SERIAL_USES_USB
HardwareSerial SerialUSB("/dev/ttyGS0");

// Receiver Declaration
#if defined (ReceiverPPM) || defined (ReceiverHWPPM)
  #undef ReceiverPPM
  #undef ReceiverHWPPM
  #define RECEIVER_BONE_BLACK_PPM
#elif defined (ReceiverSBUS)
  
#else
  #define RECEIVER_BONE_BLACK
#endif

// Motor declaration
#define MOTOR_BONE_BLACK

// LED declaration
#define LED_Green  P9_12
#define LED_Red    P9_15
#define LED_Yellow P9_23

// Analog pin declaration
#define BATT_ANALOG_INPUT	AIN0
#define A1       AIN1
#define A2       AIN2
#define A3       AIN3
#define A4       AIN4
#define A5       AIN5
#define A6       AIN6

// external LED drivers
#define PLED1 P8_14
#define PLED2 P8_17
#define PLED3 P8_18
#define PLED4 P8_26

#include <Device_I2C.h>

#include <Gyroscope_L3G4200D.h>
#include <Accelerometer_ADXL345.h>

// heading mag hold declaration
#ifdef HeadingMagHold
  #include <Compass.h>
  #define SPARKFUN_5883L_BOB
#endif

// Altitude declaration
#ifdef AltitudeHoldBaro
  #define BMP085
#endif

#ifdef AltitudeHoldRangeFinder
  #define XLMAXSONAR
#endif

#ifdef OSD
  #define MAX7456_OSD
#endif

// Camera Control declaration
#ifdef CameraControl
  #define CameraControl_BoneBlack
#endif

void initPlatform()
{
  pinMode(LED_Green, OUTPUT);
  for(byte ledloop=0; ledloop<10; ledloop++)
  {
    digitalWrite(LED_Green, ledloop & 1);
    delay(50);
  }

  pinMode(LED_Red, OUTPUT);
  digitalWrite(LED_Red, LOW);
  pinMode(LED_Yellow, OUTPUT);
  digitalWrite(LED_Yellow, LOW);

  pinMode(PLED1, OUTPUT);
  pinMode(PLED2, OUTPUT);
  pinMode(PLED3, OUTPUT);
  pinMode(PLED4, OUTPUT);

  // I2C setup
  Wire.begin();
}

// called when eeprom is initialized
void initializePlatformSpecificAccelCalibration()
{
  // Kenny default value, a real accel calibration is strongly recommended
  accelScaleFactor[XAXIS] = 0.0371299982;
  accelScaleFactor[YAXIS] = -0.0374319982;
  accelScaleFactor[ZAXIS] = -0.0385979986;
  #ifdef HeadingMagHold
    magBias[XAXIS]  = 60.000000;
    magBias[YAXIS]  = -39.000000;
    magBias[ZAXIS]  = -7.500000;
  #endif

}

unsigned long previousMeasureCriticalSensorsTime = 0;
void measureCriticalSensors()
{
  // read sensors not faster than every 1 ms
  if (currentTime - previousMeasureCriticalSensorsTime >= 1000)
  {
    measureGyroSum();
    measureAccelSum();
    previousMeasureCriticalSensorsTime = currentTime;
  }
}

#endif
