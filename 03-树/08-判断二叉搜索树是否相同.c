#include <stdio.h>

typedef struct BTNode{
	int value;
	struct BTNode *lchild;
	struct BTNode *rchild;	
	int flag;
}LNode;

/*
 * 1、搜索树的表示
 * 2、建搜索树T
 * 3、判别一个序列是否与搜索树相同
 *
 *
 * */

int main()
{
	int N, L, i;
	BTNode *T;
	scanf("%d", &N);
	while(N){
		scanf("%d", &L);	
		T = createTree(N);
		for(i = 0; i < L; i++){
			if(judge(T, N))
				printf("yes\n");
			else
				printf("no\n");
			resetT(T);// 清除T中的标记
		}
		freeTree(T);
		scanf("%d", &N);
	}


	return 0;
}
