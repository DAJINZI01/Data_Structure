#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MaxSize 1024

typedef int Vertex;

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


/*
 * 深度优先搜索（Depth First Search, DFS）
 *
 * 广度优先搜索（Breadth First Search, BFS）
 *
 *
 * */

/*
	void DFS(vertex V){
		visited[V] = true;
		for(V 的每一个邻接点 W)
			if(!visited[W])
				DEF(W);
	}

	void BFS(vertex V){
		visited[V] = true;
		enQueue(V, Q);
		while(!isEmpty(Q)){
			V = deQueue(Q);
			for(V 的每个邻接点 W){
				if(!visited[W]){
					visited[W] = true;
					enQueue(W, Q);	
				}
			}
		}
	}
*/

int visited[1024] = {false};

typedef void(*VISIT)(Vertex V);
void visit(Vertex V){ printf("<%d>\n", V); }

void DFS(MGraph *Graph, Vertex S, VISIT visit){
	// 类似于树的先序遍历
	visit(S);
	visited[S] = true;	
	Vertex V;
	for(V = 0; V < Graph->Nv; ++V){
		// 如果V没有被访问，并且V是S的邻接点
		if(!visited[V] && Graph->edges[S][V])	
			DFS(Graph, V, visit);
	}
}

void BFS(MGraph *Graph, Vertex S, VISIT visit){
	int queue[MaxSize] = {0};
	int front, rear;
	front = rear = 0;

	Vertex V, W;
	visit(S);
	visited[S] = true;// 标记S已经访问了	
	rear = (rear + 1) % MaxSize;
	queue[rear] = S;// 入队

	while(rear != rear){// 队不空的时候
		front = (front + 1) % MaxSize;
		V = queue[front]; // 出队	
		for(W = 0; W < Graph->Nv; ++W){// 遍历图的每一个顶点
			   /* 若W是V的邻接点并且未访问过 */	
			if(!visited[W] && Graph->edges[V][W]){
				visit(W);	
				visited[W] = true;
				rear = (rear + 1) % MaxSize;
				queue[rear] = S;// 入队
			}

		}
		
	}

}

int main()
{
	int i, j;
	MGraph Graph;
	Graph.Ne = 3;
	Graph.Nv = 3;
	for(i = 0; i < Graph.Nv; ++i)
		for(j = 0; j < Graph.Nv; ++j)
			Graph.edges[i][j] = 0;
	Graph.edges[1][0] = 1;
	Graph.edges[0][1] = 1;
	Graph.edges[2][3] = 0;
	Graph.edges[1][4] = 0;
	Graph.edges[3][7] = 0;
	Graph.edges[9][3] = 0;

	//DFS(&Graph, 0, visit);
	DFS(&Graph, 0, visit);
	
	return 0;
}
