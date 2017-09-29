/****高低位灯互闪，定时器方式*******/
/******by曹晓峰************/

#include<reg51.h>
#define LED p1							//定义LED接Port1
#define count 100000					//T0(M1)计数值，约0.1秒
#define TH_M1 (65536-count)/256			//T0计数高8位
#define TL_M1 (65536-count)%256			//T0计数低8位

int main()								//主程序
{
	int i;								//中断次数
	TMOD=TMOD&0xf1;						//设置T0为mode1
	TMOD=TMOD|0x01；
	LED=0xf0;							//LED初始值11110000，右边4 灯亮
	while(1)
	{
		for(i=0;i<10;i++)				//定时中断10次
		{
			TH0=TH_H1;					//设置高8位
			TL0=TL_M1;					//设置低8位
			TR0=1;						//启动T0
			while(TF0==0);				//判断是否溢出
			TF0=0;						//溢出后，清除TF0，关闭T0
		}
		LED=~LED;						//输出反向
	}
}