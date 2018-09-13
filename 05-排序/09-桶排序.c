#include <stdio.h>
/* 
 * 最好情况 T = O(N)
 * 最坏情况 T = O(N^2)
 *
 *
 * */

typedef int ElementType;

void printArr(ElementType a[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf(" <%d> ", a[i]);
	}
	printf("\n---------------------------\n");

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
 *
 * */


void Bucket_sort(ElementType A[], int N){

}

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

	Bucket_sort(arr, n);

	printf("after sort...\n");
	printArr(arr, n);


	return 0;
}
