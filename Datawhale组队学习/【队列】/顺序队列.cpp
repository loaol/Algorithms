//˳�����
#include <stdio.h>
#include <stdlib.h>
#define Maxsize 20
 
//������еĽṹ�� 
typedef struct Squeue{
	int data[Maxsize];
	int front;
	int rear;
}Squeue; 
 
//��ʼ������ 
void InitQueue(Squeue &qu)
{
	qu.front = qu.rear = 0;
}
 
//�ж϶����Ƿ�Ϊ�� 
int isQueueEmpty(Squeue qu)
{
	if(qu.front == qu.rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
 
//Ԫ����Ӳ��� 
int inQueue(Squeue &qu,int x)
{
	//���������޷���� 
	if((qu.rear + 1) % Maxsize == qu.front)
	{
		return 0;
	}
	qu.rear = (qu.rear + 1) % Maxsize;
	qu.data[qu.rear] = x;
	return 1; 
}
 
//Ԫ�س��Ӳ��� 
int deQueue(Squeue &qu,int &x)
{
	//���ӿ����޷����� 
	if(qu.front == qu.rear)
	{
		return 0;
	}
	qu.front = (qu.front + 1) % Maxsize;
	x = qu.data[qu.front];
	return 1;
}
 
int main()
{
	Squeue q;
	int i , n , x , a;
	InitQueue(q);
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%d",&a);
		inQueue(q,a);
	}
	//�����зǿ�ʱ������������������� 
	while(!isQueueEmpty(q))
	{
		deQueue(q,x);
		printf("%d ",x);
	}
	return 0;
}
