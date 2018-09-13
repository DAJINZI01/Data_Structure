#include <stdio.h>
#include <stdlib.h>
#define MaxSize 1024

typedef int DataType;
typedef int WeightType;

/*
 * 邻接表：G[N]为指针数组，对应矩阵每一行一个链表，只存非零元素
 *
 * */

typedef struct ArcNode{
	int adjVex;// 邻接点的下标
	WeightType weight;// 边的权重
	struct ArcNode *nextArc;// 指向下一条边的指针
}ArcNode;// 边表节点


typedef struct VNode{
	ArcNode *firstEdge;// 指向第一条边的指针
	DataType data;// 存节点的数据
}VNode;// 顶点表节点

typedef struct GNode{
	int Nv; // 顶点数
	int Ne; // 边数
	VNode  adjList[MaxSize];// 邻接表 一维
}LGraph;

typedef struct ENode{
	int v1, v2;
	WeightType weight;
}Edge;

// LGraph 初始化
// 初始化一个有VertexNum个顶点但没有边的图
LGraph* createGraph(int vertexNum){
	LGraph *Graph = NULL;
	int i = 0;

	Graph = (LGraph *)malloc(sizeof(LGraph));
	Graph->Nv = vertexNum;
	Graph->Ne = 0;

	for(i = 0; i < Graph->Nv; ++i)
		Graph->adjList[i].firstEdge = NULL;
}

// 向LGraph中插入边
void insertEdge(LGraph *Graph, Edge *E){
	ArcNode *newNode = NULL;
	// 插入边<v1, v2>
	// 为v2创建一个邻接点
	newNode = (ArcNode *)malloc(sizeof(ArcNode));
	newNode->adjVex = E->v2;
	newNode->weight = E->weight;
	// v2插入v1的表头
	newNode->nextArc  = Graph->adjList[E->v1].firstEdge;
	Graph->adjList[E->v1].firstEdge = newNode;// 头插法

	// 如果是无向图， 插入边<v2, v1>
	newNode = (ArcNode *)malloc(sizeof(ArcNode));
	newNode->adjVex = E->v1;
	newNode->weight = E->weight;
	// v1插入v2的表头
	newNode->nextArc  = Graph->adjList[E->v2].firstEdge;
	Graph->adjList[E->v2].firstEdge = newNode;// 头插法
	


}

int main()
{

}
