#include "car.h"

Car::Car(TIM_HandleTypeDef *servo_pwm_htim_, TIM_HandleTypeDef *motor_pwm_htim_,
		UART_HandleTypeDef *connect_huart) {
	servo = new Servo(servo_pwm_htim_);
	motor = new Motor(motor_pwm_htim_);
	connect = new Connect(connect_huart);
}

void Car::handle_rx_idle(UART_HandleTypeDef *huart) {
	if (huart == connect->connect_huart) {
		connect->handle_rx_idle();
	}
}

void Car::start() {
	servo->start();
	motor->start();
	connect->start();
}

void Car::test() {
//	servo->test();
	motor->test_pid();
}

void Car::update() {
	/* YOUR CODE THERE */
}
