#include <LPC213X.H>

#define rs (1<<8)
#define rw (1<<9)
#define en (1<<10)


void delay(unsigned int i)
{
	unsigned int m,n;
	for(m=0;m<i;m++)
	{
		for(n=0;n<1000;n++);
	}
}


void cmd(unsigned char value)
{
	IOCLR0=rs;
	IOCLR0=rw;
	IOSET0=en;
	IOSET0=value;
	delay(50);
  IOCLR0=en;
	IOCLR0=value;
}
	void data(unsigned char value)
{
	IOSET0=rs;
	IOCLR0=rw;
	IOSET0=en;
	IOSET0=value;
	delay(50);
  IOCLR0=en;
	IOCLR0=value;
}

void string(unsigned char *a)
{
int i;
for(i=0; a[i]!='\0';i++)
data(a[i]);
}

int main()
{ int i;
	 
  PINSEL0=0X00000000;
	IODIR0=0XFFFFFFFF;
	  cmd(0x01);
		cmd(0x38);
    cmd(0x0e);
	  cmd(0x06);
    cmd(0x0c);
/*
	while(1)
{
		for(i=0;i<17;i++)
		{
		
			cmd( 0x80 | i );
			 string("himani");
			cmd( 0x80 | i-1 );
			string("  ");
			delay(100);
		}		
	}
	*/
while(1)
{cmd(0x80);
	cmd( 0x07 );
	
			 string("himani");
delay(100);
}

}

