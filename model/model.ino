/*The motor starts to rotate at a pwm of 170 on acceleration
 * and stops at a pwm of 100 on decelaration
 */
#include "motorDriver.h"

Motor motor;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motor.motor_init();
}

void loop() {
  // put your main code here, to run repeatedly:
  motor.accelerate_upwards(1, 1, 100);
  motor.decelerate_downwards(1, 1, 100);
}
