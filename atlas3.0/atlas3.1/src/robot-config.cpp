#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor Left1 = motor(PORT2, ratio18_1, false);
motor Right1 = motor(PORT10, ratio18_1, false);
motor arm_lift_left = motor(PORT1, ratio18_1, false);
motor arm_right = motor(PORT12, ratio18_1, false);
motor arm_left = motor(PORT11, ratio18_1, false);
motor lift = motor(PORT9,ratio18_1,false);
motor Left2 = motor(PORT3, ratio18_1, false);
motor Right2 = motor(PORT8, ratio18_1, false);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}