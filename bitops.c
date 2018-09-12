#include<stdio.h>

#define BITMASK 
static void setbit (int pos, int *src){

	*src |= (1<<pos);
}

static void restbit (int pos, int *src){
	
	*src &= ~(1<<pos);
}

int main (){
	int a=1;
	int b=0;
	b=((~b)<<8);
	setbit(2,&a);
	restbit(0,&a);
	printf("%d\n", a);
	printf("%x\n", b);
	return 0;
}
