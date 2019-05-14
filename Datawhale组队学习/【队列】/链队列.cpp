#include<stdio.h>
#include<stdlib.h>
#define TRUE   1
#define FALSE  0
#define OK     1
#define ERROR  0
#define OVERFLOW -2
typedef int Status ;
typedef int QElemType;
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
 
//���нṹ����
typedef struct LQueue
{
	QueuePtr front;            //��ͷ
	QueuePtr rear;             //��β
}LQueue;
 
Status Visit(QElemType e);
 
/*�ڶ��еĻ��������ӿڶ���*/
//1-��ʼ��������һ���ն���Q
Status InitLQueue(LQueue &Q);
 
//2-���٣�����һ������Q
Status DestroyLQueue(LQueue &Q);
 
//3-��գ����һ������Q
Status ClearLQueue(LQueue &Q);
 
//4-�Ƿ�Ϊ�ն��У��ж϶����Ƿ�ΪQ��
Status IsLQueueEmpty(LQueue Q);
 
//5-���г��ȣ����ض���Ԫ��Q�ĸ���
int LQueueLength(LQueue Q);
 
//6-��ȡ��ͷԪ�أ���e����Q�Ķ�ͷԪ��
Status GetFrontElem(LQueue Q,QElemType &e);
 
//7-��ӣ�����Q�Ѿ����ڣ�����Ԫ��eΪ���еĶ�βԪ��
Status EnLQueue(LQueue &Q,QElemType e);
 
//8-���ӣ�����Q�ǿգ�ɾ����ͷԪ�أ���e����
Status DeLQueue(LQueue &Q,QElemType &e);
 
//9-����������Q�����ҷǿգ����ζ�Q��ÿ��Ԫ�ص���Visit()��
//���б�����һ��Visitʧ�ܣ������ʧ��
Status LQueueTraverse(LQueue Q,Status (*Visit)(QElemType e));
 
// LQueueTraverse������ ���ʶ����е�һ��Ԫ��e��ʹ�õĺ���
Status Visit(QElemType e)
{
	printf("%d\n",e);
	return OK;
}
 
/*�۶��л�������ʵ��*/
//1-��ʼ��������һ���ն���Q
Status InitLQueue(LQueue &Q)
{
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) exit (OVERFLOW); 
	Q.front->next=NULL;
	return OK;
}
 
//2-���٣�����һ������Q
Status DestroyLQueue(LQueue &Q)
{
	while(Q.front)
	{
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}
	return OK;
}
 
//3-��գ����һ������Q
Status ClearLQueue(LQueue &Q)
{
	QueuePtr p,s;
	Q.rear=Q.front;
	p=Q.front->next;
	s=p;
	while(p)
	{
		s=p->next;
		free(p);
		p=s;
	}
	return OK;
}
 
//4-�Ƿ�Ϊ�ն��У��ж϶����Ƿ�ΪQ��
Status IsLQueueEmpty(LQueue Q)
{
	if(Q.front==Q.rear) 
		return TRUE;
	else 
		return FALSE;
}
 
//5-���г��ȣ����ض���Ԫ��Q�ĸ���
int LQueueLength(LQueue Q)
{
	QueuePtr p;
	int length=0;
	if(Q.front==Q.rear) 
		return 0;
	else
	{
		p=Q.front->next;
		while(p)
		{
		    length++;
		p=p->next;
		}
	}
	return length;
}
 
//6-��ȡ��ͷԪ�أ���e����Q�Ķ�ͷԪ��
Status GetFrontElem(LQueue Q,QElemType &e)
{
	if(Q.front==Q.rear) 
		return ERROR;
	e=Q.front->next->data;
	return OK;
}
 
//7-��ӣ�����Q�Ѿ����ڣ�����Ԫ��eΪ���еĶ�βԪ��
Status EnLQueue(LQueue &Q,QElemType e)
{
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(!p)  exit (OVERFLOW);
	p->data =e;
	p->next =NULL;
	Q.rear->next=p;
	Q.rear =p;
	return OK;
}
 
//8-���ӣ�����Q�ǿգ�ɾ����ͷԪ�أ���e����
Status DeLQueue(LQueue &Q,QElemType &e)
{
	QueuePtr p;
	if(Q.front==Q.rear) return ERROR;
	p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p) Q.rear=Q.front;
	free(p);
	return OK;
}
 
//9-����������Q�����ҷǿգ����ζ�Q��ÿ��Ԫ�ص���Visit()��
//���б�����һ��Visitʧ�ܣ������ʧ��
Status LQueueTraverse(LQueue Q,Status (*Visit)(QElemType e))
{
    QueuePtr p;
	if(Q.front==Q.rear) 
		return ERROR;
	else
	{
		p=Q.front->next;
		while(p)
		{
		    Visit(p->data);
		p=p->next;
		}
	}
	return OK;
}
 
 
void main()
{
	LQueue Q;
	QElemType e;
    int i,a;
    InitLQueue(Q);//��ʼ��
    //�����10���������
	printf("����10�������ڶ����У�");
    for(i=0;i<10;i++)
	{
		scanf("%d",&e);
		EnLQueue(Q,e);
	}
    //����
	printf("��������\n");
	LQueueTraverse(Q, Visit);
  //������5����
	for(i=0;i<5;i++)
	{
		DeLQueue(Q,e);
	}
	//�ٴα���
	printf("�ٴα�������\n");
	LQueueTraverse(Q,Visit);
    a=LQueueLength(Q);
	printf("���г���Ϊ:%d\n",a);
    DestroyLQueue(Q);
	printf("���ٶ��гɹ���\n");
    system("pause");
}
