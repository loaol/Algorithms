#include<stdio.h>
#include<stdlib.h>

typedef struct DNode
{
	int data;
	struct DNode *next;
	struct DNode *prior;
}DNode,*DLinkList;

int InitDList(DLinkList &head)
{
	head=(DLinkList)calloc(1,sizeof(DLinkList));
	if (head==NULL)
		return 0;
	head->next=head->prior=NULL;
	return 1;
 }
 
 DLinkList CreateList_L(DLinkList &head,int n)
{
    while(n--)
    {
        DLinkList p=(DLinkList) calloc(1,sizeof(DNode)); //��̬�����µĽ��
        scanf("%d",&p->data);   //�������ֵ
        p->next=head->next;
        head->next=p; //���뵽��ͷ
        p->prior=head->prior;
        head->prior=p;
    }
    return head;
}
 
 //�ڵ�i��λ�ú����Ԫ��e 
int ListInsert_L(DLinkList &head,int i,int e)
{
    DLinkList p=head;
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
    DLinkList q=(DLinkList) calloc(1,sizeof(DNode)); //��̬�����µĽ��
    q->data=e;     //��e��ֵ�����µĽ��
    q->next=p->next;
    p->next=q; //��i-1λ��֮������µĽ��
    q->prior=p->prior;
    p->prior=q;
    return 1;
}

//ɾ����i��Ԫ�� 
int ListDelete_L(DLinkList &head,int i)
{
	int j;
	DLinkList t1,t2;
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
	t2->prior=t1->prior;
	free(t1);
	return 1;
}

void ListPint_L(DLinkList &head)
{
	DLinkList p;
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
	DLinkList head;
	InitDList(head);
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
