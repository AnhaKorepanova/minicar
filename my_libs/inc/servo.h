#ifndef SERVO_H_
#define SERVO_H_

#include "common.h"
#include "module.h"

class Servo: public Module {
private:
	TIM_HandleTypeDef *pwmHtim;
	int pwmHtimCh;

	float stop_angle_deg;
	float min_angle_pulse;
	float max_angle_pulse;
	float min_angle_deg;
	float max_angle_deg;

	float deg_to_pulse(float v_deg);
	float pulse_to_deg(float v_pulse);
	void set_pulse(float pulse);
public:
	Servo(TIM_HandleTypeDef *pwmHtim_);
	void start();
	void update();
	void test();

	void set_angle_deg(float angle_deg);
};

#endif // SERVO_H_
