#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;
controller Controller1 = controller(primary);
motor rightBack = motor(PORT17, ratio18_1, false);
motor leftBack = motor(PORT8, ratio18_1, true);
motor rightMiddle = motor(PORT20, ratio18_1, true);
motor leftMiddle = motor(PORT19, ratio18_1, false);
motor rightFront = motor(PORT18, ratio18_1, false);
motor leftFront = motor(PORT10, ratio18_1, true);
motor katieRerouter = motor(PORT1, ratio18_1, true); //update
digital_out clamp1 = digital_out(Brain.ThreeWirePort.H); //update
motor intake = motor(PORT7, ratio18_1, false);
inertial aniNertial = inertial(PORT16);
digital_out deviDoinker = digital_out(Brain.ThreeWirePort.D); //update
bumper beep = bumper(Brain.ThreeWirePort.A); //update
optical opt = optical(PORT7); //update

//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);

//Add your devices below, and don't forget to do the same in robot-config.h:


void vexcodeInit( void ) {
  // nothing to initialize
}