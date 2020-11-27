#ifndef PID_H_
#define PID_H_

#include "configs.h"

class Pid {
private:
	float lastError;
	float sumError;
public:
	Pid();
	void update(float error, float dt);
	float control;
};

#endif /* PID_H_ */
