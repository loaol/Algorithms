#include<stdio.h>
#include<stdlib.h>

void add(int *a,int t)
{	
    if(t>a[9])
        a[10]=t;//�����������
    else
    {
        for(int i=0; i<10; i++)
            if(a[i]>t)
            {
                for(int j=10; j>i; j--)
                    a[j]=a[j-1];//��������һλ
                a[i]=t;
                break;
            }
    }
}

void del(int *a,int t)
{
	for(int i=0;i<10;i++)
	{	if (a[i]!=t)
			continue;
		else
		{
			for(int j=i;j<10;j++)
            	a[j]=a[j+1];//�����ν�һλ
            a[10]=0;
            break;
		}		
	}
}

int main()
{
    int a[11]= {1,2,3,4,5,6,7,8,9,10};
    int number,l;
    printf("�������������('add'--1,'del'--2):");
    scanf("%d",&l);
    printf("��������Ҫ����������");
	scanf("%d",&number);
    if (l==1)
    	add(a,number);
    else
    	del(a,number);
	int i=0;
    while (a[i]!=0)
    {	printf("%d ",a[i]);
    	i++;
	}
	return 0;
}
