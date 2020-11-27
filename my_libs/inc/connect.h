#ifndef CONNECT_H_
#define CONNECT_H_

#include "common.h"
#include "module.h"

class Connect: public Module {
private:
	int min_control_speed;
	int max_control_speed;
	int min_control_angle;
	int max_control_angle;

	uint8_t rx_data[CONN_RX_DATA_LEN];
public:
	UART_HandleTypeDef *connect_huart;

	bool was_control_received = false;
	int control_speed;
	int control_angle;

	Connect(UART_HandleTypeDef *connect_huart);
	void start();
	void update();

	void handle_rx_idle();

	void start_rx();
};

#endif // CONNECT_H_
