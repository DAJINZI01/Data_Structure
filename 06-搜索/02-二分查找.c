/*
 * Searching 查找：根据某个给定关键字K, 从集合R中找出关键字与K相同的记录
 * 静态查找：集合中记录是固定的，没有插入和删除操作，只有查找
 * 动态查找：集合中记录是动态变化的，除查找，还可能发生插入和删除
 *
 * */

/*
 * 二分查找判定树
 * 	判定树上每个节点需要的查找次数刚好为该节点所在的层数
 * 	查找成功时查找次数不会超过判定树的深度
 * 	n个节点判定树的深度为log2(n)+1 或 log2(n+1)
 * 	ASL（平均查找次数）每层的节点查找次数之和 / 总的节点数n
 *
 * */


#include <stdio.h>
#define MaxSize 1024

typedef int ElementType;
typedef struct LNode{
	ElementType Element[MaxSize];
	int length;
}List;

void BubbleSort(List *tb1){
	if(!tb1) return;
	int i, j, flag = 1, temp;
	for(i = tb1->length; i > 1 && flag; i--){
		flag = 0; /*交换标志位*/
		for(j = 0; j < i; j++){
			if(tb1->Element[j] > tb1->Element[j+1]){
				temp = tb1->Element[j]; 
				tb1->Element[j] = tb1->Element[j+1]; 
				tb1->Element[j+1] = temp; 
				flag = 1;
			}	
		}
	}
}

// 二分查找 时间复杂度 O(log2(n))
int BinarySearch(List *tb1, ElementType K){
	/*在表tb1中查找关键字为k的数据元素*/
	if(!tb1) return 0;
	int left, right, mid, NotFound = -1;
	left = 1; /*初始左边界*/
	right = tb1->length; /*初始右边界*/

	while(left <= right){
		mid = (left + right) / 2; /*计算中间元素坐标*/
		printf("mid: %d \n", mid);
		if(K < tb1->Element[mid]) right = mid - 1; /*调整右边界*/
		else if(K > tb1->Element[mid]) left = mid + 1; /*调整右边界*/
		else return mid; /*查找成功返回元素的下标*/
	}
	return NotFound; /*查找不成功返回-1*/
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
	printf("--sorted sequences--\n");
	BubbleSort(&list);
	printList(&list);
	printf("please input the K you want to search: ");
	scanf("%d", &K);
	index = BinarySearch(&list, K);
	showKPosition(index);
	
	return 0;
}
