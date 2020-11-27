#include "main.h"

#ifndef CONFIGS_H
#define CONFIGS_H

// connection

#define CONN_MIN_CTRL_SPEED 100
#define CONN_MAX_CTRL_SPEED 300
#define CONN_MIN_CTRL_ANGLE 100
#define CONN_MAX_CTRL_ANGLE 300

#define CONN_RX_DATA_LEN 10

#define CONN_MAX_CTRL_VALUE 300
#define CONN_MIN_CTRL_VALUE 100
#define CONN_CENTER_CTRL_VALUE 200
//servo
#define SERVO_STOP_ANGLE_DEG 90

#define SERVO_MIN_ANGLE_DEG 0
#define SERVO_MIN_ANGLE_PULSE 500

#define SERVO_MAX_ANGLE_DEG 180
#define SERVO_MAX_ANGLE_PULSE 2500

#define SERVO_UPDATE_PERIOD 10

// motor
#define MOTOR_MIN_PULSE 0
#define MOTOR_MAX_PULSE 1999
#define MOTOR_UPDATE_PERIOD 10

// pid
#define PID_KP 0.3f
#define PID_KI 0.0f
#define PID_KD 0.0f

#endif // CONFIGS_H
