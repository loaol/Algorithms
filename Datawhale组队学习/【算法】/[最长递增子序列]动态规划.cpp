#include <stdio.h>
#include <stdlib.h>
#define MAXDATA 10000

int main()
{
  int data[MAXDATA]; /*��������*/
  int lgs[MAXDATA];  /*������г���*/
  int n,temp,k; /*n ���г��� temp �����г����м���� */
  
  scanf("%d",&n);
  if(n>10000)
     return 0;      
  for(int i=0;i<n;i++)
    scanf("%d",&data[i]);
    
  for(int i=0;i<MAXDATA;i++)
    lgs[i]=1;  /*��ÿһ�����е���Ϊ�Ҷ�ʱ��������г���Ϊ1*/
  for(int i=1;i<n;i++)
  {
    temp=1;
    for(int j=0;j<i;j++) /*����ǰ���ÿһ�����бȽ�*/
      if(data[i]>data[j]) /*������ݱ�ǰ���ĳһ����ֵ��*/
        if(lgs[i]+lgs[j]>temp) /*�ҳ��õ����������г���*/
          temp=lgs[i]+lgs[j];
    lgs[i]=temp;
  }
  temp=lgs[0];
  for(int i=1;i<n;i++)
    if(lgs[i]>temp)
      temp=lgs[i];
      
  printf("%d",temp);
  return 0; 
}
