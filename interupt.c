/****�ߵ�λ�ƻ�������ʱ����ʽ*******/
/******by������************/

#include<reg51.h>
#define LED p1							//����LED��Port1
#define count 100000					//T0(M1)����ֵ��Լ0.1��
#define TH_M1 (65536-count)/256			//T0������8λ
#define TL_M1 (65536-count)%256			//T0������8λ

int main()								//������
{
	int i;								//�жϴ���
	TMOD=TMOD&0xf1;						//����T0Ϊmode1
	TMOD=TMOD|0x01��
	LED=0xf0;							//LED��ʼֵ11110000���ұ�4 ����
	while(1)
	{
		for(i=0;i<10;i++)				//��ʱ�ж�10��
		{
			TH0=TH_H1;					//���ø�8λ
			TL0=TL_M1;					//���õ�8λ
			TR0=1;						//����T0
			while(TF0==0);				//�ж��Ƿ����
			TF0=0;						//��������TF0���ر�T0
		}
		LED=~LED;						//�������
	}
}