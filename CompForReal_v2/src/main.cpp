/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Middleton VEX Robotics                                    */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Code                                          */
/*    LastEditDate: Sat Nov 9 2019                                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftMotor            motor         12              
// RightMotor           motor         19              
// StrafeMotor          motor         15              
// CubeAngleMotor       motor         2               
// LeftLiftMotor        motor         1               
// RightLiftMotor       motor         21              
// LeftIntakeMotor      motor         11              
// RightIntakeMotor     motor         20              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
 int deadzone = 20;
// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  // define your global instances of motors and other devices here


  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
 
  vex::motor lm = vex::motor(vex::PORT19);
  vex::motor rm = vex::motor(vex::PORT3, true);
  vex::motor angler = vex::motor(vex::PORT10);
  vex::motor angler2 = vex::motor(vex::PORT14, true);
  vex::gyro gscope = vex::gyro(Brain.ThreeWirePort.B);
  vex::motor in1 = vex::motor(vex::PORT12);
  vex::motor in2 = vex::motor(vex::PORT20);
  vex::motor liftl = vex::motor(vex::PORT2);
  vex::motor liftr = vex::motor(vex::PORT4, true);
  
 //Push out intakes
 Brain.Screen.print("Fold Out");
 Brain.Screen.newLine();
 angler.setVelocity(40, vex::velocityUnits::pct);
 angler2.setVelocity(40, vex::velocityUnits::pct);
 angler.rotateFor(288, vex::rotationUnits::deg, false);
 angler2.rotateFor(288, vex::rotationUnits::deg);
 vex::task::sleep(50);
 angler.rotateFor(-288, vex::rotationUnits::deg, false);
 angler2.rotateFor(-288, vex::rotationUnits::deg);
 vex::task::sleep(50);

 //Forwards 3' while intaking
 Brain.Screen.print("FWD");
 Brain.Screen.newLine();
 lm.setVelocity(40, vex::velocityUnits::pct);
 rm.setVelocity(40, vex::velocityUnits::pct);
 in1.setVelocity(80, vex::velocityUnits::pct);
 in2.setVelocity(80, vex::velocityUnits::pct);
 in1.spin(fwd);
 in2.spin(fwd);
 lm.rotateFor(1029, vex::rotationUnits::deg, false);
 rm.rotateFor(1029, vex::rotationUnits::deg);
 in1.stop();
 in2.stop();
 vex::task::sleep(500);

 //Backwards 1.5'
 Brain.Screen.print("BKWD");
 Brain.Screen.newLine();
 lm.setVelocity(30, vex::velocityUnits::pct);
 rm.setVelocity(30, vex::velocityUnits::pct);
 lm.rotateFor(-515, vex::rotationUnits::deg, false);
 rm.rotateFor(-515, vex::rotationUnits::deg);
 vex::task::sleep(50);

 //turn 135 deg right
 Brain.Screen.print("right");
 Brain.Screen.newLine();
 lm.rotateFor(474, vex::rotationUnits::deg, false);
 rm.rotateFor(-474, vex::rotationUnits::deg);
 vex::task::sleep(50);

 //Forwards 1 ft fast, then .414 ft slow
 Brain.Screen.print("FWD");
 Brain.Screen.newLine();
 lm.setVelocity(40, vex::velocityUnits::pct);
 rm.setVelocity(40, vex::velocityUnits::pct);
 lm.rotateFor(343, vex::rotationUnits::deg, false);
 rm.rotateFor(343, vex::rotationUnits::deg);
 //Heres the slow part, yippee
 lm.setVelocity(20, vex::velocityUnits::pct);
 rm.setVelocity(20, vex::velocityUnits::pct);
 lm.rotateFor(85, vex::rotationUnits::deg, false);
 rm.rotateFor(85, vex::rotationUnits::deg);
 vex::task::sleep(50);

 //Forward the cube angler
 Brain.Screen.print("Angle");
 Brain.Screen.newLine();
 angler.setVelocity(20, vex::velocityUnits::pct);
 angler2.setVelocity(20, vex::velocityUnits::pct);
 angler.rotateFor(240, vex::rotationUnits::deg, false);
 angler2.rotateFor(240, vex::rotationUnits::deg);
 vex::task::sleep(50);

 //Backwards 1' and outake
 Brain.Screen.print("REV");
 in1.setVelocity(20, vex::velocityUnits::pct);
 in2.setVelocity(20, vex::velocityUnits::pct);
 in1.spin(reverse);
 in2.spin(reverse);
 lm.rotateFor(-343, vex::rotationUnits::deg, false);
 rm.rotateFor(-343, vex::rotationUnits::deg);
 in1.stop();
 in2.stop();

 /*
 First try went well- worked for the most part with some minor adjustments needed:
  -Change the 135 deg turn so it is about 30 deg less to actually become a 135 deg turn
  -The initial move forwards needed to be extended for another half foot (and make the respective backwards move back another half foot as well)
  -Change the angler degrees so that it doesnt extend so much

 Second attempt- just as useful. Needed adjustments:
  -Stop intaking right after getting all cubes
  -When heading backwards, go at lesser speed
  -Lessen the angler yet again
  -Dont stop so abrubtly before stacking the cubes
  -When Moving forwards to stack, lessen it by 2"
 */
 
 /*
 vex::task::sleep(100);

 //Go forwards 6.2 ft
 Brain.Screen.print("forwards");
 Brain.Screen.newLine();
  vex::motor lm = vex::motor(vex::PORT19);
  vex::motor rm = vex::motor(vex::PORT3, true);
  vex::motor angler = vex::motor(vex::PORT10);
  vex::motor angler2 = vex::motor(vex::PORT14, true);
  vex::gyro gscope = vex::gyro(Brain.ThreeWirePort.B);
  vex::motor in1 = vex::motor(vex::PORT12);
  vex::motor in2 = vex::motor(vex::PORT20);
  vex::motor liftl = vex::motor(vex::PORT2);
  vex::motor liftr = vex::motor(vex::PORT4, true);
   
 lm.setVelocity(70, vex::velocityUnits::pct);
 rm.setVelocity(70, vex::velocityUnits::pct);
 lm.rotateFor(-514, vex::rotationUnits::deg, false);
 rm.rotateFor(-514, vex::rotationUnits::deg);// Lift up 

 
 lm.setVelocity(70, vex::velocityUnits::pct);
 rm.setVelocity(70, vex::velocityUnits::pct);
 lm.rotateFor(1000, vex::rotationUnits::deg, false);
 rm.rotateFor(1000, vex::rotationUnits::deg);// Lift up 
*/
/*liftl.setVelocity(100, vex::velocityUnits::pct);
 liftr.setVelocity(100, vex::velocityUnits::pct);
 liftl.rotateFor(45, vex::rotationUnits::deg, false);
 liftr.rotateFor(45, vex::rotationUnits::deg);
 vex::task::sleep(50);

//Lift down
 liftl.rotateFor(-45, vex::rotationUnits::deg, false);
 liftr.rotateFor(-45, vex::rotationUnits::deg);

vex::task::sleep(50);
 lm.setVelocity(70, vex::velocityUnits::pct);
 rm.setVelocity(70, vex::velocityUnits::pct);
 lm.rotateFor(2126, vex::rotationUnits::deg, false);
 rm.rotateFor(2126, vex::rotationUnits::deg);
 vex::task::sleep(50);
 
//turn 90 deg left
 Brain.Screen.print("left");
 Brain.Screen.newLine();
 lm.setVelocity(50, vex::velocityUnits::pct);
 rm.setVelocity(50, vex::velocityUnits::pct);
 lm.rotateFor(-359, vex::rotationUnits::deg, false);
 rm.rotateFor(359, vex::rotationUnits::deg);
 vex::task::sleep(50);
 
//Set move velocities to 70, intake to 100
 lm.setVelocity(70, vex::velocityUnits::pct);
 rm.setVelocity(70, vex::velocityUnits::pct);
 in1.setVelocity(100, vex::velocityUnits::pct);
 in2.setVelocity(100, vex::velocityUnits::pct);
 
//forwards 2.1 ft (720 degrees) and intake
 Brain.Screen.print("forwards");
 Brain.Screen.newLine();
 in1.spin(fwd);
 in2.spin(reverse);
 lm.rotateFor(720, vex::rotationUnits::deg, false);
 rm.rotateFor(720, vex::rotationUnits::deg);
 in1.stop();
 in2.stop();
 vex::task::sleep(50);
 
//back up 5 in (143 in)
 Brain.Screen.print("backwards");
 Brain.Screen.newLine();
 lm.rotateFor(-143, vex::rotationUnits::deg, false);
 rm.rotateFor(-143, vex::rotationUnits::deg);
 vex::task::sleep(50);
 
//turn 135 right
 Brain.Screen.print("right");
 Brain.Screen.newLine();
 lm.setVelocity(50, vex::velocityUnits::pct);
 rm.setVelocity(50, vex::velocityUnits::pct);
 lm.rotateFor(539, vex::rotationUnits::deg, false);
 rm.rotateFor(-539, vex::rotationUnits::deg);
 vex::task::sleep(50);
 
//forwards 1.4ft (485 deg)
 Brain.Screen.print("final push");
 Brain.Screen.newLine();
 lm.setVelocity(70, vex::velocityUnits::pct);
 rm.setVelocity(70, vex::velocityUnits::pct);
 lm.rotateFor(485, vex::rotationUnits::deg, false);
 rm.rotateFor(485, vex::rotationUnits::deg);
 vex::task::sleep(50);

//raise block holder
 Brain.Screen.print("angler");
 Brain.Screen.newLine();
 angler.setVelocity(25, vex::velocityUnits::pct);
 angler.rotateFor(288, vex::rotationUnits::deg);

//Back half a foot and outake
 Brain.Screen.print("Back and stuff");
 Brain.Screen.newLine();
 lm.setVelocity(50, vex::velocityUnits::pct);
 rm.setVelocity(50, vex::velocityUnits::pct);
 in1.spin(reverse);
 in2.spin(forward);
 lm.rotateFor(-343, vex::rotationUnits::deg, false);
 rm.rotateFor(-343, vex::rotationUnits::deg);
 in1.stop();
 in2.stop();
}

---------------------------------------------------------------------------
                                                                           |
                             User Control Task                             |
                                                                           |
  This task is used to control your robot during the user control phase of |
  a VEX Competition.                                                       |
                                                                           |
 You must modify the code to add your own robot specific commands here.    |
---------------------------------------------------------------------------*/
}
void usercontrol(void) 
{
  // User control code here, inside the loop

  vex::motor LeftMotor = vex::motor(vex::PORT19);
  vex::motor RightMotor = vex::motor(vex::PORT3, true);
  vex::motor CubeAngleMotor = vex::motor(vex::PORT10);
  vex::motor CubeAngleMotor2 = vex::motor(vex::PORT14, true); 
  vex::motor LeftLiftMotor = vex::motor(vex::PORT2);
  vex::motor RightLiftMotor = vex::motor(vex::PORT4, true); 
  vex::motor LeftIntakeMotor = vex::motor(vex::PORT11);
  vex::motor RightIntakeMotor = vex::motor(vex::PORT20);

  vex::controller Controller1 (vex::controllerType::primary); //(vex::controllerType::primary) (vex::controllerType::partner)
  vex::controller Controller2 (vex::controllerType::partner); 
  int cubeAngleSpeedPCT = 100;
  int liftSpeedPCT = 100;
  int intakeSpeedPCT = 100;
  int outtakeSpeedPCT = 25;

  int forward_backward(void);
  int turning(void);
  
  while(1) 
  { 
    // Drivetrain Section (Arcade Style)
    //Axis 2 (right joystick horizontal acis) of the controller makes the robot moves forward or backward and Ax
    vex::task t(forward_backward);   
    vex::task t2(turning);
       // Cube Angle Section
       
       if (Controller1.ButtonA.pressing())
       {
          cubeAngleSpeedPCT = 100;
          CubeAngleMotor.setVelocity(cubeAngleSpeedPCT, vex::percentUnits::pct);
          CubeAngleMotor2.setVelocity(cubeAngleSpeedPCT, vex::percentUnits::pct);
          CubeAngleMotor.spin(vex::directionType::fwd);
          CubeAngleMotor2.spin(vex::directionType::fwd);
       }

       if(Controller1.ButtonDown.pressing())
       {
          cubeAngleSpeedPCT = 25;
          CubeAngleMotor.setVelocity(cubeAngleSpeedPCT, vex::percentUnits::pct);
          CubeAngleMotor2.setVelocity(cubeAngleSpeedPCT, vex::percentUnits::pct);
         CubeAngleMotor.spin(vex::directionType::fwd);
         CubeAngleMotor2.spin(vex::directionType::fwd);
       }
       else if (Controller1.ButtonUp.pressing())
       {
        cubeAngleSpeedPCT = 25;
        CubeAngleMotor.setVelocity(cubeAngleSpeedPCT, vex::percentUnits::pct);
        CubeAngleMotor2.setVelocity(cubeAngleSpeedPCT, vex::percentUnits::pct);
         CubeAngleMotor.spin(vex::directionType::rev);
         CubeAngleMotor2.spin(vex::directionType::rev);
       }
       /*
       else if (Controller1.ButtonUp.pressing())
       {
         CubeAngleMotor.setVelocity(100, vex::percentUnits::pct);
         CubeAngleMotor2.setVelocity(100, vex::percentUnits::pct);
         CubeAngleMotor.spin(vex::directionType::fwd);
         CubeAngleMotor2.spin(vex::directionType::fwd);
       }
       else if (Controller1.ButtonDown.pressing()
       {
         CubeAngleMotor.setVelocity(100, vex::percentUnits::pct);
         CubeAngleMotor2.setVelocity(100, vex::percentUnits::pct);
         CubeAngleMotor.spin(vex::directionType::rev);
         CubeAngleMotor2.spin(vex::directionType::rev);
       }
       */
       else
       {
         CubeAngleMotor.stop();
         CubeAngleMotor2.stop();
       }

 
       //Lift Section
       LeftLiftMotor.setVelocity(liftSpeedPCT, vex::percentUnits::pct);
       RightLiftMotor.setVelocity(liftSpeedPCT, vex::percentUnits::pct);
 
       if(Controller2.ButtonR1.pressing())
       {
         LeftLiftMotor.spin(vex::directionType::fwd);
         RightLiftMotor.spin(vex::directionType::fwd);
       }
       else if (Controller2.ButtonR2.pressing())
       {
         LeftLiftMotor.spin(vex::directionType::rev);
         RightLiftMotor.spin(vex::directionType::rev);
       }
       else
       {
         LeftLiftMotor.stop();
         RightLiftMotor.stop();
       }
       // Intake Section
 
       if(Controller2.ButtonL1.pressing())
       {
         LeftIntakeMotor.setVelocity(outtakeSpeedPCT, vex::percentUnits::pct);
         RightIntakeMotor.setVelocity(outtakeSpeedPCT, vex::percentUnits::pct);
         LeftIntakeMotor.spin(vex::directionType::rev);
         RightIntakeMotor.spin(vex::directionType::fwd);
       }
       else if (Controller2.ButtonL2.pressing())
       {
         LeftIntakeMotor.setVelocity(intakeSpeedPCT, vex::percentUnits::pct);
         RightIntakeMotor.setVelocity(intakeSpeedPCT, vex::percentUnits::pct);         
         LeftIntakeMotor.spin(vex::directionType::fwd);
         RightIntakeMotor.spin(vex::directionType::rev);
       }
       else
       {
         LeftIntakeMotor.stop();
         RightIntakeMotor.stop();
       }
       vex::task::sleep(10); 
       
       /* Combined Functions
       if(Controller1.ButtonA.pressing())
       {
         LeftIntakeMotor.spin(vex::directionType::fwd);
         RightIntakeMotor.spin(vex::directionType::rev);
         LeftMotor.spin(vex::directionType::fwd, 50, vex::percentUnits::pct);
         RightMotor.spin(vex::directionType::fwd, 50, vex::percentUnits::pct);
       }
       else
       {
         LeftIntakeMotor.stop();
         RightIntakeMotor.stop();
         LeftMotor.stop();
         RightMotor.stop();
       }
       */
  }
}
int main(){
  
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}

int turning()
{
  while(1)
  {
    if(abs(Controller1.Axis1.position()) > deadzone)
       {
         LeftMotor.spin(vex::directionType::fwd, Controller1.Axis1.position()/3, vex::percentUnits::pct);
         RightMotor.spin(vex::directionType::rev, Controller1.Axis1.position()/3, vex::percentUnits::pct);
         //StrafeMotor.spin(vex::directionType::fwd, Controller.Axis4.position()/3, vex::percentUnits::pct);
       }
       else
       {
         LeftMotor.stop();
         RightMotor.stop();
       }
    vex::task::sleep(25);
  }
  return (0);
}
int forward_backward()
{
  while(1)
  {
    if(abs(Controller1.Axis3.position()) > deadzone || abs(Controller1.Axis4.position()) > deadzone )
    {
      LeftMotor.spin(vex::directionType::fwd, Controller1.Axis3.position(), vex::percentUnits::pct);
      RightMotor.spin(vex::directionType::fwd, Controller1.Axis3.position(), vex::percentUnits::pct);
    }
    else
    {
      LeftMotor.stop();
      RightMotor.stop();
    }
    vex::task::sleep(25);
  }
}