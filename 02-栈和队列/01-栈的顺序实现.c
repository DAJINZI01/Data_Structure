#include <stdio.h>
#include <stdlib.h>

#include "seqStack.h"

//生成空栈，其最大长度为MaxSize
void createStack(seqStack **stack){
	if(stack == NULL)
		return;
	seqStack *s = (seqStack *)malloc(sizeof(seqStack));
	s->top = -1;// 栈顶指针置为-1
	*stack = s;	
}
//判断栈是否为空
int isEmpty(seqStack *stack){
	if(stack == NULL)
		return 1;
	return stack->top == -1;
}
//将元素压栈
void push(seqStack *stack, ElementType item){
	if(stack == NULL)
		return;
	stack->data[++stack->top] = item;
}
//删除并返回栈顶元素
void pop(seqStack *stack, ElementType *item){
	if(stack == NULL)
		return;
	*item = stack->data[stack->top--];
}

//释放栈空间
void destoryStack(seqStack *stack){
	if(stack == NULL)
		return;
	free(stack);
}

int main(){
	// 创建一个stack
	seqStack *stack = NULL;
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
