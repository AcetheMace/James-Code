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
// Left1                motor         2               
// Right1               motor         10              
// arm_lift_left        motor         1               
              
// arm_right            motor         12              
// arm_left             motor         11    
// lift                 motor         8
// Left2                motor         3
// Right2               motor         8          
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;
controller Controller1 = controller(primary);


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
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  Left1.spinFor(forward,7,turns,false);
  Right1.spinFor(reverse,7,turns,false);
  Left2.spinFor(forward,7,turns,false);
  Right2.spinFor(reverse,7,turns,false);
  wait(900,msec);
  Left1.spinFor(reverse,3,turns,false);
  Right1.spinFor(forward,3,turns,false);
  Left2.spinFor(reverse,3,turns,false);
  Right2.spinFor(forward,3,turns,false);
  
}
int arm_leftSpeed = 
    Controller1.ButtonR1.pressing() + Controller1.ButtonR1.pressing();

int arm_rightSpeed = 
    Controller1.ButtonR2.pressing() + Controller1.ButtonR2.pressing();
int arm_left_liftSpeed = 
    Controller1.ButtonL1.pressing() + Controller1.ButtonL1.pressing();
int liftSpeed = 
    Controller1.ButtonX.pressing() + Controller1.ButtonX.pressing();
int arm_right_liftSpeed = 
    Controller1.ButtonL2.pressing() + Controller1.ButtonL2.pressing();
int drivetrainLeftSideSpeed = 
    Controller1.Axis3.position() + Controller1.Axis1.position();
int drivetrainRightSideSpeed = 
    Controller1.Axis3.position() - Controller1.Axis1.position();
    void Controller1L1pressing(){
      arm_lift_left.spin(forward); 
      waitUntil(!Controller1.ButtonL1.pressing());
      arm_lift_left.stop(brakeType::hold);
    }
     void Controller1L2pressing(){
      arm_lift_left.spin(reverse);
      waitUntil(!Controller1.ButtonL2.pressing());
      arm_lift_left.stop(brakeType::hold);
    } 
    void Controller1R1pressing(){
      arm_left.spin(reverse);
      arm_right.spin(forward);
      waitUntil(!Controller1.ButtonR1.pressing());
      arm_left.stop(brakeType::hold);
      arm_right.stop(brakeType::hold);
    }
    void Controller1R2pressing(){
      arm_left.spin(forward);
      arm_right.spin(reverse);
      waitUntil(!Controller1.ButtonR2.pressing());
      arm_left.stop(brakeType::hold);
      arm_right.stop(brakeType::hold);
    }
    void Controller1Xpessing(){
      lift.spin(forward);
      waitUntil(!Controller1.ButtonX.pressing());
      lift.stop(brakeType::hold);
    } 
    void Controller1bpressing(){
      lift.spin(reverse);
      waitUntil(!Controller1.ButtonB.pressing());
      lift.stop(brakeType::hold);
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

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................


  int deadband = 5;

  while(true) {
    Controller1R1pressing();
    Controller1R2pressing();
    Controller1Xpessing();
    Controller1bpressing();
    Controller1L1pressing();
    Controller1L2pressing();

    int drivetrainLeftSideSpeed = 
    Controller1.Axis1.position() + Controller1.Axis3.position();
    int drivetrainRightSideSpeed = 
    Controller1.Axis1.position() - Controller1.Axis3.position();

    //This section applies to left motor one and two
    if (abs(drivetrainLeftSideSpeed) < deadband) {
      Left1.setVelocity(0, percent);
      Left2.setVelocity(0, percent);
    } else{
      Left1.setVelocity(drivetrainLeftSideSpeed, percent);
      Left2.setVelocity(drivetrainLeftSideSpeed, percent);
    }

    //This section applies to right motor one and two
    if (abs(drivetrainRightSideSpeed) < deadband) {
      Right1.setVelocity(0, percent);
    } else{
      Right1.setVelocity(drivetrainRightSideSpeed, percent);
    }

    Left1.spin(forward);
    Right1.spin(reverse);
    Left2.spin(forward);
    Right2.spin(reverse);

    wait(25, msec);
  
  }

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
