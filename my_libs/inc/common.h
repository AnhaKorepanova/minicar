#ifndef COMMON_H_
#define COMMON_H_

#include "stdint.h"
#include "stdbool.h"
#include "stdlib.h"
#include "stdio.h"
#include "stm32f1xx_hal.h"

#include "configs.h"

float a_to_b(float a, float a_max, float a_min, float b_max, float b_min);

#endif // COMMON_H_
