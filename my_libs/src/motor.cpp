#include "motor.h"
#include "common.h"

Motor::Motor(TIM_HandleTypeDef *pwmHtim_) :
		Module(MOTOR_UPDATE_PERIOD), pwmHtim(pwmHtim_), current_speed_norm(0.0), control_speed_norm(
				0.0), max_speed_pulse(
		MOTOR_MAX_PULSE), min_speed_pulse(MOTOR_MIN_PULSE) {
	pid = new Pid();
}

void Motor::set_speed_norm(float v_norm) {

	if (v_norm > 0) {

		int pulse = (int) a_to_b(v_norm, 1.0, 0.0, max_speed_pulse,
				min_speed_pulse);
		pwmHtim->Instance->CCR1 = pulse;
		pwmHtim->Instance->CCR2 = 0;
	} else {
		int pulse = (int) a_to_b(-v_norm, 1.0, 0.0, max_speed_pulse,
				min_speed_pulse);
		pwmHtim->Instance->CCR1 = 0;
		pwmHtim->Instance->CCR2 = pulse;
	}
}

void Motor::set_control_speed_norm(float v_norm) {
	control_speed_norm = v_norm;
}

void Motor::start() {
	HAL_TIM_PWM_Start(pwmHtim, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(pwmHtim, TIM_CHANNEL_2);
	stop();
	HAL_GPIO_WritePin(nSleep_GPIO_Port, nSleep_Pin, GPIO_PIN_SET);
}

void Motor::update() {
	/* YOUR CODE THERE */
}

void Motor::stop() {
	pwmHtim->Instance->CCR1 = 0;
	pwmHtim->Instance->CCR2 = 0;
	current_speed_norm = 0;
}

void Motor::test() {
	float speed_norm = 0.0;
	float d = 1.0;
	float dp = 0.1;

	uint32_t now = HAL_GetTick();
	uint32_t dt = 0;

	printf("Current pulse / velocity:/n");

	for (;;) {

		dt = now;
		now = HAL_GetTick();
		dt = now - dt;

		speed_norm += d * dp;

		if (speed_norm > 1) {
			d = -1.0;
		}
		if (speed_norm < 0) {
			d = 1.0;
		}

		set_speed_norm(speed_norm);

		printf("%i  /  %2.0f\n", pwmHtim->Instance->CCR1, speed_norm);

		HAL_Delay(50);
	}
}

void Motor::test_pid() {
	control_speed_norm = 0.0;
	float d = 1.0;
	float dp = 0.3;

	uint32_t dt = 0;
	uint32_t speed_update_period = 500;
	uint32_t prev_speed_update_time = HAL_GetTick();

	printf("Current pulse / velocity:/n");

	for (;;) {

		now = HAL_GetTick();
		dt = now - prev_speed_update_time;

		if (dt > speed_update_period) {
			control_speed_norm += d * dp;
			if (control_speed_norm > 1) {
				d = -1.0;
			}
			if (control_speed_norm < 0) {
				d = 1.0;
			}

			prev_speed_update_time = now;
		}

		update();

		printf("%i  /  %2.2f\n", pwmHtim->Instance->CCR1, current_speed_norm);

		HAL_Delay(10);
	}
}

