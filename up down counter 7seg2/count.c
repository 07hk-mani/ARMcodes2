
#include<lpc21xx.h>

void delay(int n)
{
 unsigned int i,j;
	for(i=0;i<n;i++)
	{
	 for(j=0;j<=1000;j++);
	}
}


int main()
{
	int j,k;
	int a[10]={0x3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X67};
	
 PINSEL1=0X00000000;
 IODIR0=0XFFFFFFFF;
		 
	while(1)
 { 
	for(k=0;k<10;k++)
  {
			for(j=0;j<=9;j++)
   {
			IOCLR0=0X100;
	 	  IOSET0=0X200;
		  IOSET0=a[k];
		  delay(90);
			IOCLR0=a[k];
			IOCLR0=0X200;
			IOSET0=0X100;
			IOSET0=a[j];
		  delay(80);
		 IOCLR0=a[j];
		
}	
}

}
}
