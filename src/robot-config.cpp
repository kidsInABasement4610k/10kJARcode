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
digital_out clamp1 = digital_out(Brain.ThreeWirePort.H);
motor intake = motor(PORT7, ratio18_1, true);
inertial aniNertial = inertial(PORT16);
digital_out deviDoinker = digital_out(Brain.ThreeWirePort.G);
motor rightLb = motor(PORT6, ratio18_1, true);
motor leftLb = motor(PORT3, ratio18_1, false);
rotation roti = rotation(PORT1);
bumper beep = bumper(Brain.ThreeWirePort.A); //update
optical opt = optical(PORT7); //update

void vexcodeInit( void ) {
  // nothing to initialize
}