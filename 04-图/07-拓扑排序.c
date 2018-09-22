/*
 *  AOV (Activity On Vertex) 网络 ，所有的真实的活动是表现在顶点上的
 *  拓扑排序
 *  拓扑序：如果图中从V到W有一条有向路径，则V一定排在W之前。
 *  		满足此条件的顶点序列称为一个拓扑序
 *  获得一个拓扑序的过程就是拓扑排序
 *  AOV如果有合理的拓扑序，则必定是有向无环图（Directed Acylic Graph,DAG）
 *  	--> V --> V必须在V开始之前结束
 *
 * */

/*
 * void TopSort(){
 *	for(count = 0; count < V; count++){
 *		V = 未输出的入度为0的顶点;// O[V]
 *		if(这样的V不存在){
 *			Error("图中有回路");
 *			break;
 *		}
 *
 *		输出V, 或则记录V的输出序号;
 *		for(V 的每个邻接点 W) // 将V从图中抹掉
 *			indegree[W]--;
 *	}
 * }
 *
 * 随时将入度变为0的顶点放到一个容器中
 * void topSort(){
 *	for(图中的每一个顶点V)
 *		if(indegree[v] == 0)
 *			enQueue(Q, V);
 *	while(!isEmpty(Q)){
 *		V = deQueue(Q);
 *		输出V, 或则记录V的输出序号;count++;
 *		for(V的每一个邻接点W)
 *			if(--indegree[W] == 0)
 *				enQueue(Q, W);
 *	}
 *	if(count !=  V){
 *	        Error("图中有回路");
 *	}
 * }// T = O(V + E)
 * 此算法可以用来检测有向图是否DAG
 * 
 * */

/********************邻接表表示的图***************************/
#define MaxSize 1024
typedef int Vertex;
typedef int WeightType;
typedef int DataType;
typedef struct ArcNode{
	Vertex adjVex; // 邻接点的下标
	WeightType weight;// 权重
	struct ArcNode *nextArc;// 指向下一条边的指针
}ArcNode;// 边表节点
typedef struct VNode{
	ArcNode *firstEdge;// 指向第一条边的指针
	DataType data;// 存放节点的数据
}VNode; // 顶点节点
typedef struct GNode{
	int Nv; // 定点数
	int Ne; // 边数
	VNode adjList[MaxSize]; // 邻接表数组
}LGraph; // 图

int TopSort(LGraph *Graph, Vertex TopOrder[]){
/* 对Graph进行拓扑排序,  TopOrder[]顺序存储排序后的顶点下标 */
	int Indegree[MaxSize];
	ArcNode *W;
	Vertex queue[MaxSize]; int front = 0, rear = 0;
	Vertex V;
	/* 初始化Indegree[] */
	for(V = 0; V < Graph->Nv; V++) Indegree[V] = 0;
	/* 遍历图，得到Indegree[] */
	for(V = 0; V < Graph->Nv; V++)
		for(W = Graph->adjList[V].firstEdge; W; W = W->nextArc)
			++Indegree[W->adjVex]; /* 对有向边<V, W->AdjV>累计终点的入度 */
	/* 将所有入度为0的顶点入列 */
	for(V = 0; V < Graph->Nv; V++)
		if(Indegree[V] == 0) {rear = (rear + 1) % MaxSize; queue[rear] = V;}
	/* 下面进入拓扑排序 */
	int count = 0;
	while(front != rear){
		front = (front + 1) % MaxSize; V = queue[front]; /* 弹出一个入度为0的顶点 */	
		TopOrder[count++] = V; /* 将之存为结果序列的下一个元素 */
		for(W = Graph->adjList[V].firstEdge; W; W = W->nextArc)
			if(--Indegree[W->adjVex] == 0) /* 若删除V使得W->AdjV入度为0 */
			{rear = (rear + 1) % MaxSize; queue[rear] = V;} /* 则该顶点入列 */
	}
	if(count != Graph->Nv)
		return 0; /* 说明图中有回路, 返回不成功标志 */
	return 1;
}
