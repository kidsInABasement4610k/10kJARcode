#include "vex.h"
/* 
AWP:
At least four (4) Scored Rings of the Alliance's color.
A minimum of three (3) Stakes on the Alliance's side of the Autonomous Line with at least one (1) Ring of the Alliance's color Scored.
At least one Ring of the Alliance's color Scored on the Alliance's Wall Stake.
Neither Robot contacting / breaking the plane of the Starting Line.
At least one (1) Robot contacting the Ladder.
*/
/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */
void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(9, 1.45, 0, 10, 0);
  chassis.set_heading_constants(5.9, .4, 0, 1.1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(2, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}
/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */
void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 10;
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
  chassis.boomerang_lead = .5;
  chassis.drive_min_voltage = 0;
}

void skills(){
  chassis.drive_distance(4.5);
  clamp1.set(true);
  chassis.turn_to_angle(-135);
  intake.spin(fwd, 100, pct);
  chassis.drive_distance(-13.5);
  //2

  chassis.turn_to_angle(90);
  chassis.drive_distance(-10);
  //3 rings

  chassis.turn_to_angle(-45);
  chassis.drive_distance(-11.25);
  //4

  chassis.turn_to_angle(-86);
  chassis.drive_distance(-5);
  //5 rings

  chassis.turn_to_angle(38);
  chassis.drive_distance(-4.5);
  //6 rings

  chassis.turn_to_angle(125);
  chassis.drive_distance(6.5);

  clamp1.set(false);
  intake.stop();
  //hopefully 6 on a mogo in the corner!

  chassis.drive_distance(-6);
  chassis.turn_to_angle(-89);
  chassis.drive_distance(12);
  chassis.drive_distance(10);
  //going to the other side

//second half
  chassis.drive_distance(5);
  clamp1.set(true);
  chassis.turn_to_angle(133);
  intake.spin(fwd, 100, pct);
  chassis.drive_distance(-12);
  //1

  chassis.turn_to_angle(-85);
  chassis.drive_distance(-7.5);
  //2

  chassis.turn_to_angle(135-90);
  chassis.drive_distance(-11.5);
  //3

  chassis.turn_to_angle(180-90);
  chassis.drive_distance(-5.5);
  //4

  chassis.turn_to_angle(50-90);
  chassis.drive_distance(-8);
  //5

  chassis.turn_to_angle(-30-90);
  chassis.drive_distance(6);
  clamp1.set(false);
  //corner

  chassis.drive_distance(-6);
  chassis.turn_to_angle(0);
  chassis.drive_distance(20);
  chassis.turn_to_angle(45);
  chassis.drive_distance(15);
  chassis.turn_to_angle(70);
  chassis.drive_distance(15);
}

void bluePositive(){
  chassis.drive_distance(8);
  clamp1.set(true);
  intake.spin(fwd,100,pct);
  wait(200, msec);
  chassis.turn_to_angle(90);
  chassis.drive_distance(-12);
  wait(600, msec);
  intake.stop(hold);
  chassis.turn_to_angle(-110);
  chassis.drive_distance(-14.5);
}

void blueNegative(){
  chassis.drive_distance(8);
  clamp1.set(true);
  intake.spin(fwd, 100, pct);
  wait(200, msec);
  chassis.turn_to_angle(-90);
  chassis.drive_distance(-10);
  wait(400, msec);
  //chassis.turn_to_angle(-180);
  chassis.turn_to_angle(165);
  chassis.drive_distance(-5.5);
  wait(400, msec);
  chassis.drive_distance(4);
  chassis.turn_to_angle(-180);
  chassis.drive_distance(-8);
  wait(400, msec);
  chassis.drive_distance(4);
  chassis.turn_to_angle(-85);
  chassis.drive_distance(13);
}

void redNegative(){
 chassis.drive_distance(8);
  clamp1.set(true);
  intake.spin(fwd, 100, pct);
  wait(200, msec);
  chassis.turn_to_angle(90);
  chassis.drive_distance(-10);
  wait(400, msec);
  chassis.turn_to_angle(-165);
  chassis.drive_distance(-5.5);
  wait(400, msec);
  chassis.drive_distance(4);
  chassis.turn_to_angle(180);
  chassis.drive_distance(-8);
  wait(400, msec);
  chassis.drive_distance(4);
  chassis.turn_to_angle(85);
  chassis.drive_distance(13);
}

void redPositive(){
  chassis.drive_distance(8);
  clamp1.set(true);
  intake.spin(fwd,100,pct);
  wait(200, msec);
  chassis.turn_to_angle(-90);
  chassis.drive_distance(-12);
  wait(600, msec);
  intake.stop(hold);
  chassis.turn_to_angle(-110);
  chassis.drive_distance(-14.5);
}

void simpleAuto(){

}

/**
 * Doesn't drive the robot, but just prints coordinates to the Brain screen 
 * so you can check if they are accurate to life. Push the robot around and
 * see if the coordinates increase like you'd expect.
 */
 void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5,20, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(5,40, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(5,60, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5,80, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(5,100, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    wait(20, msec);
  }
}
message.txt
6 KB
