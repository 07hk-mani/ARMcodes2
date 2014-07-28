#include <LPC214X.H>

#define sw (1<<16)

void delay(unsigned int i)
{
	unsigned int m,n;
	for(m=0;m<i;m++)
	{
		for(n=0;n<1000;n++);
	}
}

int main()
{
	PINSEL0=0X00000000;
	PINSEL1=0X00000000;
	IODIR0=0XFFF<<0;
	
	while(1)
	{
		if(((IOPIN0) & sw)==0)
		{
		IO0SET=0xfff;
			delay(100);
		
	}
		else
		{	IO0CLR=0xfff;	

	delay(100);
	}
}
}

