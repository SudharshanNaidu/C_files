#ifndef _LCD_H_
#define _LCD_H_

void LCD_Init(void);

void LCD_char(unsigned char);
void LCD_cmd(unsigned char);
void LCD_str(unsigned char *);

void LCD_int(int);

void LCD_float(float);
void CGRAM_build(void);
void LCD_scroll2_left(char *p);

#endif
