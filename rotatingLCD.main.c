/*
l * main.c
 *
 *  Created on: Apr 4, 2019
 *      Author: zizo rashad
 */
#include"types.h"
#include"LCD.h"

#define F_CPU 8000000
#include<util/delay.h>

typedef enum
{
	aen,
	beh,
	dal,
	alf,
	lam,
	zen,
	yeh
}zizo;

int main (void)
{
	LCD_vidInit();
	//LCD_vidInit();
	u8 row1[16]={'A','b','d','e','l','a','z','i','z',7,7,7,7,7,7,7};
	u8 row2[16]={7,7,7,7,7,7,7,zen,yeh,zen,aen,lam,alf,dal,beh,aen};
	u8 swap;
	//u8 row2[16]={5,6,5,0,4,3,2,1,0,7,7,7,7,7,7,7};
	//u8 arr[16]={0};
	//u8 i=0,j=0,k=0,l=0;
	//u8 lcd_char_adress = 64;	 // this is means location 0

	LCD_vidWriteCommand(0b01000000);	// or 64
	// ain
	LCD_vidWriteChar(0);
	LCD_vidWriteChar(0b00011111);
	LCD_vidWriteChar(0b00010000);
	LCD_vidWriteChar(0b00010000);
	LCD_vidWriteChar(0b11111111);
	LCD_vidWriteChar(0b000);
	LCD_vidWriteChar(0b000);
	LCD_vidWriteChar(0);
	// beh @ 1
	LCD_vidWriteChar(0);
	LCD_vidWriteChar(0b00000000);
	LCD_vidWriteChar(0b00000100);
	LCD_vidWriteChar(0b00000100);
	LCD_vidWriteChar(0b11111111);
	LCD_vidWriteChar(0);
	LCD_vidWriteChar(0b00001000);
	LCD_vidWriteChar(0);
	// dal @ 2
	LCD_vidWriteChar(0);
	LCD_vidWriteChar(0);
	LCD_vidWriteChar(0b00010000);
	LCD_vidWriteChar(0b00001000);
	LCD_vidWriteChar(0b00011100);
	LCD_vidWriteChar(0);
	LCD_vidWriteChar(0);
	LCD_vidWriteChar(0);
	// alf @ 3
	LCD_vidWriteChar(0b00000100);
	LCD_vidWriteChar(0b00000100);
	LCD_vidWriteChar(0b00000100);
	LCD_vidWriteChar(0b00000100);
	LCD_vidWriteChar(0b00000100);
	LCD_vidWriteChar(0);
	LCD_vidWriteChar(0);
	LCD_vidWriteChar(0);
	// lam @ 4
	LCD_vidWriteChar(0b00000100);
	LCD_vidWriteChar(0b00000100);
	LCD_vidWriteChar(0b00000100);
	LCD_vidWriteChar(0b00000100);
	LCD_vidWriteChar(0b11111100);
	LCD_vidWriteChar(0);
	LCD_vidWriteChar(0);
	LCD_vidWriteChar(0);
	// zen @ 5
	LCD_vidWriteChar(0);
	LCD_vidWriteChar(0b00000010);
	LCD_vidWriteChar(0);
	LCD_vidWriteChar(0b00000100);
	LCD_vidWriteChar(0b00000111);
	LCD_vidWriteChar(0b00001000);
	LCD_vidWriteChar(0b00100000);
	LCD_vidWriteChar(0);
	// yeh 6
	LCD_vidWriteChar(0);
	LCD_vidWriteChar(0b00000010);
	LCD_vidWriteChar(0b00000010);
	LCD_vidWriteChar(0b00000010);
	LCD_vidWriteChar(0b11111111);
	LCD_vidWriteChar(0);
	LCD_vidWriteChar(0b00010100);
	LCD_vidWriteChar(0);
	// nothing 7
	LCD_vidWriteChar(0);
	LCD_vidWriteChar(0);
	LCD_vidWriteChar(0);
	LCD_vidWriteChar(0);
	LCD_vidWriteChar(0);
	LCD_vidWriteChar(0);
	LCD_vidWriteChar(0);
	LCD_vidWriteChar(0);

	LCD_vidSetPosition(1,1);
	while (1)
	{
		// printing the English name in row 1
		LCD_vidSetPosition(1,1);
		for (u8 i=0;i<16;i++)
		{
			LCD_vidWriteChar(row1[i]);
		}

		// printing arabic name in row 2
		LCD_vidSetPosition(2,1);
		for (u8 i=0;i<16;i++)
		{
			LCD_vidWriteChar(row2[i]);
		}
		// row 1 rotating right
		for (u8 i=0;i<16;i++)
		{
			if (i==0)
			{
				swap = row1[15];
				//continue;
			}
			else if (i==15)
			{
				row1[0]= swap;
				swap=0;
				continue;
			}
			else {}
			row1[15-i]=row1[15-i-1];
		}

		//row 2 rotating left
		for (u8 i=0;i<16;i++)
		{
			if (i==0)
			{
				swap = row2[0];
				continue;
			}
			else {}

			row2[i-1]=row2[i];

			if (i==15)
			{
				row2[i]= swap;
				swap=0;
				//continue;
			}
			else {}

		}

		_delay_ms(800);
		/*
		// af45 wa7ed 3mlto sa7 fadlo taka bas ISA

		LCD_vidDisplayHome();
		for (u8 n=0;n<j;n++)
		{
			for (u8 n1=7;n1<j;n1++)
			{
				LCD_vidWriteChar(row1[15-n1]);
				n += (n1-7);
			}
			LCD_vidWriteChar(' ');
		}
		for (i=0;i<9;i++)
			LCD_vidWriteChar(row1[i]);
		for (;i<16;i++)
			LCD_vidWriteChar(' ');
		if (i==16)
		{
			j++;
		}
		if (j== 16)
			j=0;
		_delay_ms(800);
*/

		/*
		LCD_vidSetPosition(2,1);
		for (u8 x =1;x<9;x++)
			LCD_vidWriteChar(row1[8-x]);
		 */

		/*
		LCD_vidWriteChar(zen);
		LCD_vidWriteChar(aen);
		LCD_vidWriteChar(lam);
		LCD_vidWriteChar(alf);
		LCD_vidWriteChar(dal);
		LCD_vidWriteChar(beh);
		LCD_vidWriteChar(aen);

		LCD_vidWriteChar('A');
		i++;
		LCD_vidWriteChar('b');
		i++;
		LCD_vidWriteChar('d');
		i++;
		LCD_vidWriteChar('E');
		i++;
		LCD_vidWriteChar('l');
		i++;
		LCD_vidWriteChar('a');
		i++;
		LCD_vidWriteChar('z');
		i++;
		LCD_vidWriteChar('i');
		i++;
		LCD_vidWriteChar('z');
		i++;

		*/
	}
	return 0;
}
