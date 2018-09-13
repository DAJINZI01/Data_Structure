#include <stdio.h>
#include <stdlib.h>

/*
 * 什么是图？
 * 表示多对多的关系
 * 包含：一组顶点，通常用V(Vertex)表示顶点的集合
 * 	一组边：通常用E(Edge)表示边的集合
 * 	(v, w) <v, w>
 * 	不考虑重边，和自回路
 *
 * 无向图 有向图 网络
 *
 * */

/*
 * 邻接矩阵
 * 	问题：对于无向图的存储，怎样可以省一般的空间
 * 	用一个长度为 N(N + 1) / 2的一维数组存储,Gij = (i * (i + 1) / 2) + j
 * 	对于网络，只要把Gij的值定义为边<vi, vj>的权重即可。没有边，如何表示。
 * 有什么好处？
 * 1、直观、简单、好理解
 * 2、方便检查任一对顶点间是否有边
 * 3、方便找任一顶点的所有的“邻接点”（有边直接连接的顶点）
 * 4、方便计算任一顶顶啊的“度”，出度，入度
 * 	无向图：对应的行（列）非0元素的个数
 * 	有向图：对应的行（列）非0元素的个数 出(入)度
 *
 * 有什么不好？
 * 	浪费空间 - 存稀疏图（点很多而边很少）有大量的无效元素
 * 	稠密图 （完全图）还是很合算的
 * 	浪费时间 - 统计稀疏图中一共有多少条边
 *
 * */

/*
 * 邻接表：G[N]为指针数组，对应矩阵每行一链表，只存非0元素。
 * 	G[0]-> G[1]-> ... G[N]-> 
 *
 * */

#define MaxSize 1024
typedef int weightType;

typedef struct {
	int no; // 顶点编号
	char info; // 顶点的其他信息
}VertexType;// 顶点类型

typedef struct GNode {// 图的定义
	int Nv;// 顶点数
	int Ne;// 边数
	weightType edges[MaxSize][MaxSize];// 邻接矩阵的定义
	VertexType vex[MaxSize]; //存放顶点的数据 
}MGraph;// 图的邻接矩阵类型

typedef struct ENode{// 边节点
	int v1, v2; // <v1, v2>
	weightType weight;// 权重	
}Edge;

// MGraph初始化
// 初始化一个有VertexNum个顶点但没有边的图
MGraph* createGraph(int vertexNum){
	MGraph *Graph = NULL;
	int i, j;
	Graph = (MGraph *)malloc(sizeof(MGraph));
	Graph->Nv = vertexNum;
	Graph->Ne = 0;
	for(i = 0; i < Graph->Nv; ++i)
		for(j = 0; j < Graph->Nv; ++j)
			Graph->edges[i][j] = 0;// INFINITY 

	return Graph;
}

// 向MGraph中插入边
void insertEdge(MGraph *Graph, Edge *E){
	// 插入边 <v1, v2>
	Graph->edges[E->v1][E->v2] = E->weight;						

	// 如果是无向图，还要插入<v2, v1>
	Graph->edges[E->v2][E->v1] = E->weight;			
}

// 建立一个MGraph
MGraph* buildGraph(){

	MGraph *Graph = NULL;
	Edge *E = NULL;
	int i = 0;

	int Nv = 0;// 顶点数
	printf("please input Nv: ");
	scanf("%d", &Nv);
	Graph = createGraph(Nv);// 初始化图
	printf("please input Ne: ");
	scanf("%d", &Graph->Ne);
	if(Graph->Ne != 0){
		E = (Edge *)malloc(sizeof(Edge));
		for(i = 0; i < Graph->Ne; ++i){
			printf("please input v1, v2, weight: ");
			scanf("%d %d %d",
				&E->v1, &E->v2, &E->weight);
			insertEdge(Graph, E);
		}
	
	}

	// 如果节点有数据的话读入数据
	for(i = 0; i < Graph->Nv; ++i){
		printf("please input vex.no, vex.info: ");
		scanf("%d %c", &(Graph->vex[i].no), &(Graph->vex[i].info));
	}

	return Graph;
}


int main()
{
	buildGraph();	
	return 0;

}
