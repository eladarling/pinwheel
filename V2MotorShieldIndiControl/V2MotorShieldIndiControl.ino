#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

int lspeed = 0;
int rspeed = 0;

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *rightMotor = AFMS.getMotor(1);
Adafruit_DCMotor *leftMotor = AFMS.getMotor(2);


void setup() {
  Serial.begin(9600);
  Serial.println("Lets Go!");
  AFMS.begin();
}

void ReadCommandFromSerial()
{
  char spin = Serial.read();
  switch (spin)
  {
    case '0':
    {  
      rspeed = 0;
      lspeed = 0;
      rightMotor->run(RELEASE);
      leftMotor->run(RELEASE);
      Serial.println ("hold yer horses, cowboy!");
      Serial.println ("stopped");
    }
      break;
    case '1':
    {
      rspeed = rspeed + 20;
      if (rspeed > 240)
        rspeed = 240;
      rightMotor->run(FORWARD);
      rightMotor->setSpeed(rspeed);
      Serial.println ("right yeehaw!");
      Serial.println (rspeed);
    }  
      break;
    case '2':
    {
      lspeed = lspeed + 20;
      if (lspeed > 240)
        lspeed = 240;
      leftMotor->run(FORWARD);
      leftMotor->setSpeed(lspeed);
      Serial.println ("left yeehaw!");
      Serial.println (lspeed);
    }  
      break;
    case '3':
    {
      rspeed = rspeed - 20;
        if (rspeed < 0)
        rspeed = 0;
      rightMotor->run(FORWARD);
      rightMotor->setSpeed(rspeed);
      Serial.println ("right whoa there!");
      Serial.println (rspeed);
    }  
      break;
    case '4':
    {  
      lspeed = lspeed - 20;
        if (lspeed < 0)
        lspeed = 0;
      leftMotor->run(FORWARD);
      leftMotor->setSpeed(lspeed); 
      Serial.println ("left whoa there!");
      Serial.println (lspeed);
    }  
      break;
   }
}
void loop() 
{
  ReadCommandFromSerial();
}
