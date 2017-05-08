#include"lcd.h"
#include"delay.h"
#include<reg51.h>


#define lcd P0

sbit rs = P3^0;
sbit rw = P3^1;
sbit en = P3^2;

char CGRAM_LUT[] = {0x1f,0x1a,0x14,0x1f,0x14,0x1a,0x1f,0x00};

void LCD_Init(void)
{
	delay_ms(15);
	LCD_cmd(0x30);
	
	delay_ms(5);
	LCD_cmd(0x30);
	
	delay_ms(2);
	LCD_cmd(0x30);
	
	delay_ms(2);
	LCD_cmd(0x38); //8-bit ,2-line,5x7 pixel
	LCD_cmd(0x08); //Turn off display
	LCD_cmd(0x01); //clear display
	LCD_cmd(0x06); //shift cursor right side
	LCD_cmd(0x0f); //display cursor with blinking
}

void LCD_cmd(unsigned char cmd)
{
	lcd = cmd;
	rs=0;
	rw=0;
	en= 1;
	delay_ms(2);
	en=0;
}

void LCD_char(unsigned char ch)
{
	lcd = ch;
	rs=1 ;
	rw=0;
	en= 1;
	delay_ms(2);
	en=0;
}

void LCD_str(unsigned char *p)
{
	while(*p)
		LCD_char(*p++);
}

void LCD_int(int n)
{
	char a[5];
	char i=0;
	if(n==0)
	{
		LCD_char(0+48);
	}
	else
	{
		if(n<0)
		{
			LCD_char('-');
			n = -n;
		}
		while(n)
		{
			a[i] = n%10;
			n/=10;
			i++;
		}
		for(;i>0;i--)
		{
			LCD_char(a[i-1]+48);

		}
	}

}

/*void LCD_float(float f)
{
	int i;
	i=f;
	LCD_int(i);
	LCD_char('.');
	i = (f-i)*100;
	LCD_int(i);

}

void CGRAM_build(void)
{
	char i;
	LCD_cmd(0x40);
	for(i=0;i<8;i++)
	{
		LCD_char(CGRAM_LUT[i]);
	}

}

void LCD_scroll2_left(char *p)
{
//	char i;
	while(*p)
	{	
		LCD_cmd(0xc0);
		LCD_str(p);
		delay_ms(500);
		LCD_str("                             ");
		p++;
	}
}*/




