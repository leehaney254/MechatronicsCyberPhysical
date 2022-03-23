#include "motorDriver.h"
//motor one
  int enableA = PB8;
  int forwardA = PB10;
  int reverseA = PB11;
  //motor two
  int enableB;
  int forwardB;
  int reverseB;

void Motor::motor_init()
{
  pinMode(enableA, OUTPUT);
  pinMode(forwardA, OUTPUT);
  pinMode(reverseA, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(forwardB, OUTPUT);
  pinMode(reverseB, OUTPUT);
}

void Motor::drive_motorA(int pwm, int directions)
{
  if(directions == 1)
  {
    digitalWrite(forwardA, 1);
    analogWrite(enableA, pwm);
  }
  else if(directions == 2)
  {
    digitalWrite(reverseA, 1);
    analogWrite(enableA, pwm);
  }
  else
  {
    analogWrite(enableA, 0);
  }
}

void Motor::drive_motorB(int pwm, int directions)
{
  if(directions == 1)
  {
    digitalWrite(forwardB, 1);
    analogWrite(enableB, pwm);
  }
  else if(directions == 2)
  {
    digitalWrite(reverseB, 1);
    analogWrite(enableB, pwm);
  }
  else
  {
    analogWrite(enableB, 0);
  }
}

void Motor::driving_motor(int pwm, int directions)
{
  if(directions == 1)
  {
    analogWrite(enableA, pwm);
  }
  else if(directions == 2)
  {
    analogWrite(enableB, pwm);
  }
  else
  {
    analogWrite(enableA, pwm);
    analogWrite(enableB, pwm);
  }
}
void Motor::accelerate_upwards(int motor, int directions, int delays)
{
    if(motor == 1)
    {
      if(directions == 1)
    {
      digitalWrite(forwardA,1);
    }
    else if(directions == 2)
    {
      digitalWrite(reverseA, 1);
    }
    else
    {
      digitalWrite(reverseA, 1);
      digitalWrite(forwardA, 1);
    }
    for(int i=0; i<256; i++)
    {
      analogWrite(enableA, i);
      Serial.println(i);
      delay(delays);
    }
  }
    if(motor == 2)
    {
      if(directions == 1)
    {
      digitalWrite(forwardB,1);
    }
    else if(directions == 2)
    {
      digitalWrite(reverseB, 1);
    }
    else
    {
      digitalWrite(reverseB, 1);
      digitalWrite(forwardB, 1);
    }
    for(int i=0; i<256; i++)
    {
      analogWrite(enableB, i);
      delay(delays);
    }
  }
}

void Motor::decelerate_downwards(int motor, int directions, int delays)
{
  if(motor == 1)
    {
      if(directions == 1)
    {
      digitalWrite(forwardA,1);
    }
    else if(directions == 2)
    {
      digitalWrite(reverseA, 1);
    }
    else
    {
      digitalWrite(reverseA, 1);
      digitalWrite(forwardA, 1);
    }
        
    for(int i=255; i>=0; i--)
    {
      analogWrite(enableA, i);
      Serial.println(i);
      delay(delays);
    }
  }
  if(motor == 2)
  {
    if(directions == 1)
    {
      digitalWrite(forwardB,1);
    }
    else if(directions == 2)
    {
      digitalWrite(reverseB, 1);
    }
    else
    {
      digitalWrite(reverseB, 1);
      digitalWrite(forwardB, 1);
    }
    for(int i=255; i>=0; i--)
    {
      analogWrite(enableB, i);
      delay(delays);
    }
  }
}
