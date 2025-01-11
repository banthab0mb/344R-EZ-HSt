#include "main.h"  // IWYU pragma: keep

// intake control
void setIntake() {
	// <motor name>.move(a number between -127 and 127);
	if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
		intake.move(-100); 
	} else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
		intake.move(100);
	} else {
		intake.move(0);
	}
}

// lady brown control

const int numStates = 3;
//make sure these are in centidegrees (1 degree = 100 centidegrees)
int states[numStates] = {0, 300, 2000};
int currState = 0;
int target = 0;

void nextState() {
    currState += 1;
    if (currState == numStates) {
        currState = 0;
    }
    target = states[currState];
}

void liftControl() {
    double kp = 0.5;
    double error = target - lbRotation.get_position();
    double velocity = kp * error;
    wallmech.move(velocity);
}

void setWall() {
	if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
		nextState();
	}
}

// Pneumatics controls

void setMogo() { 
	bool mogomechState = false;
	if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)){
    mogomechState = !mogomechState; // toggle piston state
    mogomech.set(mogomechState);
	}
}

void setdoinker() { 
	bool doinkerState = false;
	if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)){
    doinkerState = !doinkerState; // toggle piston state
    doinker.set(doinkerState);
	}
}
