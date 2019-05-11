#include<stdio.h>
#include<stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;

int InitCList(LinkList &head)
{
	head=(LinkList)calloc(1,sizeof(LinkList));
	if (head==NULL)
		return 0;
	head->next=head;
	return 1;
 }
 
 LinkList CreateList_L(LinkList &head,int n)
{
    head=(LinkList) calloc(1,sizeof(LNode));  //�Ƚ���һ����ͷ���ĵ�����
    head->next=NULL; //��ʼ�� 
    while(n--)
    {
        LinkList p=(LinkList) calloc(1,sizeof(LNode)); //��̬�����µĽ��
        scanf("%d",&p->data);   //�������ֵ
        p->next=head->next;
        head->next=p; //���뵽��ͷ
    }
    return head;
}
 
 //�ڵ�i��λ�ú����Ԫ��e 
int ListInsert_L(LinkList &head,int i,int e)
{
    LinkList p=head;
    p=p->next;
    for (int j=1;j<i;j++)
    	if (p)
    		p=p->next;
    	else
    		break;
	if (!p||i<1)
	{
		printf("��������ȷ��iֵ��\n");
		return 0;
	}
    LinkList q=(LinkList) calloc(1,sizeof(LNode)); //��̬�����µĽ��
    q->data=e;     //��e��ֵ�����µĽ��
    q->next=p->next;
    p->next=q; //��i-1λ��֮������µĽ��
    return 1;
}

//ɾ����i��Ԫ�� 
int ListDelete_L(LinkList &head,int i)
{
	int j;
	LinkList t1,t2;
	j=1;
	t1=head->next;
	t2=head;
	while(j<i&&t1!=head)
	{
		j++;
		t1=t1->next;
		t2=t2->next;
	}
	if(j>i)
		return 0;
	t2->next=t1->next;
	free(t1);
	return 1;
}

void ListPint_L(LinkList &head)
{
	LinkList p;
	p=head->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}

int main()
{
	int i,n;
	char cmd,e;
	LinkList head;
	InitCList(head);
	scanf("%d",&n);
	CreateList_L(head,n);
	ListPint_L(head);
	putchar('\n');
	ListInsert_L(head,2,1);
	ListPint_L(head);
	putchar('\n');
	ListDelete_L(head,2);
	ListPint_L(head);
	return 0;
}
