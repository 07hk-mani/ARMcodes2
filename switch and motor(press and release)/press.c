#include <LPC214X.H>

#define sw (1<<16) //switch

void delay(unsigned int i)  //delay function
{
	unsigned int m,n;
	for(m=0;m<i;m++)
	{
		for(n=0;n<1000;n++);
	}
}

int main()
{ int i=0;
	PINSEL0=0X00000000;          //pinselect pin 0-15 of port0
	PINSEL1=0X00000000;           //pinselect pin 16-31 of port0
	IODIR0=1<<6|1<<7;                //direction for port0 (1 means output and 0 means input)
	
	while(1)
	{
		
		if((((IOPIN0) & sw)==0) && (i%2==0))
		{
			while(((IOPIN0) & sw)==0);
			
			IOCLR0=1<<6;
		IOSET0=1<<7;
		delay(100);
			i++;
		
	}
		else if ((((IOPIN0) & sw)==0) && (i%2!=0))
		{
			while(((IOPIN0) & sw)==0);
			IOCLR0=1<<7;
			IOCLR0=1<<6;	
	delay(10);
			i++;
	}
}
	
	
	
	
	
}

