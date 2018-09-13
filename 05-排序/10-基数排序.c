#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;

void printArr(ElementType a[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf(" <%d> ", a[i]);
	}
	printf("\n---------------------------\n");
}
/* 基数排序 - 次位优先 */

/* 假设元素最多有MaxDigit个关键字，基数全是同样的Radix */
#define MaxDigit 4
#define Radix 10

/* 桶元素结点 */
typedef struct Node {
	int key;
	struct Node * next;
}Node ;

/* 桶头结点 */
typedef struct HeadNode {
	Node *head, *tail;
}HeadNode;


/* 创建链表节点 */
void createNode(Node **node, int key){
	if(node == NULL)
		return;
	*node = (Node *)malloc(sizeof(Node));
	if(*node == NULL){
		printf("内存不足\n");
		return;
	}
	(*node)->key = key;
	(*node)->next = NULL;
}

int GetDigit ( int X, int D )
{ /* 默认次位D=1, 主位D<=MaxDigit */
	int d, i;
	for (i=1; i<=D; i++) {
		d = X % Radix;
		X /= Radix;
	}
	return d;
}

void LSDRadixSort(ElementType A[], int N){
	HeadNode Bucket[Radix];
	Node *List = NULL, *temp, *p;
	int i, D, Di;
	/* 初始化每个桶为空链表 */
	//HeadNode Bucket[Radix] = {0};
	for(i = 0; i < Radix; i++)
		Bucket[i].head = Bucket[i].tail = NULL;
	/* 将原始序列逆序存入初始链表无头List */
	for(i = 0; i < N; ++i){
		createNode(&temp, A[i]);		
		// 头插法
		temp->next = List;
		List = temp;
	}
	/* 下面开始排序 */ 
	for (D=1; D<=MaxDigit; D++) { /* 对数据的每一位循环处理 */
		/* 下面是分配的过程 */
		p = List;
		while(p){
			Di = GetDigit(p->key, D); /* 获得当前元素的当前位数字 */
			/* 从List中摘除 */
			temp = p; p = p->next;
			/* 插入B[Di]号桶尾 */
			temp->next = NULL;
			if (Bucket[Di].head == NULL)// 如果是第一次插入，同时修改头尾指针
				Bucket[Di].head = Bucket[Di].tail = temp;
			else {
				Bucket[Di].tail->next = temp;
				Bucket[Di].tail = temp;
			}		     
		}
		/* 下面是收集的过程 */
		List = NULL; 
		for (Di=Radix-1; Di>=0; Di--) { /* 将每个桶的元素顺序收集入List */
			if (Bucket[Di].head) { /* 如果桶不为空 */
				/* 整桶插入List表头 */
				// 头插法，循环从大到小
				Bucket[Di].tail->next = List;
				List = Bucket[Di].head;
				Bucket[Di].head = Bucket[Di].tail = NULL; /* 清空桶 */
			}
		}
	}

	/* 将List倒入A[]并释放空间 */
	for(i = 0; i < N; ++i){
		temp = List;
		List = List->next;	
		A[i] = temp->key;
		free(temp);
	}
}


/* 
 * void Bucket_sort(ElementType A[], int N){
 *	count[M] 初始化;
 *	while(读入一个学生的成绩grade)
 *		将该生插入count[grade]链表;
 *	for(i = 0; i < M; ++i){
 *		if(count[i])
 *			输出整个count[i]链表;
 *	}
 * }
 *
 * T(N, M) = O(M + N)
 * 如果M >> N该怎么办？
 *
 * 基数排序
 * 	基数指的是 进制 2进制 -> 基数为2  10进制 -> 基数为10
 *	用 次位优先 (Least Significant Digit)
 *
 * 多关键字排序
 *
 * */



int main(){
	int arr[1024] = {0};
	printf("please input the disorder numbers: \n");
	int i = 0;
	int n = 0;
	scanf("%d", &arr[i]);
	while(arr[i]){
		i++;	
		scanf("%d", &arr[i]);
	}
	n = i;	
	printf("n = %d\n", n);
	printf("before sort...\n");
	printArr(arr, n);

	LSDRadixSort(arr, n);

	printf("after sort...\n");
	printArr(arr, n);


	return 0;
}
