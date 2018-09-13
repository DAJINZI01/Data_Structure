#include <stdio.h>
#include <stdlib.h>
/* 
 * T = O(Nlog(N))
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


// 有序子列的归并，两个有序子列合并为一个有序子列
void Merge(ElementType A[], ElementType TempA[], int L, int R, int RightEnd){
	/* L = 左边的起始位置，R = 右边的起始位置，RightEnd = 右边的终点位置*/
	int LeftEnd, temp, NumElements, i;
	LeftEnd = R - 1;// 右边的终点位置，假设左右两边紧挨着
	temp = L;// 存放结果的数组的初始位置, 与L相对
	NumElements = RightEnd - L + 1;// 计算出元素的个数
	while(L <= LeftEnd && R <= RightEnd){
		// 注意是<=，保证了排序的稳定性？
		if(A[L] <= A[R]) TempA[temp++] = A[L++];	
		else 		 TempA[temp++] = A[R++];
	}
	while(L <= LeftEnd)// 直接复制左边剩下的
		TempA[temp++] = A[L++];
	while(R <= RightEnd)// 直接复制右边剩下的
		TempA[temp++] = A[R++];

	for(i = 0; i < NumElements; i++, RightEnd--)
		A[RightEnd] = TempA[RightEnd];
}

void MSort(ElementType A[], ElementType TempA[], int L, int RightEnd){
	int Center;
	if(L < RightEnd){
		Center = (L + RightEnd) / 2;
		MSort(A, TempA, L, Center);// 左边递归的排序
		MSort(A, TempA, Center + 1, RightEnd);// 右边递归的排序
		Merge(A, TempA, L, Center + 1, RightEnd);// 左右已经排序的子列合并为一个子列
		printArr(TempA, RightEnd - L + 1);
	}
}

// 统一函数接口
void Merge_sort1(ElementType A[], int N){
	ElementType *TempA;
	TempA = (ElementType *)malloc(sizeof(ElementType) * N);
	if(TempA == NULL){
		printf("空间不足\n");
		return;
	}
	MSort(A, TempA, 0, N - 1);
	free(TempA);
}

// 非递归算法
void Merge_pass(ElementType A[], ElementType TempA[], int N, int length){
	// length = 当前有序子列的长度
	int i, j;
	for(i = 0; i <= N - 2 * length; i += 2 * length)
		Merge(A, TempA, i, i + length, i + 2 * length - 1);;
	if(i + length < N)// 归并最后2个子列
		Merge(A, TempA, i, i + length,  N - 1);
	else// 最后只剩下1个子列
		for(j = i; j < N; j++) TempA[j] = A[j];
}

void Merge_sort(ElementType A[], int N){
	int length = 1;// 初始化子序列的长度为1
	ElementType *TempA;
	TempA = (ElementType *)malloc(sizeof(ElementType) * N);
	if(TempA == NULL){
		printf("空间不足\n");
		return;
	}
	while(length < N){
		Merge_pass(A, TempA, N, length);
		length *= 2;
		Merge_pass(TempA, A, N, length);
		length *= 2;
	}
	free(TempA);
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

	Merge_sort(arr, n);

	printf("after sort...\n");
	printArr(arr, n);


	return 0;
}
