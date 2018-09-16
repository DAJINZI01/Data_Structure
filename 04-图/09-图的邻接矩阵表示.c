#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 1024
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
			printf("Graph->Ne: %d\n", Graph->Ne);
			printf("please input an Edge's information(V1, V2, W): ");
			scanf("%d, %d, %d", &E->V1, &E->V2, &E->Weight);
			InsertEdge(Graph, E);
		}
	}
	free(E);
	return Graph;
}

int main()
{
	printf("create a Graph...\n");
	MGraph *Graph = BuildGraph();

	return 0;
}
