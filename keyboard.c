/****直接式按键控制LED灯程序**********/
/**LED共阴极接P1口，键盘接P2口******/
/***********by曹晓峰*********/

#include <reg51.h>
#define LED P1
unsigned char Read_Keyboard();		//定义读键值函数
void Func1();						//声明4种LED状态函数
void Func2();
void Func3();

int main() //主程序
{
	unsigned char Keyboard_Status;	// 定义键值
	LED=0xff;						//设置LED初始值为11111111，全亮
	while(1)						//无限循环
	{
		Keyboard_Status = Read_Keyboard(); // 读取按键值
		if(Keyboard_Status==0x01)			//如果键值=1
		{Func1();}							//调用函数1
		else if(Keyboard_Status==0x02)		 //如果键值=2
		{Func2();}
		else if(Keyboard_Status==0x03)		 //如果键值=3
		{Func3();}

	}
	return 0;
}

unsigned char Read_Keyboard()				//读入键值子程序
{
	unsigned char Keys_Value;			// 定义键值变量
	P2 = 0xff;							// P2口置高(向P2口写ff)，准备读取P2获按键状态
	Keys_Value = P2;					// 读取按键状态
	return Keys_Value;					// 返回按键状态值
}

void Func1()							//设置LED=0101
{LED=0x55}
void Func2()							//设置LED=00001111
{LED=0x0f}
void Func3()							//设置LED=11110000
{LED=0xf0}
