#ifndef CAR_H_
#define CAR_H_

#include "common.h"
#include "servo.h"
#include "motor.h"
#include "connect.h"

class Car {
private:
	Servo *servo;
	Motor *motor;
	Connect *connect;

public:
	Car(TIM_HandleTypeDef *servo_pwm_htim_, TIM_HandleTypeDef *motor_pwm_htim_,
			UART_HandleTypeDef *connect_huart);
	void start();
	void update();
	void test();
	void handle_rx_idle(UART_HandleTypeDef *huart);
};

#endif /* CAR_H_ */
