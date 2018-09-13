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

// 如何快速找到最小元

void Selection_sort(ElementType a[], int n){
	// 每次选择一个最小值，放到开头
	int i, temp, minPosition;
	for(i = 0; i < n; ++i){
		// 从a[i]到a[n-1]中找到最小元，将其位置赋值给minPosition
		minPosition = scanForMin(a, i, n);		
		// 将未排序部分的最小元换到有序部分的最后位置
		temp = a[i];
		a[i] = a[minPosition];
		a[minPosition] = temp;

		printArr(a, n);
	}
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

	Selection_sort(arr, n);

	printf("after sort...\n");
	printArr(arr, n);


	return 0;
}
