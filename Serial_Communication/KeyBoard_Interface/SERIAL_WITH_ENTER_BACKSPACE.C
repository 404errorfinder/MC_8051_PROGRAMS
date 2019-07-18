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

int row0 = -1;
int row1 = 0;
	
void main()
{
	int msg;
	int row_change;
	Lcd_Setup();
	SCON = 0x50;
	TMOD = 0x20;
	TH1 = 0xFD;
	TR1 = 1;
	while(1)
	{
		while(RI == 0);
		msg = SBUF;
		RI = 0;
		if(msg == 0x08)
		{
			if(row0 > 0)
			{
				if(row1 != 0)
				{
						Insert_Cmd(0xC0 + row1);
						Insert_Cmd(0x10);
						Insert_Char(0x20);
						row1--;
						Insert_Cmd(0x10);
				}
				else
				{
					row_change = 0;
						Insert_Cmd(0x80 + row0);
						Insert_Cmd(0x10);
						Insert_Char(0x20);
						row0--;
						Insert_Cmd(0x10);
				}
			}
		}
		else if(msg == 0x0D)
		{
			Insert_Cmd(0xC0);
			row0++;
			row_change = 1;
		}
		else
		{
			if(row0 == -1)
			{
				Insert_Cmd(0x80);
				row0++;
			}
			if(row0 == 16 && row_change == 0)
			{
				Insert_Cmd(0xC0);
				row_change = 1;
			}
			Insert_Cmd(0x06);
			Insert_Char(msg);
			if(row_change == 0)
			{
				row0++;
			}
			else
			{
				row1++;
			}
		}
		
}
}


