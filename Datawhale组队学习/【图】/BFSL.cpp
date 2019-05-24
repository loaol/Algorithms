#include<stdio.h>
#include<stdlib.h>
#define N 5

typedef struct node *pointer;
struct node
{
	int vertex;
	int data; 
	struct node *next;
}nnode;
typedef struct
{
	int data;
	pointer first;
}head;
typedef struct
{
	head AdjList[N];
	int n,e;
}lkgragh;
typedef struct
{
	int data[10];
	int front;
	int rear;
}seqqueue;

int Nodes[5][3]={{1,2,2},{2,3,9},{0,3,11},{1,4,5},{4,2,7}};
int visid[6]={};

void CreatGragh(lkgragh *ga)
{
	//������ʼ��
	ga->n=5;
	for (int i=0;i<ga->n;i++)
	{
		ga->AdjList[i].first=NULL;
		ga->AdjList[i].data=i; 
	}
	ga->e=sizeof(Nodes)/sizeof(Nodes[0]);
	for (int i=0;i<ga->e;i++)
	{
		pointer p=(pointer)malloc(sizeof(struct node));
		p->vertex=Nodes[i][1];
		p->next=ga->AdjList[Nodes[i][1]].first;
		p->data=Nodes[i][2];
		ga->AdjList[Nodes[i][0]].first=p;
		
		p=(pointer)malloc(sizeof(struct node));
		p->vertex=Nodes[i][0];
		p->next=ga->AdjList[Nodes[i][0]].first;
		p->data=Nodes[i][2];
		ga->AdjList[Nodes[i][1]].first=p;
	}
}

//��ʼ������ 
void init_seqqueue(seqqueue &q)
{
	q.front = q.rear = 0;
}
 
//�ж϶����Ƿ�Ϊ�� 
int empty_seqqueue(seqqueue &q)
{
	if(q.front == q.rear)
		return 1;
	else
		return 0;
}
 
//Ԫ����Ӳ��� 
int en_seqqueue(seqqueue &q,int x)
{
	//���������޷���� 
	if((q.rear + 1) % 10 == q.front)
	{
		printf("����\n"); 
		return 0;
	}
	q.rear = (q.rear + 1) % 10;
	q.data[q.rear] = x;
	return 1; 
}
 
//Ԫ�س��Ӳ��� 
int de_seqqueue(seqqueue &q,int &x)
{
	//���ӿ����޷����� 
	if(q.front == q.rear)
	{
		printf("�ӿ�\n");
		return 0;
	}
	q.front = (q.front + 1) % 10;
	x = q.data[q.front];
	return 1;
}

//vΪ��ʼ�ĵ� 
void BFSL(lkgragh *ga,int v)
{
	pointer p;
	seqqueue q;
	
	init_seqqueue(q);
	printf("���ʳ����� %d\n",v);
	visid[v]=1;
	en_seqqueue(q,v);
	while(!empty_seqqueue(q))
	{
		de_seqqueue(q,v);
		p=ga->AdjList[v].first;
		while (p!=NULL)
		{
			if (!visid[p->vertex])
			{
				printf("%d ",p->vertex);
				visid[p->vertex]=1;
				en_seqqueue(q,p->vertex);
			}
			p=p->next;
		}
	}
}

int main()
{
	lkgragh ga[6];
	CreatGragh(ga);
	BFSL(ga,1);
	//���ʲ���1�� 
	return 0;
}
