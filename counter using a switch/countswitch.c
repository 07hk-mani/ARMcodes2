#include <LPC214X.H>

#define sw1 (1<<16) //switch1
#define sw2 (1<<17) //switch2

void delay(unsigned int i)  //delay function
{
	unsigned int m,n;
	for(m=0;m<i;m++)
	{
		for(n=0;n<1000;n++);
	}
}

int main()
{
	int i=0;
	
int a[ ]={0x3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X67};
	
	PINSEL0=0X00000000;          //pinselect pin 0-15 of port0
	IODIR0=0xffffffff;                
	
IOSET0=a[i];
	
    while(1)
	{
			if(((IOPIN1) & sw1)==0)
			{
			while(((IOPIN1) & sw1)==0);
			if (i<9)
			{IOCLR0=a[i];
	      i++;
			}
		}
			else if(((IOPIN1) & sw2)==0)
			{
			while(((IOPIN1) & sw2)==0);
			if(i>0)
			{IOCLR0=a[i];	
			i--;
			}
		}

			IOSET0=a[i];
			delay(1000);

}
	
}


