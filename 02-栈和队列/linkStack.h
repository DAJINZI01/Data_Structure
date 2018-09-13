#ifndef __STACK_H_
#define __STACK_H_


#define ElementType char 

typedef struct LNode{
	ElementType data;
	struct LNode *next;
	
}LinkStack, LNode;

void createStack(LinkStack **stack);
int isEmpty(LinkStack *stack);
void push(LinkStack *stack, ElementType item);
void pop(LinkStack *stack, ElementType *item);
void top(LinkStack *stack, ElementType *item);
void destoryStack(LinkStack *stack);

#endif
