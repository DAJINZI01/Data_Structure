#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

typedef int ElementType;

/* 队列结点 */
typedef struct QNode{
	ElementType data;
	struct QNode *next;	
}QNode;

/* 队列结构体  */
typedef struct LinkQueue{
	QNode *front, *rear;// 队头，队尾指针
}LinkQueue; 

// 创建队列
void createQueue(LinkQueue **queue);
// 判断队列是否为空
int isEmpty(LinkQueue *queue);
// 入队
void enQueue(LinkQueue *queue, ElementType item);
// 出队
void deQueue(LinkQueue *queue, ElementType *item);
// 销毁队列
void destoryQueue(LinkQueue *queue);

#endif
