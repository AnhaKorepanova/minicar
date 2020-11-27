#ifndef MAINCPP_H_
#define MAINCPP_H_

#include "main.h"

#ifdef __cplusplus
extern "C" {
#endif

void loop();

void handle_idle(UART_HandleTypeDef *huart);

#ifdef __cplusplus
}
#endif

#endif // MAINCPP_H_
