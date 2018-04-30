#include "settings.h"
#include <pigpio.h>

int times = 1;

void changeLED(void);

void main(void){
	// GPIO初期化
	if (gpioInitialise() < 0) {
		printf("initialize error");
		exit(1);
	}
	gpioSetMode(17,PI_OUTPUT);
	gpioSetMode(18,PI_INPUT);
	gpioWrite(17,PI_OFF);
	gpioSetISRFunc(18,RISING_EDGE,-1,changeLED);
	while(1){
	}
	gpioTerminate();
	return;
}

void changeLED(void){
	gpioWrite(17,!gpioRead(17));
	time_sleep(0.01);
}