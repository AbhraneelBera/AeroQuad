
#ifndef RECEIVER_BONE_BLACK_H
#define RECEIVER_BONE_BLACK_H

#if defined(AeroQuadBoneBlack)

#include "Receiver.h"

#define RECEIVER_PIN0 P9_42
#define RECEIVER_PIN1 P9_41
#define RECEIVER_PIN2 P9_31
#define RECEIVER_PIN3 P9_30
#define RECEIVER_PIN4 P9_29
#define RECEIVER_PIN5 P9_28
#define RECEIVER_PIN6 P9_27
#define RECEIVER_PIN7 P9_25
#define RECEIVER_PIN8 P8_16
#define RECEIVER_PIN9 P8_15

void initializeReceiver(int nbChannel = 6)
{
  initializeReceiverParam(nbChannel);
}
  
int getRawChannelValue(byte channel)
{
  switch(channel)
  {
    case 0: return(getPulseWidth(RECEIVER_PIN0));
    case 1: return(getPulseWidth(RECEIVER_PIN1));
    case 2: return(getPulseWidth(RECEIVER_PIN2));
    case 3: return(getPulseWidth(RECEIVER_PIN3));
    case 4: return(getPulseWidth(RECEIVER_PIN4));
    case 5: return(getPulseWidth(RECEIVER_PIN5));
    case 6: return(getPulseWidth(RECEIVER_PIN6));
    case 7: return(getPulseWidth(RECEIVER_PIN7));
    case 8: return(getPulseWidth(RECEIVER_PIN8));
    case 9: return(getPulseWidth(RECEIVER_PIN9));
  }
  return 0;
}

#endif

#endif