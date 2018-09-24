/*
 * 集合的表示：
 * 	集合的运算：交、并、补、差，判定一个元素是否属于某一个集合
 * 	并查集：集合并、查某元素属于什么集合
 * 	并查集问题中集合存储如何实现？
 *
 * 	例子：有10台电脑{1, 2, ..., 10}，已知下列电脑之间已经实现了连接：
 * 		1-2、2-4、3-5、4-7、5-8、6-9、6-10
 * 	Q:2-7之间、5-9之间是否是连通的？
 *
 * 	解决思路：
 * 	（1）将10台电脑看成10个集合{1}、{2}、...{10}
 * 	（2）已知一种连接“X和Y”，就将X和Y的集合合并；
 * 	（3）查询“X和Y是否是连通的”就是判别X和Y是否属于同一个集合
 * */

/*采用数组存储形式*/
typedef int ElementType;
#define MaxSize 1024
typedef struct{
	ElementType Data;
	int Parent;
}SetType;

/*查找某个元素所在的集合（用根节点表示）*/
int Find(SetType S[], ElementType X){
	/*在数组S中查找值为X的元素所属的集合*/
	/*MaxSize是全局变量，为数组S的最大长度*/
	int i;
	for(i = 0; i < MaxSize && S[i].Data != X; i++);
	if(i >= MaxSize) return -1; /*未找到，返回-1*/
	for(; S[i].Parent >= 0; i = S[i].Parent);
	return i; /*找到X所属集合，返回树根节点在数组S中的下标*/
}

/*
 * 集合的并运算
 * 分找到X1和X2两个元素所在集合树的根节点
 * 如果它们不同根，则将其中一个根节点的父节点指针设置成另一个根节点的数组下标
 *
 * */

/*集合的并运算*/
void Union(SetType S[], ElementType X1, ElementType X2){
	int Root1, Root2;
	Root1 = Find(S, X1);
	Root2 = Find(S, X2);
	if(Root1 != Root2) S[Root2].Parent = Root1;
}

/*
 * 为了改善合并以后的查找性能，可以采用小的集合合并到相对大的集合中（修改Union函数）
 * */

/*集合的并运算(V2.0)*/
void Union2(SetType S[], ElementType X1, ElementType X2){
	int Root1, Root2;
	Root1 = Find(S, X1);
	Root2 = Find(S, X2);
	if(S[Root1].Parent > S[Root2].Parent) {S[Root1].Parent += S[Root2].Parent; S[Root2].Parent = Root1;}
	else {S[Root2].Parent += S[Root1].Parent; S[Root1].Parent = Root2;}
}

