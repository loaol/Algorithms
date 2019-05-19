#define PAGES 12  /*ҳ������ҳ��*/
#define M 3      /*��ǰ���������ҵ���������*/
//#define M 4
/*ҳ�����ô�*/
int page[PAGES] =  {4,3,2,1,4,3,5,4,3,2,1,5};
int rel[M][PAGES];   /*�洢�������*/
/*�ڴ������ṹ��*/
typedef struct{
  int pnum;     /*�ÿ��������ҳ���*/
  int tm;       /*�����һ�ε�����������ʱ��*/
}PBlock;
/*��ʼ�����������*/
void init(PBlock *pb)
{
  int i,j;
  //pb = (PBlock*)malloc(sizeof(PBlock)*M);
  for(i=0;i<M;i++){
    pb[i].pnum = -1;
    pb[i].tm = -1;
    for(j=0;j<PAGES;j++){
      rel[i][j] = -1;
    }
  }
}
/*��ӡ�������*/
void printRelArr(int rel[M][PAGES])
{
  int i,j;
  for(i=0;i<M;i++){
    for(j=0;j<PAGES;j++){
      if(rel[i][j]==-1)
        printf("_ ");
      else
        printf("%d ",rel[i][j]);
    }
    printf("\n");
  }
}
/*��ӡһά����*/
void printArr1(int *arr,int n)
{
    int i;
    for(i=0;i<n;i++){
      printf("%d ",arr[i]);
    }
    printf("\n");
}
/*�鿴ҳ���Ϊnum��ҳ���Ƿ����ڴ����,���ڷ���1*/
int in_mem(int num,PBlock *pb,int m)
{
  int i;
  int b = 0;
  for(i=0;i<m;i++){
      if(pb[i].pnum == num){
        b = 1;
        break;
      }
  }
  return b;
}
/*��������õĿ�*/
int getP(PBlock *pb,int p)
{
  int i;
  bool out = true;  //
  for(i=0;i<M;i++){
    if(pb[i].tm == -1){
      p = i;
      out = false;
      break;
    }
  }
  if(out){
    for(i=0;i<M;i++){
      if(pb[i].tm>pb[p].tm)
        p = i;
    }
  }
  return p;
}
int getEQnum(int num,PBlock *pb)
{
  int i;
  int in = -1;
  for(i=0;i<M;i++){
    if(pb[i].pnum == num){
      in = i;
      break;
    }
  }
  return in;
}
/*LRU�㷨*/
void lru(PBlock *pb,int m)
{
  int lps=0;   /*ȱҳ����*/
  double lpp;   /*ȱҳ��*/
  int p = 0;    /*�滻ָ��*/
  int index =0;  /*ҳ�������*/
  while(index<PAGES){
      if(!in_mem(page[index],pb,m)){   /*���ҳ�治���������*/
        p = getP(pb,p);
        pb[p].pnum = page[index];
        pb[p].tm = 0;
        lps++;
        for(int i=0;i<M;i++){
          rel[i][index] = pb[i].pnum;
        }
      }else{                         /*���ҳ�����������*/
        int in = getEQnum(page[index],pb);  /*��ȡ��ҳ����������е�����*/
          pb[in].tm = 0;
      }
      int i;
      for(i=0;i<M;i++){
          if(i!=p&&pb[i].tm!=-1){
            pb[i].tm++;
          }
      }
      index++;
  }
  printf("LRU�㷨����ȱҳ����Ϊ %d \n",lps);
  lpp = 1.0*lps/PAGES;
  printf("LRU�㷨ȱҳ��Ϊ: %0.4lf\n",lpp);
  printf("ҳ�������Ϊ:\n");
  printArr1(page,PAGES);
  printf("LRU�������Ϊ:\n");
  printRelArr(rel);
}
int main()
{
    //printArr(rel);
  PBlock pb[M];
  init(pb);
  fifo(pb,M);
  init(pb);
  lru(pb,M);
  return 0;
}
