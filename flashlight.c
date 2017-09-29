/**LED间隔式高低电平交替闪烁程序**/
/****by曹晓峰****/

#include <reg51.h>
#define LED P2          //定义LED接到Port2
void delay(int);

int main()
{
	LED=0x55;			//初始值为01010101，状态为偶位亮，奇位不亮（共阳极）
	while(1)			//循环
	{
		delayms(5);		//调用延时函数，延时5mS
		LED=~LED;		//改变P2状态，按位取反
	}
return 0;
}

 void delayms(int ms)	//延时毫秒程序
 {
	 int i,j;
	 for(i=0;i<ms;i++)
		 for(j=0;j<125;j++)	//12M晶振
 }