/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\4168242                                          */
/*    Created:      Fri Dec 13 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
  vex::motor lm = vex::motor(vex::PORT19);
  vex::motor rm = vex::motor(vex::PORT3, true);
 float GlobalX, GlobalY; 
void drive (float inches, float theta)
{
  float x,y;
 int diameter = 4;
 float circumference,degrees;

 circumference = diameter * 3.1459;
 degrees = (inches*360)/circumference;

 x = inches*cos(theta);
 y = inches*sin(theta);

 GlobalX += x;
 GlobalY += y;
Brain.Screen.setCursor(1,0);
Brain.Screen.print("%.1f", GlobalX);
Brain.Screen.setCursor(2,0);
Brain.Screen.print("%.1f", GlobalY);

 lm.rotateFor(degrees, vex::rotationUnits::deg, false);
 rm.rotateFor(degrees, vex::rotationUnits::deg);

x=0;
y=0;

}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  
}
