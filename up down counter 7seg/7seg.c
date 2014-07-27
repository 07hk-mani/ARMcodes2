#include <LPC214X.H>

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
	int c=0,d=100;
	int x,y;
	 int i;
	
	int a[]={0x030000,0x9f0000,0x250000,0x0d0000,0x990000,0x490000,0xc10000,0x1f0000,0x010000,0x190000};
	
	PINSEL0=0X00000000;
	PINSEL2=0X00000000;
	IODIR0=0XFFFFFFFF;
	IODIR1=0XFFFFFFFF;
	while(1)
	{ 
	
		for(i=0;i<99;i++)
		{
			c++;
			x=c%10;
			y=c/10;
			IOSET0=a[x];
			IOSET1=a[y];
			delay(500);
			IOCLR0=a[x];
			IOCLR1=a[y];
		}
	
	
		for(i=99;i>0;i--)
		{
			d--;
			x=d%10;
			y=d/10;
			IOSET0=a[x];
			IOSET1=a[y];
			delay(500);
			IOCLR0=a[x];
			IOCLR1=a[y];
		}
	}
}
	
	



