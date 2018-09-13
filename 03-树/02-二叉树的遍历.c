#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TreeNode{
	ElementType data;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
}BinTree;


// 先序遍历
void preRecursion(BinTree *bt){
	if(bt){
		printf(" <%d> ", bt->data);
		preRecursion(bt->lchild);
		preRecursion(bt->rchild);
	}
}

// 中序遍历
void inRecursion(BinTree *bt){
	if(bt){
		preRecursion(bt->lchild);
		printf(" <%d> ", bt->data);
		preRecursion(bt->rchild);
	}
}

// 后序遍历
void postRecursion(BinTree *bt){
	if(bt){
		preRecursion(bt->lchild);
		preRecursion(bt->rchild);
		printf(" <%d> ", bt->data);
	}
}

int main()
{

	return 0;
}
