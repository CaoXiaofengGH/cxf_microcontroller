/**LED���ʽ�ߵ͵�ƽ������˸����**/
/****by������****/

#include <reg51.h>
#define LED P2          //����LED�ӵ�Port2
void delay(int);

int main()
{
	LED=0x55;			//��ʼֵΪ01010101��״̬Ϊżλ������λ��������������
	while(1)			//ѭ��
	{
		delayms(5);		//������ʱ��������ʱ5mS
		LED=~LED;		//�ı�P2״̬����λȡ��
	}
return 0;
}

 void delayms(int ms)	//��ʱ�������
 {
	 int i,j;
	 for(i=0;i<ms;i++)
		 for(j=0;j<125;j++)	//12M����
 }