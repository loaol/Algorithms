#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t,n=0;
	int *array;
	array=(int*)calloc(5,sizeof(int)); //����5������Ϊint���ڴ�ռ� 
	if (!array) //�ж��Ƿ�����ɹ� 
    {
        printf("����ʧ�ܣ�");
		return 0; 
    }
	while (1)
	{	
		//���� 
		scanf("%d",&t);
		if (t==0) //����0������������� 
			break;
		*(array+n)=t;
		n++;
    	if (n%5==0) //������ˣ�������2��ԭ�������� 
    		array=(int*)realloc(array,2*n*sizeof(int));
	}
	printf("----���----\n");
	for(int i=0;i<n;i++)
		printf("%d ",array[i]);
	putchar('\n');
	free(array); //�ͷ��ڴ� 
	return 0;	
}
