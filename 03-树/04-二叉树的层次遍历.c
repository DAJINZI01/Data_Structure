#include <stdio.h>
#include <stdlib.h>
#define MaxSize 1024

typedef char ElementType;

typedef struct BTNode{
	ElementType data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BinTree, BTNode;


/*
 * 二叉树遍历的核心问题：二维结构的线性化
 * 	从节点访问其左右儿子节点
 * 	访问左儿子后，右儿子节点怎么办？
 * 		需要一个存储结构保存暂时不访问的节点
 * 		栈保存的是自己，队列保存的是右儿子
 * 队列实现：遍历从根节点开始，首先将根节点入队，然后开始执行
 * 循环：节点出队，访问该节点，其左右儿子入队
 *
 * 1、从队列取出一个元素
 * 2、访问该元素所指的节点
 * 3、若该元素的所指的节点的左右孩子节点非空
 * 	则将其左右孩子的指针 顺序 入队列
 * */

void level(BinTree *bt){
	if(bt == NULL)
		return;

	BTNode *queue[MaxSize] = {0};
	BTNode *temp;
	int front, rear;
	front = rear = 0;

	// 根节点入队列
	rear = (rear + 1) % MaxSize;
	queue[rear] = bt;

	// 开始循环
	while(front != rear){// 队列不空的时候
		// 出队列
		front = (front + 1) % MaxSize;
		temp = queue[front];
		// （访问）
		printf(" <%c> ", temp->data);

		if(temp->lchild != NULL){// 左孩子不空，入队
			rear = (rear + 1) % MaxSize;
			queue[rear] = temp->lchild;
		}
		if(temp->rchild != NULL){// 右孩子不空，入队
			rear = (rear + 1) % MaxSize;
			queue[rear] = temp->rchild;
		}
	}


}

int main(){

	return 0;
}
