/*----------------------------------------------------------------------------
                                                                            
      Module:       CompForReal_v2                                                  
      Author:       Middleton VEX Robotics                                    
      Created:      Thu Sep 26 2019                                           
      Description:  Competition Code                                          
      LastEditDate: Fri Nov 29 2019       
      v2 with flipped joysticks (Not NFS)                              
                                                                            
----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
   ---- START VEXCODE CONFIGURED DEVICES ----
   Robot Configuration:
   [Name]               [Type]        [Port(s)]
   LeftMotor            motor         19              
   RightMotor           motor         3               
   CubeAngleMotor       motor         10              
   CubeAngleMotor2      motor         14              
   LeftLiftMotor        motor         2               
   RightLiftMotor       motor         4               
   LeftIntakeMotor      motor         11              
   RightIntakeMotor     motor         20              
   Controller1          controller                    
   ---- END VEXCODE CONFIGURED DEVICES ----
----------------------------------------------------------------------------*/
#include "vex.h"
using namespace vex;

competition Competition;
int driveFunction()
{
  int leftMotorSpeed = 0, rightMotorSpeed = 0;
  while(1)
  {
    leftMotorSpeed = Controller1.Axis2.position() + Controller1.Axis4.position();
    rightMotorSpeed = Controller1.Axis2.position() - Controller1.Axis4.position();
    LeftMotor.spin(fwd,leftMotorSpeed, pct);
    RightMotor.spin(fwd, rightMotorSpeed, pct);   
    vex::task::sleep(15);
  }
  return 0;
}
// define your global instances of motors and other devices here
/*---------------------------------------------------------------------------
                            Pre-Autonomous Functions                         
                                                                           
    You may want to perform some actions before the competition starts.      
    Do them in the following function.  You must return from this function   
    or the autonomous and usercontrol tasks will not be started.  This       
    function is only called once after the V5 has been powered on and        
    not every time that the robot is disabled.                               
---------------------------------------------------------------------------*/
void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // define your global instances of motors and other devices here
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}
/*---------------------------------------------------------------------------
                                                                           
                                Autonomous Task                              
                                                                           
    This task is used to control your robot during the autonomous phase of   
    a VEX Competition.                                                       
                                                                           
    You must modify the code to add your own robot specific commands here.   
---------------------------------------------------------------------------*/
void autonomous(void) {
 vex::task::sleep(10);

 //Go forwards 6.2 ft
   
 LeftMotor.setVelocity(70, pct);
 RightMotor.setVelocity(70, pct);
 LeftMotor.rotateFor(-514, deg, false);
 RightMotor.rotateFor(-514, deg);// Lift up 

 LeftMotor.setVelocity(70, pct);
 RightMotor.setVelocity(70, pct);
 LeftMotor.rotateFor(1000, deg, false);
 RightMotor.rotateFor(1000, deg);// Lift up 
/*
---------------------------------------------------------------------------
                             User Control Task                             |
                                                                           |
  This task is used to control your robot during the user control phase of |
  a VEX Competition.                                                       | 
 You must modify the code to add your own robot specific commands here.    |
---------------------------------------------------------------------------*/
}
void usercontrol(void) 
{
  // User control code here, inside the loop
  int liftSpeedPCT = 100,intakeSpeedPCT = 100,outtakeSpeedPCT = 25;
  while(1) 
  { 
    task driving = task(driveFunction);
    if(Controller1.ButtonUp.pressing()) 
    {
      CubeAngleMotor.spin(fwd, 100, pct);
      CubeAngleMotor2.spin(fwd, 100, pct);
    }
    else if(Controller1.ButtonDown.pressing()) 
    {
    CubeAngleMotor.spin(reverse, 100, pct);
    CubeAngleMotor2.spin(reverse, 100, pct);
    }
    else 
    {
      CubeAngleMotor.stop();
      CubeAngleMotor2.stop();
    }
    //Lift Section
    LeftLiftMotor.setVelocity(liftSpeedPCT, pct);
    RightLiftMotor.setVelocity(liftSpeedPCT, pct);
 
    if(Controller1.ButtonR1.pressing())
    {
      LeftLiftMotor.spin(fwd);
      RightLiftMotor.spin(fwd);
    }
    else if (Controller1.ButtonR2.pressing())
    {
      LeftLiftMotor.spin(reverse);
      RightLiftMotor.spin(reverse);
    }
    else
    {
      LeftLiftMotor.stop();
      RightLiftMotor.stop();
    }
    // Intake Section
    if(Controller1.ButtonL1.pressing())
    {
      LeftIntakeMotor.spin(reverse, outtakeSpeedPCT, pct);
      RightIntakeMotor.spin(fwd, outtakeSpeedPCT, pct);
    }
    else if (Controller1.ButtonL2.pressing())
    {
      LeftIntakeMotor.spin(fwd, intakeSpeedPCT, pct);
      RightIntakeMotor.spin(reverse, intakeSpeedPCT, pct);
    }
    else
    {
      LeftIntakeMotor.stop();
      RightIntakeMotor.stop();
    }
    vex::task::sleep(10); 
  }
}
int main(){
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  // Prevent main from exiting with an infinite loop.
  while (1) {wait(100, msec);}
}