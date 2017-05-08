#include "delay.h"
#include "lcd.h"

main()
{
	int i;
	LCD_Init();
	Init_keypad();	
	while(1)
	{	
		LCD_cmd(0x85);
		LCD_str("WELCOME");
		//LCD_cmd(0x18);
		//LCD_cmd(0xc0);
		LCD_scroll2_left("Sudharshan");
		/*LCD_str("Sudharshan");
		for(i = 0;i<16;i++)
		{
			LCD_cmd(0x18);
			delay_ms(300);
		}*/
	}
	/*LCD_cmd(0xc0);
	LCD_float(1619.14);*/

/*	CGRAM_build();
	LCD_cmd(0xc0);
	LCD_char(0);*/
	while(1);

}
