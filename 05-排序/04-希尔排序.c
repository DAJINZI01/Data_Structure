#include <stdio.h>
/* 
 * 最好情况 T = O(N)
 * 最坏情况 T = O(N^2)
 *
 * 希尔增量序列
 * 增量元素不互质，则小增量可能根本不起作用
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

// 原始希尔排序
void Shell_sort(ElementType a[], int n){
	int i, j, D, temp, si;
	 /* Sedgewick增量序列， 这里只列出一小部分增量 */
	int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};
	/* 初始的增量Sedgewick[Si]不能超过待排序列长度 */
	for(si = 0; Sedgewick[si] > n; ++si);

	//for(D = n / 2; D > 0; D /= 2){// 希尔增量序列
	for(D = Sedgewick[si]; D > 0; D = Sedgewick[++si]){// Sedgewick增量序列
		for(i = D; i < n; i++){// 插入排序
			temp = a[i];// 从序列中的第一个开始，而不是第零个
			for(j = i; j >=D  && a[j - D] > temp; j -= D)// j 的跨度为D	
				a[j] = a[j - D];
			a[j] = temp;
			printArr(a, n);
		}
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

	Shell_sort(arr, n);

	printf("after sort...\n");
	printArr(arr, n);


	return 0;
}
