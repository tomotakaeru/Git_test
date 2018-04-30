#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

#include <pigpio.h>
int main(int argc, char const *argv[])
{
	sleep(2);
	printf("Hello World\n");
	usleep(2*1000000);
	printf("Hello World\n");
	/* code */
	return 0;
}
