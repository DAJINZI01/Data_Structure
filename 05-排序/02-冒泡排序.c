#include <stdio.h>
/* 
 * 最好情况 T = O(N)
 * 最坏情况 T = O(N^2)
 * 只有在前一个元素大于后一个元素的时候才发生交换，稳定
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

void Bubble_sort(ElementType a[], int n){
	int i, j, flag;
	int temp;
	for(i = n - 1; i >= 0; i--){// 关于j的循环
		flag = 0;
		for(j = 0; j < i; ++j){// 一趟冒泡
			if(a[j] > a[j + 1]){// 交换元素的位置
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 1;// 标识发生了交换
			}
		}
		printArr(a, n);
		if(flag == 0) break;// 全程无交换
	}
}/*最好的情况：顺序 T=O(N) 逆序 T=O(N^2) 从前往后一次比较，每次交换相邻的两个元素，对于链表排序可以实现，算法稳定*/

int main(){
	int arr[1024] = {0};
	printf("please input the disorder numbers: ");
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

	Bubble_sort(arr, n);

	printf("after sort...\n");
	printArr(arr, n);


	return 0;
}
