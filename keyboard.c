/****ֱ��ʽ��������LED�Ƴ���**********/
/**LED��������P1�ڣ����̽�P2��******/
/***********by������*********/

#include <reg51.h>
#define LED P1
unsigned char Read_Keyboard();		//�������ֵ����
void Func1();						//����4��LED״̬����
void Func2();
void Func3();

int main() //������
{
	unsigned char Keyboard_Status;	// �����ֵ
	LED=0xff;						//����LED��ʼֵΪ11111111��ȫ��
	while(1)						//����ѭ��
	{
		Keyboard_Status = Read_Keyboard(); // ��ȡ����ֵ
		if(Keyboard_Status==0x01)			//�����ֵ=1
		{Func1();}							//���ú���1
		else if(Keyboard_Status==0x02)		 //�����ֵ=2
		{Func2();}
		else if(Keyboard_Status==0x03)		 //�����ֵ=3
		{Func3();}

	}
	return 0;
}

unsigned char Read_Keyboard()				//�����ֵ�ӳ���
{
	unsigned char Keys_Value;			// �����ֵ����
	P2 = 0xff;							// P2���ø�(��P2��дff)��׼����ȡP2�񰴼�״̬
	Keys_Value = P2;					// ��ȡ����״̬
	return Keys_Value;					// ���ذ���״ֵ̬
}

void Func1()							//����LED=0101
{LED=0x55}
void Func2()							//����LED=00001111
{LED=0x0f}
void Func3()							//����LED=11110000
{LED=0xf0}
