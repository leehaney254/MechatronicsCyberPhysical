#ifndef _MOTORDRIVER_H_
#define _MOTORDRIVER_H_

#include <arduino.h>
class Motor
{
  private:
  

  public:
  void motor_init(void);
  void drive_motorA(int pwm, int directions);
  void drive_motorB(int pwm, int directions);
  void driving_motor(int pwm, int directions);
  void accelerate_upwards(int motor, int directions, int delays);
  void decelerate_downwards(int motor, int directions, int delays);
  Motor(){};
  ~Motor(){};
};



#endif
