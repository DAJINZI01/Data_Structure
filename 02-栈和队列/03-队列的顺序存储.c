#include <stdio.h>
#include <stdlib.h>

#include "seqQueue.h"
/*
 * 循环队列：逻辑上的循环队列
 *
 * */

// 创建队列
void createQueue(SeqQueue **queue){
	if(queue == NULL)
		return;
	SeqQueue *q = (SeqQueue *)malloc(sizeof(SeqQueue));
	if(q == NULL){
		printf("内存不足\n");
		return;
	}
	q->front = q->rear = 0;
	*queue = q;
}

// 判断队列是否为空
int isEmpty(SeqQueue *queue){
	if(queue == NULL)	
		return 1;
	return queue->front == queue->rear;
}

// 入队
void enQueue(SeqQueue *queue, ElementType item){
	if(queue == NULL)
		return;
	if((queue->rear + 1) % MaxSize == queue->front){
		printf("队列满了\n");	
		return;
	}

	queue->rear = (queue->rear + 1) % MaxSize;
	queue->data[queue->rear] = item;
}

// 出队
void deQueue(SeqQueue *queue, ElementType *item){
	if(queue == NULL || item == NULL)
		return;
	if(queue->front == queue->rear){
		printf("队列为空\n");	
		return;
	}

	queue->front = (queue->front + 1) % MaxSize;
	*item = queue->data[queue->front];
}

// 销毁队列
void destoryQueue(SeqQueue *queue){
	if(queue == NULL)
		return;
	free(queue);
}

int main()
{
	// 创建一个queue
	SeqQueue *queue = NULL;
	createQueue(&queue);

	//将元素入队
	printf("please input some number used to push(0 end): \n");
	ElementType item = -1;
	while(item != 0){
		scanf("%d", &item);
		enQueue(queue, item);
	}

	//元素出队
	while(!isEmpty(queue)){
		deQueue(queue, &item);
		printf(" <%d> ", item);
	}
	
	destoryQueue(queue);
	printf("\n---------------\n");
	
	return 0;
}
