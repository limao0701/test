#include <stdio.h>
#include <S3C2440.h>
#define LED1 (0X01<<10)
#define LED2 (0X01<<12)
#define LED3 (0X01<<14)
#define LED4 (0X01<<16)
#define LED1ON (0X01<<5)
#define LED2ON (0X01<<6)
#define LED3ON (0X01<<7)
#define LED4ON (0X01<<8)
void delay();
int main(void){
	GPBCON &=~(255<<10);
	GPBCON |= LED1;
	GPBCON |= LED2;
	GPBCON |= LED3;
	GPBCON |= LED4;
	GPBDAT &=~(7<<5);
	GPBDAT |=LED1ON;
	GPBDAT |=LED2ON;
	GPBDAT |=LED3ON;
	while(1){
		GPBDAT &=~(7<<5);
		delay();
		GPBDAT |=(LED1ON | LED2ON);
    delay();
	}
	return 0;
}


void delay(){
	int i=3000000;
	int j=1000000;
	int c=0;
	for (;i>0;i--){
		for(;j>0;j--)
		   c=j>i;
	}
}