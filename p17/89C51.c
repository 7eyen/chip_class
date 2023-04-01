#include<reg51.h>
sbit S1 = P3^0;
sbit S2 = P3^1;
sbit sound = P1^0;
unsigned int keyval;
void delay(unsigned int n){
	unsigned int i;
	for(i=0;i<n;i++);
}

void delay1000Hz(void){
	unsigned char i;
	for(i=0;i<167;i++);
}

void delay500Hz(void){
	unsigned char i;
	for(i=0;i<133;i++);
}

void sound1s(void){
	unsigned int i;
	for(i=0;i<1000;i++){
		sound=0;
		delay1000Hz();
		sound=1;
		delay1000Hz();
	}
}

void soundBans(void){
	unsigned char i;
	for(i=0;i<250;i++){
		sound=0;
		delay500Hz();
		sound=1;
		delay500Hz();
	}
}

void key_scan(void){
	if(S1==0){
		keyval = 1;
	}
	delay(1000);
	if(S2==0){
		keyval = 2;
	}
	delay(1000);
}

void main(void){
	keyval = 0;
	while(1){
		key_scan();
		switch(keyval){
			case 1:sound1s();
			break;
			case 2:soundBans();
			break;
		}
	}
}