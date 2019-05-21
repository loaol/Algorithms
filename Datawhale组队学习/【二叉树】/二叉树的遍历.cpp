#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10001

typedef struct biTree{
	int data;
	struct biTree * lchild, * rchild;
}biTree, *bipts;// �����Ķ��������

bipts createBiTree(bipts bt){
	// ��δ��������֮ǰ�Ĳ��ġ���C���ԡ�������ո�������ַ�����
    char read[10001];
    int input;
    int i = 0;
    int j = 0;// initialize
    int k = 0;
    int convert[10001];// char -> int
    while(1){
        input = getchar();
        read[j] = input;
        j++;
        if(input == ' ' || input == '\n' || input == EOF){
            read[j-1] = '\0';
            convert[i] = atoi(read);
            i++;
            memset(read, 0, sizeof(read));
            j = 0;
            if(input == '\n' || input == EOF){
                convert[i] = -1;
                convert[i+1] = '\0';
                break;
            }
        }
    }
	int front, rear;// �ֱ��סǰ������ͺ������
	int ch;
	int node = 0;// ��ס�ǵڼ�������
	bipts p, Queue[MAX];
	front = 1,rear = 0;
	// �����������������������0(������Ϊ-1)
	while((ch = convert[node]) != -1){
        node++;
		p = NULL;
		if(ch != 0){
			p = (bipts)malloc(sizeof(biTree));
			p->data = ch;
			p->lchild = p->rchild = NULL;
		}
		rear++;
		Queue[rear] = p;
		if(rear == 1){
			bt = p;
		}
		// ��������
		else{
		// �۲췢��ż����λ�����ֻᱻinsert����ߣ�����������ұ�
			if(p != NULL && Queue[front] != NULL){
				if(rear % 2 == 0){
					Queue[front]->lchild = p;
				}
				else{
					Queue[front]->rchild = p;
				}
			}
			if(rear % 2 == 1){
				front++;
			}
		}
	}
	return bt;
}

// ��inorder���һ��
int inOrderTraverse(bipts bt){
	if(bt!=NULL){
		inOrderTraverse(bt->lchild);
		printf("%d ",bt->data);
		inOrderTraverse(bt->rchild);
	}
	return 0;
}

int main(){
    int total_num;
    bipts bt;
    bt=(bipts)malloc(sizeof(biTree));
    bt=createBiTree(bt);
    inOrderTraverse(bt);
return 0;
}
