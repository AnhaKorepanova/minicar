#include "maincpp.h"
#include "car.h"

extern TIM_HandleTypeDef *servo_pwm_htim;
extern TIM_HandleTypeDef *motor_pwm_htim;
extern UART_HandleTypeDef *connect_huart;

Car *car;

void handle_idle(UART_HandleTypeDef *huart) {
	__HAL_UART_DISABLE_IT(huart, UART_IT_IDLE);
	car->handle_rx_idle(huart);

}

void loop() {

	car = new Car(servo_pwm_htim, motor_pwm_htim, connect_huart);

	car->start();
//	car->test();

	for (;;) {
		car->update();
		HAL_Delay(10);
	}
}
