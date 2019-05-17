#include <stdio.h>
#include <stdlib.h>

void ShellSort(int a[], int length)
{
	int increment;
	int i,j;
	int temp;
	for(increment = length/2; increment > 0; increment /= 2) //�������Ʋ���,���ݼ���1
	{
		// i�ӵ�step��ʼ���У�ӦΪ��������ĵ�һ��Ԫ��
		// �����Ȳ������ӵڶ�����ʼ����
		for(i = increment; i < length; i++)
		{
			temp = a[i];
			for(j = i - increment; j >= 0 && temp < a[j]; j -= increment)
			{
				a[j + increment] = a[j];
			}
			a[j + increment] = temp; //����һ��λ������
		}
	}
}
 
void PrintArray(int *a,int n)
{
	for (int i=0;i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main()
{
	int n=10;
	int a[] = {10,6,7,1,3,9,4,2,5,8};
	ShellSort(a,n);
	PrintArray(a,n);
	return 0;
} 
