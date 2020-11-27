#include "servo.h"

float Servo::deg_to_pulse(float v_deg) {
	return a_to_b(v_deg, max_angle_deg, min_angle_deg, max_angle_pulse,
			min_angle_pulse);
}

float Servo::pulse_to_deg(float v_pulse) {
	return a_to_b(v_pulse, max_angle_pulse, min_angle_pulse, max_angle_deg,
			min_angle_deg);
}

void Servo::set_pulse(float pulse) {
	pwmHtim->Instance->CCR1 = pulse;
}

Servo::Servo(TIM_HandleTypeDef *pwmHtim_) :
		Module(0), pwmHtim(pwmHtim_), min_angle_pulse(SERVO_MIN_ANGLE_PULSE), max_angle_pulse(
		SERVO_MAX_ANGLE_PULSE), min_angle_deg(SERVO_MIN_ANGLE_DEG), max_angle_deg(
		SERVO_MAX_ANGLE_DEG), stop_angle_deg(SERVO_STOP_ANGLE_DEG) {
}

void Servo::start() {
	HAL_TIM_PWM_Start(pwmHtim, TIM_CHANNEL_1);
	set_angle_deg(stop_angle_deg);
}
void Servo::set_angle_deg(float angle_deg) {
	set_pulse(deg_to_pulse(angle_deg));
}

void Servo::update() {
	/* YOUR CODE THERE */
}

void Servo::test() {
	float pulse = deg_to_pulse(stop_angle_deg);

	int d = 1;
	int dp = 10;

	printf("Servo pulse/angle:\n");

	uint32_t now = HAL_GetTick();
	uint32_t prevUpdate = now;

	for (;;) {
		set_pulse(pulse);

		pulse += d * dp;

		if (pulse > max_angle_pulse) {
			printf("This is max angle pulse.\n");
			d = -1;
		}
		if (pulse < min_angle_pulse) {

			printf("This is min angle pulse.\n");
			d = 1;
		}

		printf("%4.0f  /  %2.0f\n", pulse, pulse_to_deg(pulse));

		HAL_Delay(50);
	}
}
