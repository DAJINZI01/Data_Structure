/*
 * 给定两颗树T1和T2。如果T1可以通过若干次左右孩子互换变成T2，则我们称两棵树是“同构”的。
 * 静态链表：物理上的存储是数组，逻辑上链表
 * 在元素所用的存储下标中，左右下标中没出现的数字就是根的下标
 * */

#include <stdio.h>
#define MaxTree 10
#define ElementType char 
#define Tree int 
#define Null -1 /*NULL(0), Null(-1)*/

struct TreeNode{
	ElementType item;
	Tree Left;
	Tree Right;
}T1[MaxTree], T2[MaxTree];

Tree BuildTree(struct TreeNode *T){

}
int Isomorphic(Tree R1, Tree R2){}

int main()
{
	Tree R1, R2;// 根节点

	R1 = BuildTree(T1);
	R2 = BuildTree(T2);

	if(Isomorphic(R1, R2)) printf("they are the same tree!!!");
	else printf("they are the same tree!!!");

	return 0;
}
