#include <stdio.h>
#include <stdlib.h>
#define MaxSize 1024
#define true 1
#define false 1

typedef int DataType;
typedef int WeightType;
typedef int Vertex;

/*
 * 邻接表：G[N]为指针数组，对应矩阵每一行一个链表，只存非零元素
 * 与矩阵的邻接表类似 即 一行 == 一个链表
 *
 * */

typedef struct ArcNode{
	Vertex adjVex;// 邻接点的下标
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
	VNode  adjList[MaxSize];// 邻接表数组 一维
}LGraph;// 表示整张图

typedef struct ENode{
	int V1, V2;
	WeightType weight;
}Edge;

// LGraph 初始化
// 初始化一个有VertexNum个顶点但没有边的图
LGraph* CreateGraph(int vertexNum){
	LGraph *Graph = NULL;
	int i = 0;

	Graph = (LGraph *)malloc(sizeof(LGraph));
	Graph->Nv = vertexNum;
	Graph->Ne = 0;

	/*没有边，顶点表的firstEdge=NULL*/
	for(i = 0; i < Graph->Nv; ++i)
		Graph->adjList[i].firstEdge = NULL;

	return Graph;
}

// 向LGraph中插入边
void InsertEdge(LGraph *Graph, Edge *E){
	ArcNode *newNode = NULL;
	// 插入边<v1, v2>
	// 为v2创建一个邻接点
	newNode = (ArcNode *)malloc(sizeof(ArcNode));
	newNode->adjVex = E->V2;
	newNode->weight = E->weight;
	// v2插入v1的表头
	newNode->nextArc  = Graph->adjList[E->V1].firstEdge;
	Graph->adjList[E->V1].firstEdge = newNode;// 头插法

	// 如果是无向图， 插入边<v2, v1>
	newNode = (ArcNode *)malloc(sizeof(ArcNode));
	newNode->adjVex = E->V1;
	newNode->weight = E->weight;
	// v1插入v2的表头
	newNode->nextArc  = Graph->adjList[E->V2].firstEdge;
	Graph->adjList[E->V2].firstEdge = newNode;// 头插法
}

LGraph* BuildGraph(){
	LGraph *Graph;
	Edge *E;
	Vertex Nv;
	int i;
	printf("please input the Nv of the LGraph: ");
	scanf("%d", &Nv);
	/*创建一个含有Nv顶点的图, 没有边*/
	Graph = CreateGraph(Nv);
	printf("please input the Ne of the LGraph: ");
	scanf("%d", &Graph->Ne);
	/*创建一个边节点*/
	E = (Edge *)malloc(sizeof(Edge));
	if(Graph->Ne){
		for(i = 0; i < Graph->Ne; i++){
			printf("please input an Edge's information(V1, V2, W): ");
			scanf("%d, %d, %d", &E->V1, &E->V2, &E->weight);
			InsertEdge(Graph, E);
		}
	}
	free(E);
	
	return Graph;
}
typedef void (*VISIT)(Vertex S );
void visit(Vertex S){printf(" <%d> ", S);}
int DFS_visited[MaxSize] = {false}; /* DFS_visited[]为全局变量，已经初始化为false */
void DFS(LGraph *Graph, Vertex V, VISIT visit){
	/* 以V为出发点对邻接表存储的图Graph进行DFS搜索 */
	if(!Graph || !visit) return;
	ArcNode *W;
	/*访问（print）第S个顶点*/
	visit(V); DFS_visited[V] = true; // 标记访问过了
	for(W = Graph->adjList[V].firstEdge; W; W = W->nextArc) /*对V的每个邻接点W->adjVex*/
		if(!DFS_visited[W->adjVex]) /*如果W->adjVex没有访问过*/
			DFS(Graph, W->adjVex, visit); /*则递归访问之*/	
}

int main()
{
	printf("create a Graph...\n");
	LGraph *Graph = BuildGraph();
	printf("DFS: ");
	DFS(Graph, 0, visit);
	printf("\n----------\n");

	return 0;
}
