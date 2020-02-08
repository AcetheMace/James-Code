using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor Left1;
extern motor Right1;
extern motor arm_lift_left;
extern motor arm_lift_right;
extern motor arm_right;
extern motor arm_left;
extern motor lift;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );