/*
  Stage.h - Library for controlling the stage on the OpenLabTools microscope
  Written by James Ritchie for OpenLabTools
  github.com/OpenLabTools/Microscope
*/
#include "Arduino.h"
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <AccelStepper.h>

#ifndef Stage_h
#define Stage_h

//Define pins
#define Z_UP_SWITCH 7
#define Z_DOWN_SWITCH 6
#define Z_ULIMIT_SWITCH 5
#define Z_LLIMIT_SWITCH 4
#define ROTARY_ENCODER_A 8
#define ROTARY_ENCODER_B 9
#define ROTARY_ENCODER_SWITCH 10

//Define motor selections
#define X_STEPPER 0
#define Y_STEPPER 1
#define Z_STEPPER 2

class Stage
{
  public:
    boolean manual_control;
    boolean calibrated;
      
    Stage();
    
    void begin();
    void loop();
    void manualControl();
    
    void calibrate();
    
    long getPosition(int stepper);
    long getDistanceToGo(int stepper);
    long getLength(int stepper);
    
    void Move(int stepper, long steps);
    void MoveTo(int stepper,long position);
    
    
    
  private:
  
    long _x_pos;
    long _y_pos;
    long _z_pos;
  
    long _x_length;
    long _y_length;
    long _z_length;
    
    long _x_target;
    long _z_target;
    long _y_target;
    
    long _z_last_step;
    long _xy_last_step;
    
    long _z_interval;
    long _xy_interval;
  
};
  
#endif

