#include <stdio.h>
#include <stdlib.h>
#define LEN(A) sizeof(A) / sizeof(A[0])
#define QSIZE 101
/* 
 * 最好情况 T = O(N)
 * 最坏情况 T = O(N^2)
 *
 *
 * */

typedef struct LNode{
	int id;
	char *name;
	int gender;
	int age;
	int score;
	struct LNode *next;
}Student;

typedef Student  ElementType;

void printArr(ElementType a[], int n){
	int i;
	for(i = 0; i < n; i++)
		printf("id:[%d]\tname:[%s]\tgender:[%d]\tage:[%d]\tscore:[%d]\n",
				a[i].id, a[i].name, a[i].gender, a[i].age, a[i].score);
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
 * 当M非常小的时候，这是一个线性的时间复杂度，比如说N=40,000个学生，M=101(0-100)
 * 如果M >> N该怎么办？
 *
 *
 * */


void Bucket_sort(ElementType A[], int N){
	int i, j;
	ElementType count[QSIZE], *temp;
	ElementType *B = (ElementType *)malloc(sizeof(ElementType) * N);
	for(i = 0; i < QSIZE; i++) count[i].next = NULL;
	for(i = 0; i < N; i++){
		temp = count[A[i].score].next;
		count[A[i].score].next = &A[i];
		A[i].next = temp;
	}

	j = 0;
	for(i = 0; i < QSIZE; i++){
		temp = count[i].next;
		while(temp){
			B[j++] = *temp;
			temp = temp->next;
		}
	}
	for(i = 0; i < N; i++)
		A[i] = B[i];
	free(B);
}

int main(){
	Student STU[] = {
		{100, "宫本武藏", 1, 22 , 98, NULL}, {101, "花木兰", 0, 18, 92, NULL}, 
		{102, "赵云", 1, 32 , 90, NULL}, {103, "甄姬", 0, 16, 88, NULL}, 
		{104, "武则天", 0, 3100, 100, NULL}, {105, "李白", 1, 3000, 99, NULL}, {106, "荆轲", 0, 5000, 93, NULL}};
	printf("排序前。。。\n");
	printArr(STU, LEN(STU));
	Bucket_sort(STU, LEN(STU));
	printf("排序后。。。\n");
	printArr(STU, LEN(STU));
	return 0;
}
