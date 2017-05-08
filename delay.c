/*************************************************************
/*FILE NAME   : delay.c
/*DESCRIPTION : contains delay functions
/*CLOCK       : 11.0592 MHz
/*AUTHOR      : Sudharshan Pathi
**************************************************************/

#include<intrins.h>

void delay_ms(unsigned int n)
{
	unsigned int i;
	for(n;n>0;n--)
		for(i=121;i>0;i--);
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
}
