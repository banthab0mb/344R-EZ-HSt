#pragma once

#include "EZ-Template/api.hpp"  // IWYU pragma: keep
#include "api.h"  // IWYU pragma: keep

// Motors, sensors, etc
inline pros::Motor intake(12);
inline pros::Motor wallmech(-14);
inline ez::Piston mogomech('G');
inline ez::Piston doinker('C');
inline pros::Optical ringsens(8);
inline pros::Rotation lbRotation(15);

// Functions
void setIntake();
void setWall();
void setMogo();
void setdoinker();
void nextState();
void liftControl();

extern bool doinkerState;
extern bool mogomechState;

extern int states[];
extern const int numStates;
extern int currState;
extern int target;