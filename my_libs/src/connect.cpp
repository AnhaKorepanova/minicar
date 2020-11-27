#include "connect.h"
#include <stdio.h>
#include <string.h>

static uint8_t buffer[32];

Connect::Connect(UART_HandleTypeDef *connect_huart_) :
		Module(0), connect_huart(connect_huart_), min_control_speed(
		CONN_MIN_CTRL_SPEED), max_control_speed(CONN_MAX_CTRL_SPEED), min_control_angle(
		CONN_MIN_CTRL_ANGLE), max_control_angle(CONN_MAX_CTRL_ANGLE) {
}

void Connect::start_rx() {
	__HAL_UART_CLEAR_IDLEFLAG(connect_huart);
	__HAL_UART_ENABLE_IT(connect_huart, UART_IT_IDLE);
	if (HAL_UART_Receive_DMA(connect_huart, buffer, sizeof(buffer)) != HAL_OK) {
		// error
	}
}

void Connect::start() {
	memset(buffer, 0, sizeof(buffer));
	start_rx();
}

void Connect::update() {
}

void Connect::handle_rx_idle() {
	HAL_UART_DMAStop(connect_huart);
	int rcvdCount = sizeof(buffer) - connect_huart->hdmarx->Instance->CNDTR;

	if (rcvdCount == 8) {
		int control = atoi((char*) &(buffer[1]));
		control_speed = control % 1000;
		control_angle = control / 1000;
		was_control_received = true;
	}

	start_rx();

}

