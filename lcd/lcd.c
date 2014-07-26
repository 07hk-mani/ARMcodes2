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
	IOSET0=value<<16;
	delay(100);
  IOCLR0=en;
	IOCLR0=value<<16;
}
	void data(unsigned char value)
{
	IOSET0=rs;
	IOCLR0=rw;
	IOSET0=en;
	IOSET0=value<<16;
	delay(100);
  IOCLR0=en;
	IOCLR0=value<<16;
}

void string(unsigned char *a)
{
int i;
for(i=0; a[i]!='\0';i++)
data(a[i]);
}

int main()
{
//	int i,j; 
//char a[][6]={"hello ","bye"};
//char b[]={'h','i','m','a','n','i'};
	

  PINSEL0=0X00000000;
PINSEL1=0X00000000;
	IODIR0=0XFFFFFFFF;
	  
   cmd(0x01);
		cmd(0x38);
    cmd(0x0e);
		
	  cmd(0x06);
    cmd(0x0c);
while(1)
	{
		//for(i=0;i<6;i++)
		{
			//data(b[i]);
//			for(j=0;j<6;j++)
	//		data(a[i][j]);
	   string("hi himani");
				
		}		
	}
}

