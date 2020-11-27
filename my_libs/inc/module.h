#ifndef MODULE_H_
#define MODULE_H_

class Module {
protected:
	uint32_t prev_update_time;
	uint32_t now;
	uint32_t update_period;
	Module(uint32_t update_period_) :
			update_period(update_period_) {
		prev_update_time = HAL_GetTick();
	}
	;
public:
	virtual void start() = 0;
	virtual void update() = 0;
};

#endif /* MODULE_H_ */
