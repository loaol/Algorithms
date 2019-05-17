#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
 
//����鲢
void _Merge(int *a, int begin1, int end1, int begin2, int end2, int *tmp)
{
	int index = begin1;
	int i = begin1, j = begin2;
	//ע��:�����ֵ������㹻Сʱ,begin1==end1,begin2==end2
	while (i <= end1&&j <= end2){
		if (a[i]<=a[j])
			tmp[index++] = a[i++];
		else
			tmp[index++] = a[j++];
	}
	//�����Ԫ����䵽tmp��
	while (i <= end1)
		tmp[index++] = a[i++];
	//���ұ�Ԫ������tmp��
	while (j <= end2)
		tmp[index++] = a[j++];
	//��tmp�е����ݿ�����ԭ�����Ӧ����������
	//ע��:end2-begin1+1
	memcpy(a + begin1, tmp + begin1, sizeof(int)*(end2 - begin1 + 1));
}

//�鲢����
void MergeSort(int *a, int left, int right, int *tmp)
{
	if (left >= right)
		return;
	assert(a);
	//mid���������
	int mid = left + ((right - left) >> 1);
	//��߹鲢����,ʹ��������������
	MergeSort(a, left, mid, tmp);
	//�ұ߹鲢����,ʹ��������������
	MergeSort(a, mid + 1, right, tmp);
	//����������������ϲ�
	_Merge(a, left, mid, mid + 1, right, tmp);
}

//��ӡ����
void PrintArray(int *a, int len)
{
	assert(a);
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main()
{
	int a[] = { 10, 6, 7, 1, 3, 9, 4, 2 };
	int *tmp = (int *)malloc(sizeof(int)*(sizeof(a) / sizeof(int)));
	if (!tmp)
	{
		printf("����ʧ��"); 
	}
	memset(tmp, -1, sizeof(a) / sizeof(int));
	MergeSort(a, 0, sizeof(a) / sizeof(int)-1, tmp);
	PrintArray(a, sizeof(a) / sizeof(int));
	system("pause");
	return 0;
} 
