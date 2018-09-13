/*
 *  AOV (Activity On Vertex) 网络
 *  拓扑排序
 *  拓扑序：如果图中从V到W有一条有向路径，则V一定排在W之前。
 *  		满足此条件的顶点序列称为一个拓扑序
 *  获得一个拓扑序的过程就是拓扑排序
 *  AOV如果有合理的拓扑序，则必定是有向无环图（Directed Acylic Graph,DAG）
 *
 * */

/*
 * void topSort(){
 *	for(count = 0; count < V; count++){
 *		V = 未输出的入度为0的顶点;// O[V]
 *		if(这样的V不存在){
 *			Error("图中有回路");
 *			break;
 *		}
 *
 *		输出V, 或则记录V的输出序号;
 *		for(V 的每个邻接点 W)
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
 * }
 *
 * 
 * */
