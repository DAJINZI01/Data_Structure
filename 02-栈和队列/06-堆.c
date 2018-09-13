#include <stdio.h>
#include <stdlib.h>
/*
 * 什么是堆？
 * 优先队列（Priority Queue）:特殊的“队列”，取出元素的顺序是
 * 按照元素的优先级（关键字）大小，而不是元素进入队列的先后顺序。
 *
 * 是否可以采用二叉树存储结构？
 * 数组、链表、有序数组、有序链表
 * 二叉搜索树?
 * 如果采用二叉树结构，应该更关注 插入 还是 删除？?
 * 优先队列的完全二叉树表示
 * 	堆的两个特性：
 * 		结构性：用数组表示的完全二叉树
 * 		有序性：任一节点的关键字是其子树所有节点的最大值（最小值）
 * 		"最大堆（MaxHeap）"，也称“大顶堆”：最大值
 * 		"最小堆（MinHeap）"，也称“小顶堆”：最小值
 *
 * 类型名称：最大堆（MaxHeap）
 * 数据对象集：完全二叉树，每个节点的元素值不小于其子节点的元素值
 * 操作集：H MaxHeap item ElementType，主要操作有：
 * MaxHeap create(int MaxSize); 创建一个空的最大堆
 * Boolean isFull(MaxHeap H); 判断最大堆H是否已满
 * inset(MaxHeap H, ElementType item); 将元素item插入最大堆H
 * Boolean isEmpty(MaxHeap H); 判断最大堆是否为空
 * ElementType Delete(MaxHeap H); 返回H中最大元素（高优先级）
 *
 * */

#define MaxData 1024
typedef int ElementType;
typedef struct {
	ElementType *elem;/*存储堆元素的数组*/
	int size; /*堆当前元素个数*/
	int capacity; /*堆的最大容量*/
}MaxHeap;

MaxHeap* create(int MaxSize){
	/*创建容量为MaxSize的空的最大堆*/
	MaxHeap *H = (MaxHeap *)malloc(sizeof(MaxHeap));
	if(!H) return NULL;
	H->elem  = (ElementType *)malloc(sizeof(ElementType) * (MaxSize + 1)); /*堆的下标从1开始*/
	H->size = 0;
	H->capacity = MaxSize;
	H->elem[0] = MaxData; /*定义“哨兵“，为大于堆中所有可能的元素的值，便于以后更快的操作*/
	return H;
}

int isFull(MaxHeap *H){
	if(!H) return 0;
	return H->size == H->capacity;
}

int isEmpty(MaxHeap *H){
	if(!H) return 1;
	return H->size == 0; 
}

// O(log2(n))
void insert(MaxHeap *H, ElementType item){
	/*将元素item插入最大堆H，其中H->elem[0]已经定义为哨兵*/
	int i;
	if(isFull(H)){printf("最大堆已满！\n"); return;}
	i = ++H->size; /*i指向插入堆后中的最后一个元素的位置*/
	for(; H->elem[i/2] < item; i/=2) /*有了哨兵，就不用写  i > 1*/
		H->elem[i] = H->elem[i/2]; /*向下过滤节点*/
	H->elem[i] = item; /*将item插入*/
}

// O(log2(n))
ElementType deleteMax(MaxHeap *H){
	int Parent, Child;
	ElementType MaxItem, temp;
	if(isEmpty(H)){printf("最大堆已爲空\n"); return -1;}

	MaxItem = H->elem[1]; /*取出根節點中的最大值*/
	/*用最大堆中的最後一個元素從根節點開始網上過濾下層節點*/
	temp = H->elem[H->size--];
	for(Parent = 1; Parent * 2 <= H->size; Parent = Child){/*判斷是否有左兒子*/
		Child = Parent * 2;
		if(Child != H->size && (H->elem[Child] < H->elem[Child+1])) /*Child = H->size, 那就沒有右兒子*/	
			Child++; /*Child 指向左右孩子節點的最大者*/
		if(temp >= H->elem[Child]) break;
		else H->elem[Parent] = H->elem[Child];
	}
	H->elem[Parent] = temp;
	return MaxItem;
}

/*
 * 最大堆的建立
 * 	建立最大堆：將已經存在的N個元素按最大堆的要求存放在一個一維數組中
 * 	method1：通過插入操作，將N個元素一個個相機摻入到一個初始爲空的堆中去，其時間復雜度最大爲O(Nlog2(N))
 * 	method2：在 線性復雜度 下建立最大堆
 * 		1) 將N個元素按輸入順序存入，先滿足完全二叉樹的結構特性
 * 		2) 調整個節點的位置，以滿足最大堆的有序特性
 *
 * */

/*----------- 建造最大堆 -----------*/
void PercDown( MaxHeap *H, int p )
{ /* 下滤：将H中以H->Data[p]为根的子堆调整为最大堆 */
	int Parent, Child;
	ElementType X;

	X = H->elem[p]; /* 取出根结点存放的值 */
	for( Parent=p; Parent*2<=H->size; Parent=Child ) {
		Child = Parent * 2;
		if( (Child!=H->size) && (H->elem[Child]<H->elem[Child+1]) )
			Child++;  /* Child指向左右子结点的较大者 */
		if( X >= H->elem[Child] ) break; /* 找到了合适位置 */
		else  /* 下滤X */
		H->elem[Parent] = H->elem[Child];
	}
	H->elem[Parent] = X;
}

void BuildHeap( MaxHeap *H )
{ /* 调整H->Data[]中的元素，使满足最大堆的有序性  */
	/* 这里假设所有H->Size个元素已经存在H->Data[]中 */

	    int i;

	/* 从最后一个结点的父节点开始，到根结点1 */
	for( i = H->size/2; i>0; i-- )
		PercDown( H, i );
}


int main()
{
	return 0;
}
