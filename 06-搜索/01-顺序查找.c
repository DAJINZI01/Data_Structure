/*
 * Searching 查找：根据某个给定关键字K, 从集合R中找出关键字与K相同的记录
 * 静态查找：集合中记录是固定的，没有插入和删除操作，只有查找
 * 动态查找：集合中记录是动态变化的，除查找，还可能发生插入和删除
 *
 * */
#include <stdio.h>
#define MaxSize 1024

typedef int ElementType;
typedef struct LNode{
	ElementType Element[MaxSize];
	int length;
}List;

// 顺序查找 时间复杂度O(n)
int sequentialSearch(List *tb1, ElementType K){
	/*在Element[1]~Element[n]中查找关键字为K的数据元素*/
	if(!tb1) return 0;
	int i;
	tb1->Element[0] = K; /*建立哨兵*/
	//for(i = tb1->length; i >0 && tb1->Element[i] != K; i--);
	for(i = tb1->length; tb1->Element[i] != K; i--);
	return i; /*查找成功返回所在单元下标，不成功返回0*/
}

void printList(List *list){
	if(!list) return;
	int i;
	for(i = 1; i <= list->length; i++)
		printf(" [%d] ", list->Element[i]);
	printf("\n");
}

void showKPosition(int index){
	int i;
	for(i = 1; i < index; i++) printf("-----");// 少循环一次
	printf("->A\n");
}

int main()
{
	int i;
	int K;// 关键字
	int index;
	List list; 
	list.length = 0;
	for(i = 0; i < MaxSize; i++) list.Element[i] = 0;

	printf("please inupt some numbers(0 quit): ");
	i = 0;
	do{
		i++;// i 从 1 开始
		scanf("%d", &list.Element[i]);	
		list.length++;

	}while(list.Element[i] != 0);
	printf("\n-----------------\n");
	printList(&list);
	printf("please input the K you want to search: ");
	scanf("%d", &K);
	index = sequentialSearch(&list, K);
	showKPosition(index);
	
	return 0;
}
