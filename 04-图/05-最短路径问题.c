/*
 * 在网络中，求两个不同顶天之间的所有路径中边的权值之和最小的那一条路径
 * 这条路径就是两点之间的最短路径（Shortest Path）
 * 第一个顶点为源点(Source)
 * 最后一个顶点为终点(Destination)
 *
 * 问题分类：
 * 	单源最短路径问题：从固定源点出发，求其到所有其他定点的额最短路径
 * 		(有向) 无权图
 * 		(有向) 有权图 负值圈
 * 	多源最短路径问题：求任意两顶点间的最短路径
 *
 * 按照递增的顺序找出到各个顶点的最短路
 *
 * void unWeight(Vertes S){
 *	enQueue(S, Q);
 *	while(!isEmpty(Q)){
 *		v = deQueue(Q);
 *		for(v 的每一个邻接点 W)
 *			if(dist[W] == -1){
 *				dist[W] = dist[V] + 1;
 *				path[W] = V;
 *				enQueue(W,  Q);
 *			}
 *	}
 * }
 *
 *
 *
 * */


