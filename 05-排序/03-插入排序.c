#include <stdio.h>
/* 
 * 最好情况 T = O(N)
 * 最坏情况 T = O(N^2)
 *
 * 时间复杂度下界
 *  	对于下标i < j，如果a[i] > a[j]，则称（i, j）是一对逆序对（inversion）
 *  	交换2个相邻的元素正好消去1个逆序对
 *
 * T(N, I) = O(N+I)
 * 	如果序列 基本有序，则插入排序简单高效
 * 定理：任意N个不同元素组成的序列平均具有 N(N-1)/4 个逆序对
 * 定理：任何仅以交换两个相邻元素来排序的算法其平均复杂度为 奥米噶(N^2)
 * 这就意味着：要提高算法效率，我们必须
 * 	每次消去不止1个逆序对!
 * 	每次交换相隔较远的2个元素, 有希望在一次交换中消掉好几个逆序对
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

void Insertion_sort(ElementType a[], int n){
	int i, j;
	int temp;
	for(i = 1; i < n; ++i){// 一共有多少张牌, 默认手里已经有了一张牌0
		temp = a[i]; // 摸下一张牌 /* 取出未排序序列中的第一个元素*/	
		for(j = i; j > 0 && a[j - 1] > temp; j--)
			// 从手里的最后一张往前比较
			a[j] = a[j - 1]; // 往后移出空位 /*依次与已排序序列中元素比较并右移*/
		// a[j - 1] > temp || j = 0
		a[j] = temp;// 新牌落位
		printArr(a, i+1);
	}
} /*最好情况 顺序 T=O(N) 逆序 T=O(N^2) 算法稳定*/

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

	Insertion_sort(arr, n);

	printf("after sort...\n");
	printArr(arr, n);


	return 0;
}
