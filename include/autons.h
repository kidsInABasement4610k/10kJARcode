#pragma once
#include "JAR-Template/drive.h"

class Drive;

extern Drive chassis;

void default_constants();

void drive_test();
void turn_test();
void swing_test();
void full_test();
void odom_test();
void tank_odom_test();
void holonomic_odom_test();

//My autons
void skills();
void redPositive();
void redNegative();
void bluePositive();
void blueNegative();
void simpleAuto();

void redPositiveElims();
void redNegativeElims();
void bluePositiveElims();
void blueNegativeElims();
