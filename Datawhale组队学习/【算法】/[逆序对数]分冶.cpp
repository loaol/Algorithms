#include <stdio.h> 
 
int count=0;

void Merge(int r[],int r1[],int s,int m,int t)	// �ϲ�������
{
	int i=s,j=m+1,k=s;
	int b;
	while(i<=m && j<=t){
		if(r[i]<=r[j]){       // ȡ��С�߷���r1[k]��
			r1[k++]=r[i++];
		}
		else{                 	
			count+=m-i+1;	// ������������ұ�������������������������ڸ��ұ���		
			b=i;              
			while(b<=m){
				printf("[%d,%d]\n",r[b],r[j]);
				b++;
			}
			r1[k++]=r[j++];
		}
 
	}
	while(i<=m)			// ����һ��������û�����꣬�������β����;��ͬ
		r1[k++]=r[i++];
	while(j<=t)
		r1[k++]=r[j++];
}

// ������r[s]~r[t]���й鲢����
void MergeSort(int r[],int s,int t)
{  
	int m,r1[1000],i;
	if(s==t)
		return ;
	else{
		m=(s+t)/2;	       // ����
		MergeSort(r,s,m);     // ������1
		MergeSort(r,m+1,t);   // ������2
		Merge(r,r1,s,m,t);    // �ϲ�
		for(i=s;i<=t;i++)
			r[i]=r1[i];
	}
}

int main()
{
	int r[]={23,13,35,6,19,50,28,38,26,17,45},i;
	MergeSort(r,0,10);		// ���������ֱ�Ϊ�������顢��ʼ�±ꡢ��ֹ�±�
	for(i=0;i<=10;i++)
		printf("%d ",r[i]);
	printf("\nһ�� %d�������\n",count);
	return 0;
}
