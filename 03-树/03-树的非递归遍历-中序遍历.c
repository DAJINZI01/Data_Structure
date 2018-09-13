#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct BTNode{
	ElementType data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BinTree, BTNode;

/*
 * 中序非递归遍历算法
 * 遇到一个节点，就把它压栈，并去遍历它的左子树
 * 当 左子树遍历结束 后，从栈顶弹出这个节点并访问它
 * 然后按其右指针在去 中序遍历 该节点的右子树
 * */

typedef struct LNode{
	BTNode *bt;
	struct LNode *next;	
}LinkStack, LNode;


void createLNode(LNode **node){
	LNode *temp = NULL;
	if(node == NULL)
		return;
	temp = (LNode *)malloc(sizeof(LNode));
	if(temp == NULL){
		printf("分配内存失败");
		return;
	}
	temp->bt = NULL;
       	temp->next = NULL;	
}

void createStack(LNode **stack){
	if(stack == NULL)
		return;

	LNode *temp = NULL;
	createLNode(&temp);
	*stack = temp;
}

void pop(LNode *stack, BTNode **node){
	if(stack == NULL || node == NULL)
		return;
	if(stack->next == NULL)
		return;
	LNode *temp = NULL;
	temp = stack->next;
	*node = temp->bt;
	stack->next = stack->next->next;
	free(temp);
}

void push(LNode *stack, BTNode *node){
	if(stack == NULL || node == NULL)
		return;
	LNode *temp = NULL;
	createLNode(&temp);
	temp->bt = node;
	temp->next = stack->next;
	stack->next = temp;// 头插法
}

void destoryStack(LNode *stack){
	if(stack ==  NULL)
		return;
	LNode *p = stack;
	LNode *temp = NULL;
	while(p){
		temp = p->next;
		p->next = temp->next;
		free(temp);	
	}
	free(stack);
}

int isEmpty(LNode *stack){
	if(stack == NULL)
		return 1;
	return (stack->next == NULL);
}
/*
 * push的顺序为先序遍历
 * pop的顺序为中序遍历
 *
 *
 * */

// 中序非递归遍历
void inRecursion(BinTree *bt){
	if(bt == NULL)
		return;
	BinTree *tree = bt;
	LinkStack *stack = NULL;
	createStack(&stack);

	while(tree != NULL || !isEmpty(stack)){// 可能出现栈空，但是右子树存在

		while(tree != NULL){
			// 一直向左并将沿途的节点压栈
			push(stack, tree);// ①
			tree = tree->lchild;
		}

		if(!isEmpty(stack)){
			// 弹出节点
			pop(stack, &tree);// 根节点 // ②
			printf(" <%c> ", tree->data);// （访问）打印节点
			tree = tree->rchild;// 转向右子树
		}	
	}

	destoryStack(stack);
}

int main()
{
	LinkStack *stack = NULL;
	createStack(&stack);	
	
	int i = 0;
	for(i = 0; i < 10; ++i){
		//push(stack, i+100);	
	}

	ElementType item = 0;
	for(i = 0; i < 10; ++i){
		//pop(stack, &item);	
		printf(" <%d> ", item);
	}

	destoryStack(stack);
	printf("hello world\n");

	return 0;
}
