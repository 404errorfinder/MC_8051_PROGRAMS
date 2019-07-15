#include<reg52.h> 
#include<LCD.h> 

sbit RS = P0^0;
sbit EN = P0^1;
sbit D0 = P2^0;
sbit D1 = P2^1;
sbit D2 = P2^2;
sbit D3 = P2^3;
sbit D4 = P2^4;
sbit D5 = P2^5;
sbit D6 = P2^6;
sbit D7 = P2^7;
sbit LED = P1^1;

void main()
{
	int m;
	int count = 0;
	int row = 0;
	Lcd_Setup();
	SCON = 0x50;
	TMOD = 0x20;
	TH1 = 0xFD;
	TR1 = 1;
	while(1)
	{
		while(RI == 0);
		m = SBUF;
		RI = 0;
		if(count <= 16 && row == 0)
		{
			Insert_Cmd(0x80 + count);
			Insert_Char(m);
			count++;
			if(count == 16)
			{
				row = 1;
				count = 0;
				continue;
			}
		}
		if(count <= 16 && row == 1)
		{
			Insert_Cmd(0xC0 + count);
			Insert_Char(m);
			count++;
			if(count == 16 && row == 1)																					
			{																				
				Lcd_Clear();
				Set_Cursor(0,0);
				Insert_String("NOT ENOUGH SPACE");
			}	
		}	
  }
}


/* LOOPING codes @ 48
if(count == 16)
	{																					
		row = 0;																
		count = 0;																
	}*/
