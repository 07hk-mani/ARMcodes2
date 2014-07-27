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
	 int i;
	
	int a[]={0x11111103,0x1111119f,0x11111125,0x1111110d,0x00000099,0x11111149,0x111111c1,0x1111111f,0x11111101,0x11111119};
	
	PINSEL0=0X00000000;
	IODIR0=0XFFFFFFFF;
	while(1)
	{

		for(i=0;i<10;i++)
		{
			IOSET0=a[i];
			delay(1000);
			IOCLR0=a[i];
		}
			for(i=9;i>=0;i--)
		{
			IOSET0=a[i];
			delay(1000);
			IOCLR0=a[i];
		}
		
	}
}
	
	



