#ifndef MOTOR_H_
#define MOTOR_H_

#include "common.h"
#include "module.h"
#include "pid.h"

class Motor: public Module {
private:
	TIM_HandleTypeDef *pwmHtim;

	float current_speed_norm;
	float control_speed_norm;

	float min_speed_pulse;
	float max_speed_pulse;

	Pid *pid;

	void set_speed_norm(float v_norm);

public:

	Motor(TIM_HandleTypeDef *pwmHtim_);
	void set_control_speed_norm(float v_norm);

	void start();
	void update();
	void stop();
	void test();
	void test_pid();

};

#endif // MOTOR_H_
