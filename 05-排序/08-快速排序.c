#include <stdio.h>
/* 
 * 最好情况 T = O(Nlog(N))
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
 * void Quick_sort(ElementType A[], int N){
 *	if(N < 2) return;
 *	pivot = 从A[]中选一个主元;
 *	将s = { A[] \ privot}分成2个独立的子集;
 *		A1 = { a < privot }和
 *		A2 = { a > privot };
 *	A[] = Quick_sort(A1, N1) 
 *			(privot)
 *	      Quick_sort(A2, N2)
 * }
 *
 * 选主元
 * 随机取
 * 取头 中 尾的中位数
 *
 * */

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

}


void Swap(ElementType *a, ElementType *b){
	ElementType temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// 取中位数
ElementType Median3(ElementType A[], int Left, int Right){
	int Center = (Left + Right) / 2;
	if(A[Left] > A[Center])
		Swap(&A[Left], &A[Center]);
	if(A[Left] > A[Right])
		Swap(&A[Left], &A[Right]);
	if(A[Center] > A[Right])
		Swap(&A[Center], &A[Right]);
	// A[Left] <= A[Center] <= A[Right]
	Swap(&A[Center], &A[Right - 1]);// 将pivot藏到右边
	// 只需要考虑 A[Left + 1] -- A[Right - 2]
	return A[Right - 1];
}
// 子集划分


void QuickSort(ElementType A[], int Left, int Right){
	int Privot, i, j, Cutoff = 2;
	if(Cutoff <= Right - Left){
		Privot = Median3(A, Left, Right);
		i = Left; j = Right - 1;
		for(; ;){
			while(A[++i] < Privot);
			while(A[--j] < Privot);

			if(i < j)
				Swap(&A[i], &A[j]);
			else break;
		}
		Swap(&A[i], &A[Right - 1]);
		QuickSort(A, Left, i - 1);		
		QuickSort(A, i + 1, Right);		
	}
	else
		Insertion_sort(A + Left, Right - Left + 1);	
}

void Quick_sort(ElementType A[], int N){
	QuickSort(A, 0, N - 1);
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

	Quick_sort(arr, n);

	printf("after sort...\n");
	printArr(arr, n);


	return 0;
}
