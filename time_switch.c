#include "settings.h"
#include <pigpio.h>

int times = 1;

void getTime(void);

void main(void){
	// GPIO初期化
	if (gpioInitialise() < 0) {
		printf("initialize error");
		exit(1);
	}
	gpioSetMode(17,PI_OUTPUT);
	gpioSetMode(18,PI_INPUT);
	gpioWrite(17,PI_OFF);
	gpioSetISRFunc(18,RISING_EDGE,-1,getTime);
	while(1){
	}
	gpioTerminate();
	return;
}

void getTime(void){
	int secs,mics,h,time_bytes;
	char time[100];
	time_sleep(0.01);
	gpioTime(PI_TIME_RELATIVE,&secs,&mics);
	sprintf(time,"%d\t%d.%3d\n",times,secs,mics/1000);
	time_bytes=strlen(time);
	h=fileOpen("/home/sugarpi/c/practice/test.txt",
		PI_FILE_RW|PI_FILE_APPEND|PI_FILE_CREATE);
	fileWrite(h,time,time_bytes);
	fileClose(h);
	printf(time);
	times+=1;
}