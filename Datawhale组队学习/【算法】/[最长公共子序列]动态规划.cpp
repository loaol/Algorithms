#include<stdio.h>  
#include<string.h>  
char a[101],b[101];  
char num[102][102];//��¼�м���������  
//��̬�滮���ö�ά��������ʶ�м�������������ظ��ļ��������Ч��
void LCS(int lena,int lenb){ 
    for(int i=1;i<=lena;i++){
        for(int j=1;j<=lenb;j++){
            if(a[i-1]==b[j-1]){//ע��������±���i-1��j-1  
                num[i][j]=num[i-1][j-1]+1;
            }  
            else{
                num[i][j]=num[i][j-1] > num[i-1][j] ? num[i][j-1] : num[i-1][j];
            }  
        }  
    }  
}
int main(){  
    scanf("%s%s",&a,&b);//�����ַ���
    int lena = strlen(a);//��ȡ�ַ������� 
    int lenb = strlen(b);
    memset(num,0,sizeof(num));//���鸳��ֵ  
    LCS(lena,lenb);
    printf("%d",num[lena][lenb]); 
    return 0;
}
