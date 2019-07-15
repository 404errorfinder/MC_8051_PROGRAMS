#include<reg52.h>
sbit button = P1^2;

void delay()
{
	unsigned int i,j;
	for(i=0;i<=9;i++)
	{
		for(j=0;j<=255;j++)
		{
		}
	}
}
void main()
{
	int count;
	button = 1;
	SCON = 0x50;
	TMOD = 0x22;
	TH1 = -3;
	TR1 = 1;
	while(1)
	{
		if(button == 1)
		{
			SBUF = 'A';
			while(TI == 0);
			TI = 0;
			while(button == 1);
		}
		else
		{
			count = count + 1;
			P0 = count;
			delay;
		}
	}
}

