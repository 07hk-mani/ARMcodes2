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
	IOSET0=value;
	
	IOCLR0=rs;
	IOCLR0=rw;
	IOSET0=en;
	delay(10);
  IOCLR0=en;
	
	IOCLR0=value;
}
	void data(unsigned char value)
{
	IOSET0=value;
	
	IOSET0=rs;
	IOCLR0=rw;
	IOSET0=en;
	delay(10);
  IOCLR0=en;
	IOCLR0=value;
}



void discmd(unsigned char a)
{
	int x;
	x=(a&0xf0);
	cmd(x);
		x=((a<<4)&0xf0);
	cmd(x);
}
void disdata(unsigned char a)
{
	int y;
	y=(a&0xf0);
	data(y);
		y=((a<<4)&0xf0);
	data(y);
}
void string(unsigned char *a)
{
int i;
for(i=0; a[i]!='\0';i++)
disdata(a[i]);
}

int main()
{
	PINSEL0=0X00000000;
  PINSEL1=0X00000000;
	IODIR0=0XFFFFFFFF;
	  
   discmd(0x01); //clear all
	discmd(0x02); //return home
		discmd(0x28);  //4 bit mode
	  discmd(0x0e); //display on cursor on
	discmd(0x06);  //entry mode
  
while(1)
{	 discmd(0x01); //clear all
	discmd(0x80); //begin for ist line
	delay(500);
	 string("himani");
				
		}		
	}


