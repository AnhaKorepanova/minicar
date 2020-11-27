#include "common.h"

float a_to_b(float a, float a_max, float a_min, float b_max, float b_min) {
	if (a > a_max) {
		a = a_max;
	}
	if (a < a_min) {
		a = a_min;
	}
	float res = ((a - a_min) * (b_max - b_min)) / (a_max - a_min) + b_min;
	return res;
}
