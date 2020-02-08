/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    2, 10           
// Lift                 motor         8               
// arm_lift_right       motor         9               
// arm_lift_left        motor         1               
// arm_right            motor         12              
// arm_left             motor         11              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

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
  Drivetrain.driveFor(forward,24, inches);
  Drivetrain.driveFor(reverse,12,inches);
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
 void Controller1L1pressing(){
      arm_lift_left.spin(forward); 
      arm_lift_right.spin(reverse);
      waitUntil(!Controller1.ButtonL1.pressing());
      arm_lift_left.stop(brakeType::hold);
      arm_lift_right.stop(brakeType::hold);
    }
     void Controller1L2pressing(){
      arm_lift_left.spin(reverse); 
      arm_lift_right.spin(forward);
      waitUntil(!Controller1.ButtonL2.pressing());
      arm_lift_left.stop(brakeType::hold);
      arm_lift_right.stop(brakeType::hold);;
     } 
void usercontrol(void) {
  // Base velocity sets
  
  while (1) {
    Controller1L1pressing();
    Controller1L2pressing();
    arm_left.setVelocity(75,percent);
    arm_right.setVelocity(75,percent);
    arm_lift_left.setVelocity(75,percent);
    arm_lift_right.setVelocity(90,percent);
    Lift.setVelocity(100,percent);

//Configures arm lift motors to L1 and L2 buttons. Arm lift right is set to 90% velocity due to motor lag.
   
// Configures arm motors to R1 and R2 button. When buttons are not being pressed velocity is zero.
  if(Controller1.ButtonR1.pressing()){
    arm_left.setVelocity(75,percent);
    arm_right.setVelocity(75,percent);
  } 
  else if(Controller1.ButtonR2.pressing()){
    arm_left.setVelocity(-75,percent);
    arm_right.setVelocity(-75,percent);
    } else{
      arm_left.setVelocity(0,percent);
      arm_right.setVelocity(0,percent);
    }
// makes sure that all motors run forward when not being used. 
arm_lift_left.spin(forward);
arm_lift_right.spin(forward);
arm_left.spin(forward);
arm_right.spin(forward);
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
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
