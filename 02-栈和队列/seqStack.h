#ifndef __SEQSTAKC_H__
#define __SEQSTAKC_H__

#define MaxSize 1024

typedef int ElementType;
typedef struct {
	ElementType  data[MaxSize];
	int top;
}seqStack;

//生成空栈，其最大长度为MaxSize
void createStack(seqStack **stack);
//判断栈是否为空
int isEmpty(seqStack *stack);
//将元素压栈
void push(seqStack *stack, ElementType item);
//删除并返回栈顶元素
void pop(seqStack *stack, ElementType *item);
//释放栈空间
void destoryStack(seqStack *stack);




#endif
