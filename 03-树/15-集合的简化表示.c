#include <stdio.h>
#define MaxSize 1024

/*
 * 任何有限集合（N个）元素都可以被映射为整数0 - N-1
 * 按秩归并
 * 	为什么树会越来越高？应该吧矮树贴到高树上！
 * 	树的高度存哪里？S[Root] = -树高/-元素个数;
 * 	最坏情况下的树高 = O(logN)
 * 路径压缩
 * */

typedef int ElementType; /*默认元素都可以用非负整数表示*/
typedef int SetName; /*默认用根节点的下标作为集合名称*/
typedef ElementType SetType[MaxSize];

SetName Find(SetType S, ElementType X){
	/*默认集合全部初始化为-1*/
	for(; S[X] >= 0; X = S[X]);
	return X;
}

SetName Find2(SetType S, ElementType X){
	if(S[X] < 0) /*找到集合的根*/
		return X;
	else /*先找到根，把根变成X的父节点，在返回根*/ 
		return S[X] = Find(S, S[X]);
}

void Union(SetType S, ElementType Root1, ElementType Root2){
	/*这里默认Root1和Root2是不同集合的根节点*/
	if(S[Root1] < S[Root2]) {
		S[Root1] += S[Root2];
		S[Root2] = Root1;  
	}else {
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
}

void Initialization(SetType S, int n){
	int i;
	for(i = 0; i < n; i++) S[i] = -1; /*任然初始化为-1*/
}

void Input_connection(SetType S){
	ElementType u, v;
	SetName Root1, Root2;
	printf("please input u ＆ v: ");
	scanf("%d %d", &u, &v);
	Root1 = Find(S, u-1);
	Root2 = Find(S, v-1);
	if(Root1 != Root2) Union(S, Root1, Root2);
}

void Check_connection(SetType S){
	ElementType u, v;
	SetName Root1, Root2;
	printf("please input u ＆ v: ");
	scanf("%d %d", &u, &v);
	Root1 = Find(S, u-1);
	Root2 = Find(S, v-1);
	if(Root1 == Root2) printf("--yes--\n"); 
	else printf("--no--\n");
}

int Check_network(SetType S, int n){
	int count = 0, i;	
	for(i = 0; i < n; i++){
		if(S[i] < 0) count++;	
	}
	printf("There is(are) %d compoent(s)\n", count);
	return count;
}


int main()
{
	SetType S;
	int n;
	char in;
	printf("please input the number of your Set: ");
	scanf("%d", &n);
	Initialization(S, n);
	do{
		getchar();
		printf("please input the one of I, C, S: ");
		scanf("%c", &in);
		switch(in){
			case 'I': Input_connection(S); break;	
			case 'C': Check_connection(S); break;	
			case 'S': Check_network(S, n); break;	
		}
	}while(in != 'S');

	return 0;
}
