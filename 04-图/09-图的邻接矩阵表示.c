#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MaxVertexNum 1024
#define MaxSize 1024
typedef int WeightType;
typedef int DataType;
typedef int Vertex; /*用顶点的下标表示顶点，为整型*/
typedef struct GNode{ /*顶点类型*/
	int Nv; /*定点数*/
	int Ne; /*边数*/
	WeightType G[MaxVertexNum][MaxVertexNum]; /*邻接矩阵*/
	DataType Data[MaxVertexNum]; /*存顶点的数据*/
}MGraph;

typedef struct ENode{ /*边节点*/
	Vertex V1, V2; /*有向边<V1, V2>*/		
	WeightType Weight; /*权重*/
}Edge;

/*初始化一个有VertexNum个顶点但没有边的图*/
MGraph* CreateGraph(int VertexNum){
	Vertex V, W;
	MGraph *Graph;
	Graph = (MGraph *)malloc(sizeof(MGraph));
	if(!Graph) return NULL;
	Graph->Nv = VertexNum;
	Graph->Ne = 0;

	/*注意：这里默认顶点编号从0开始，到 Graph->Nv - 1*/
	for(V = 0; V < Graph->Nv; V++)
		for(W = 0; W < Graph->Nv; W++)
			Graph->G[V][W] = 0; /*INFINITY*/

	return Graph;
}

/*向MGraph中插入边*/
void InsertEdge(MGraph *Graph, Edge *E){
	if(!Graph || !E) return;

	/*插入边 <V1, V2>*/
	Graph->G[E->V1][E->V2] = E->Weight;
	/*若是无向图，还要插入边 <V2, V1>*/
	Graph->G[E->V2][E->V1] = E->Weight;
}

/*完整的建立一个MGraph*/
MGraph* BuildGraph(){
	MGraph *Graph;
	Edge *E;
	int Nv, i;

	printf("please input the VertexNum of the Graph: ");
	scanf("%d", &Nv);
	Graph = CreateGraph(Nv); /*创建一个只有节点没有边的图*/
	printf("please input the EdgeNum of the Graph: ");
	scanf("%d", &Graph->Ne); /*读入边数*/
	E = (Edge *)malloc(sizeof(Edge));		
	if(!E) return NULL;
	if(Graph->Ne){
		for(i = 0; i < Graph->Ne; i++){
			printf("please input an Edge's information(V1, V2, W): ");
			scanf("%d, %d, %d", &E->V1, &E->V2, &E->Weight);
			InsertEdge(Graph, E);
		}
	}
	free(E);
	return Graph;
}


int DFS_visited[1024] = {false};
int BFS_visited[1024] = {false};

typedef void(*VISIT)(Vertex V);
void visit(Vertex V){ printf(" <%d> ", V); }

void DFS(MGraph *Graph, Vertex S, VISIT visit){
	// 类似于树的先序遍历
	visit(S); DFS_visited[S] = true;	
	Vertex V;
	for(V = 0; V < Graph->Nv; ++V){
		// 如果V没有被访问，并且V是S的邻接点
		if(!DFS_visited[V] && Graph->G[S][V])	
			DFS(Graph, V, visit);
	}
}

void BFS(MGraph *Graph, Vertex S, VISIT visit){
	Vertex V, W;
	Vertex queue[MaxSize];
	int front = 0, rear = 0;

	/*根节点入队列*/
	rear = (rear + 1) % MaxSize;
	queue[rear] = S;
	/*访问（print）节点*/
	visit(S); BFS_visited[S] = true; /*标记节点S已被访问*/

	while(front != rear){ /*当队列不空的时候*/	
		/*顶点出队列*/
		front = (front + 1) % MaxSize;
		V = queue[front];

		for(W = 0; W < Graph->Nv; W++){ /*遍历V的所有的邻接点 一行*/
			if(!BFS_visited[W] && Graph->G[V][W]){ /*如果没有被访问过，并且有边*/
				/*访问（print）节点*/
				/*先访问，再放入队列，与树的层次遍历不同, 避免一个节点的重复放入*/
				/*0 -> 1(1); 0 -> 2(2); 1 -> 2(2)*/
				visit(W); BFS_visited[W] = true; 
				/*节点入队列*/
				rear = (rear + 1) % MaxSize;
				queue[rear] = W;
			}
		}
	}
}


int main()
{
	printf("create a Graph...\n");
	MGraph *Graph = BuildGraph();
	printf("DFS: ");
	DFS(Graph, 0, visit);
	printf("\n----------\n");
	printf("BFS: ");
	BFS(Graph, 0, visit);
	printf("\n----------\n");

	return 0;
}
