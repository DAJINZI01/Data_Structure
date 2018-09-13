#include <stdio.h>
#include <stdlib.h>

#include "linkQueue.h" 
/*前面删除，后面添加*/

// 创建队列
void createQueue(LinkQueue **queue){
	if(queue == NULL)
		return;
	LinkQueue *q = (LinkQueue *)malloc(sizeof(LinkQueue));
	if(q == NULL){
		printf("内存不足\n");
		return;
	}
	q->front = q->rear = NULL;
	*queue = q;
}
// 判断队列是否为空
int isEmpty(LinkQueue *queue){
	if(queue == NULL)
		return 1;
	return queue->front == NULL || queue->rear == NULL;
}
// 入队
void enQueue(LinkQueue *queue, ElementType item){
	// 不存在队列满了
	if(queue == NULL)
		return;
	QNode *newNode = (QNode *)malloc(sizeof(QNode));
	if(newNode == NULL){
		printf("内存不足\n");
		return;
	}
	newNode->data = item;
	newNode->next = NULL;
	if(queue->front == NULL || queue->rear == NULL)// 队列空，同时修改front和rear
		queue->front = queue->rear = newNode;
	else{
		queue->rear->next = newNode;
		queue->rear = newNode;	// 尾插法
	}
}
// 出队
void deQueue(LinkQueue *queue, ElementType *item){
	if(queue == NULL || item == NULL)
		return;
	if(queue->front == NULL){
		printf("队列空");
		return;
	}
	QNode *temp = queue->front;
	if(queue->front  == queue->rear){// 队列只有一个元素了，将队列置为空
		queue->front = queue->rear = NULL;
	}
	else
		queue->front = temp->next;
	
	*item = temp->data;
	free(temp);
}

// 销毁队列
void destoryQueue(LinkQueue *queue){
	if(queue == NULL)
		return;
	QNode *temp = NULL;
	while(queue->front != NULL){
		temp = queue->front;
		queue->front = queue->front->next;	
		if(queue->front == NULL)// 还剩下最后一个元素，将rear置为空
			queue->rear = NULL;
		free(temp); 
	}
}

int main()
{
	// 创建一个queue
	LinkQueue *queue = NULL;
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
