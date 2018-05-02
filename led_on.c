#include "settings.h"
#include <pigpio.h>

void main(void){
	// GPIO初期化
	if (gpioInitialise() < 0) {
		printf("initialize error");
		exit(1);
	}
	gpioSetMode(17,PI_OUTPUT);
	while(1){
		gpioWrite(17,PI_ON);
		time_sleep(0.5);
		gpioWrite(17,PI_OFF);
		time_sleep(0.5);
	}
	gpioTerminate();
	return;
}