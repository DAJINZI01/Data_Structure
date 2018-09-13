#include <stdio.h>
#include <stdlib.h>
#include "linkStack.h"

/*
 * 利用单向链表的头部进行插入和删除，带有头结点
 *
 *
 * */

void createStack(LinkStack **stack){
	if(stack == NULL)
		return;
	LinkStack *s = (LNode *)malloc(sizeof(LNode));
	if(s == NULL){
		printf("内存不足\n");
		return;
	}
	s->next = NULL;
	*stack = s;
}

int isEmpty(LinkStack *stack){
	if(stack == NULL)
		return 1;
	return stack->next == NULL;
}

void push(LinkStack *stack, ElementType item){
	if(stack == NULL)
		return;
	LNode *newNode = (LNode *)malloc(sizeof(LNode));
	if(newNode == NULL){
		printf("内存不足\n");
		return;
	}
	newNode->data = item;
	newNode->next = stack->next;
	stack->next = newNode;	
}

void pop(LinkStack *stack, ElementType *item){
	if(stack == NULL || item == NULL)
		return;
	if(stack->next == NULL)
		return;// 栈空退出
	LNode *temp = stack->next;
	stack->next = stack->next->next;
	*item = temp->data;
	free(temp);
}

void top(LinkStack *stack, ElementType *item){
	if(stack == NULL || item == NULL)
		return;
	if(stack->next == NULL)
		return;// 栈空退出
	*item = stack->next->data;
}

void destoryStack(LinkStack *stack){
	if(stack == NULL)
		return;
	LNode *temp;
	while(stack != NULL){
		temp = stack->next;	
		free(stack);
		stack = temp;
	}
}

int main01()
{
	// 创建一个stack
	LinkStack *stack = NULL;
	createStack(&stack);

	//将元素压栈
	printf("please input some number used to push(0 end): \n");
	ElementType item = -1;
	while(item != 0){
		scanf("%d", &item);
		push(stack, item);
	}

	// 弹出栈顶元素
	while(!isEmpty(stack)){
		pop(stack, &item);
		printf(" <%d> ", item);
	}
	
	destoryStack(stack);
	printf("\n---------------\n");
	
	return 0;
}
