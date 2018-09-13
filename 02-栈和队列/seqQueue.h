#ifndef __SEQQUEUE_H_
#define __SEQQUEUE_H_

#define MaxSize 1024

typedef int ElementType;

typedef struct Queue{
	ElementType data[MaxSize];
	int front, rear;
}SeqQueue;

// 创建队列
void createQueue(SeqQueue **queue);
// 判断队列是否为空
int isEmpty(SeqQueue *queue);
// 入队
void enQueue(SeqQueue *queue, ElementType item);
// 出队
void deQueue(SeqQueue *queue, ElementType *item);
// 销毁队列
void destoryQueue(SeqQueue *queue);


#endif
