using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LeftMotor;
extern motor RightMotor;
extern motor StrafeMotor;
extern motor CubeAngleMotor;
extern motor LeftLiftMotor;
extern motor RightLiftMotor;
extern motor LeftIntakeMotor;
extern motor RightIntakeMotor;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );