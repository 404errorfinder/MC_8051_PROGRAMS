#include<reg51.h>
#include"LCD.h"
//connecting LCD pins
sbit RS = P3^0;                                                                   
sbit EN = P3^1;                           
sbit D0 = P2^0;
sbit D1 = P2^1;
sbit D2 = P2^2;
sbit D3 = P2^3;
sbit D4 = P2^4;
sbit D5 = P2^5;
sbit D6 = P2^6;
sbit D7 = P2^7;
// Connecting keypad
sbit C1 = P1^0;     
sbit C2 = P1^1;
sbit C3 = P1^2;
sbit C4 = P1^3;
sbit R4 = P1^4;
sbit R3 = P1^5;
sbit R2 = P1^6;
sbit R1 = P1^7;

int dly = 2;
void Delay(unsigned int time)
{
	int i;
	TMOD = 0x01;
	TH0 = 0xFC;
	TL0 = 0x67;
	for(i=0;i<time;i++)
	{
		TR0 = 1;
		while(TF0 == 0);
		TF0 = 0;
		TR0 = 0;
	}
}

void row_finder1()
{
Delay(dly);
R1=R2=R3=R4=1;
C1=C2=C3=C4=0;
Delay(dly);
if(R1==0)
Insert_Char_at(0,0,'1');
if(R2==0)
Insert_Char_at(0,0,'4');
if(R3==0)
Insert_Char_at(0,0,'7');
if(R4==0)
Insert_Char_at(0,0,'*');
}

void row_finder2()
{
Delay(dly);
R1=R2=R3=R4=1;
C1=C2=C3=C4=0;
Delay(dly);
if(R1==0)
Insert_Char_at(0,0,'2');
if(R2==0)
Insert_Char_at(0,0,'5');
if(R3==0)
Insert_Char_at(0,0,'8');
if(R4==0)
Insert_Char_at(0,0,'0');
}

void row_finder3()
{
Delay(dly);
R1=R2=R3=R4=1;
C1=C2=C3=C4=0;
Delay(dly);
if(R1==0)
Insert_Char_at(0,0,'3');
if(R2==0)
Insert_Char_at(0,0,'6');
if(R3==0)
Insert_Char_at(0,0,'9');
if(R4==0)
Insert_Char_at(0,0,'#');
}

void row_finder4()
{
Delay(dly);
R1=R2=R3=R4=1;
C1=C2=C3=C4=0;
Delay(dly);
if(R1==0)
Insert_Char_at(0,0,'A');
if(R2==0)
Insert_Char_at(0,0,'B');
if(R3==0)
Insert_Char_at(0,0,'C');
if(R4==0)
Insert_Char_at(0,0,'D');
}

void main()
{
    Lcd_Setup();
    while(1)
    {    
				Delay(dly);
        C1=C2=C3=C4=1;
        R1=R2=R3=R4=0;
			  Delay(dly);
        if(C1==0)
          row_finder1();
        else if(C2==0)
          row_finder2();
        else if(C3==0)
					row_finder3();
        else if(C4==0)
					row_finder4();
    }
}