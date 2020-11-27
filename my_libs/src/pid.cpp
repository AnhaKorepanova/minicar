#include "pid.h"

void Pid::update(float error, float dt) {
	float p, i, d, pOut, iOut, dOut, controlOutput, de = 0;

	p = error;
	i = sumError + error * dt;
	de = error - lastError;

	if (de == 0) {
		d = error / dt;
	} else {
		d = (error - lastError) / dt;
	}

	pOut = p * PID_KP;
	iOut = i * PID_KI;
	dOut = d * PID_KD;

	controlOutput = pOut + iOut + dOut;

	sumError = i;
	lastError = error;
	control = controlOutput;
}

Pid::Pid() :
		lastError(0), sumError(0), control(0) {
}
