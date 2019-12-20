#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftMotor = motor(PORT19, ratio18_1, false);
motor RightMotor = motor(PORT3, ratio18_1, true);
motor CubeAngleMotor = motor(PORT10, ratio36_1, false);
motor CubeAngleMotor2 = motor(PORT14, ratio36_1, true);
motor LeftLiftMotor = motor(PORT2, ratio18_1, false);
motor RightLiftMotor = motor(PORT4, ratio18_1, true);
motor LeftIntakeMotor = motor(PORT11, ratio18_1, false);
motor RightIntakeMotor = motor(PORT20, ratio18_1, false);
controller Controller1 = controller(primary);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}