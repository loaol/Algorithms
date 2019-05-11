#include<stdio.h>
#include<stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;

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
    LinkList p,tmp=head;
    p=head->next;
    for (int j=1;j<i;j++)
    	if (p)
    	{
    		p=p->next;
    		tmp=tmp->next;
		}
		else
			break;
	if (!p||i<1)
	{	printf("��������ȷ��iֵ��\n");
		return 0;
	}
    tmp->next=p->next;  //ɾ����i��λ���ϵ�ֵ
    free(p);    //�ͷ�iλ���ϵĿռ�
    return 1;
}

void ListPint_L(LinkList head)
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
