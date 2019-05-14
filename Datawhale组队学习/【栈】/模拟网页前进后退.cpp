#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int stack[100];
	int top;
}SeqStack;

//��ʼ��ջ��������ջ�� 
SeqStack *InitStack()
{
	SeqStack *S;
	S=(SeqStack *)calloc(1,sizeof(SeqStack));
	if (!S)
	{
		printf("Stack creation failed��");
		return NULL; 
	}
	else
	{
		S->top=-1;
		return S;
	}
}

//�ж��Ƿ�Ϊ��ջ
int StackEmpty(SeqStack *S)
{
	return (S->top==-1?0:1);
}

//ȡջ��Ԫ��
int StackTop(SeqStack *S)
{
	if (StackEmpty(S))
	{
		printf("Stack Empty\n");
		return NULL;
	}
	else
		return S->stack[S->top];	
}

//��ջ  
SeqStack *Push(SeqStack *S,int x)
{
	if (S->top==100-1)
	{
		printf("Stack Full\n");
		return NULL; 
	}
	else
	{
		S->top++;
		S->stack[S->top]=x;
		return S;
	}
}

//ǰ�� 
void *GoAhead(SeqStack *ahead,SeqStack *back)
{
	if (back->top==0) //�����ʼ�����ҳ��1 
	{
		printf("Can't go ahead\n");
		return NULL; 
	}
	else
	{
		ahead->top++;
		ahead->stack[ahead->top]=back->stack[back->top];
		back->top--;
	}
}

//���� 
void *GoBack(SeqStack *ahead,SeqStack *back)
{
	if (ahead->top==-1) //������������ҳ��6 
	{
		printf("Can't go ahead\n");
		return NULL; 
	}
	else
	{
		back->top++;
		back->stack[back->top]=ahead->stack[ahead->top];
		ahead->top--;
	}
}

//���ջ
void StackPrint(SeqStack *S)
{
	int t;
	t=S->top;
	if (S->top==-1)
		printf("Empty Stack!\n");
	else
		while (t!=-1)
		{
			if (t!=0)
				printf("%d->",S->stack[t]);
			else
				printf("%d\n",S->stack[t]);
			t--;
		}
}

int main()
{
	int a[6]={1,2,3,4,5,6};
	SeqStack *ahead,*back;
	
	ahead=InitStack();
	back=InitStack();
	
	//��ǰҳ��Ϊҳ��3 
	//�����ҳ��1��2��3 
	for (int i=0;i<3;i++)
		Push(back,a[i]);
	//�Ѻ��˵�ҳ��4��5��6 
	for (int i=5;i>=3;i--)
		Push(ahead,a[i]);
	StackPrint(back);
	StackPrint(ahead);
	printf("��ǰҳ�棺%d\n",back->stack[back->top]);
	
	GoAhead(ahead,back);	
	StackPrint(back);
	StackPrint(ahead);
	printf("��ǰҳ�棺%d\n",back->stack[back->top]);
	GoBack(ahead,back);
	GoBack(ahead,back);
	StackPrint(back);
	StackPrint(ahead);
	printf("��ǰҳ�棺%d\n",back->stack[back->top]);	
	return 0;
}
