#pragma once

#include "EZ-Template/api.hpp"  // IWYU pragma: keep
#include "api.h"  // IWYU pragma: keep

// Motors, sensors, etc
inline pros::Motor intake(12);
inline pros::Motor wallmech(14);
inline ez::Piston mogomech('G');
inline ez::Piston indexer('A');
inline ez::Piston doinker('C');
inline pros::Optical ringsens(8);
// inline pros::adi::DigitalIn limit_switch('A');

// Functions
void setIntake();
void setWall();
void setMogo();
void setRedirect();
void setdoinker();
bool shift();