#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftMotor = motor(PORT12, ratio18_1, false);
motor RightMotor = motor(PORT19, ratio18_1, true);
motor StrafeMotor = motor(PORT15, ratio18_1, false);
motor CubeAngleMotor = motor(PORT2, ratio18_1, false);
motor LeftLiftMotor = motor(PORT1, ratio18_1, false);
motor RightLiftMotor = motor(PORT21, ratio18_1, true);
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