/*
 * 背景：求两个站点之间的最短的一条路，最便宜的一条路，最快的一条路。
 *
 * 在网络中，求两个不同顶点之间的所有路径中,边的权值之和最小的那一条路径
 * 这条路径就是两点之间的最短路径（Shortest Path）
 * 第一个顶点为源点(Source)
 * 最后一个顶点为终点(Destination)
 *
 * 问题分类：
 * 	单源最短路径问题：从固定源点出发，求其到所有其他顶点的最短路径
 * 		(有向) 无权图
 * 		(有向) 有权图 负值圈(negative-cost-cycle)
 * 	多源最短路径问题：求任意两顶点间的最短路径
 *
 * 按照递增(非递减)的顺序找出到各个顶点的最短路
 *
 * void unWeight(Vertes S){ // 无权图的单源最短路径
 *	enQueue(S, Q);
 *	while(!isEmpty(Q)){
 *		v = deQueue(Q);
 *		for(v 的每一个邻接点 W)
 *			if(dist[W] == -1){ // 一看就知道没有被访问过
 *				dist[W] = dist[V] + 1; // S 到 W 的最短距离
 *				path[W] = V; // S 到 W 的路上经过的某顶点
 *				enQueue(W,  Q);
 *			}
 *	}
 * }
 *
 * Dijkstra 算法
 * 	令 S = {源点S + 已经确定了最短路径的顶点Vi}
 *      对于任一未收录的顶点v, 定义dist[v]为s到v的最短路径长度，但该路径仅经过S中的顶点。
 *      即路径{s -> (Vi ∈ S) -> v)}的最小长度。
 *
 *      若路径是按照递增（非递减）的顺序生成的，则：
 *      	真正的最短路径必须只经过S中的顶点（why？）
 *      	每次从未收录的顶点中选一个dist最小的收录（贪心）
 *      	增加一个v进入S，可能影响另外一个w的dist值！换句话说，v进入S后，能影响的只有v的邻接点
 *      	dist[W] = min{dist[W], dist[v]+<v, w>的权重}
 *
 *      void Dijkstra(Vertex s){
 *		while(1) {
 *			V = 未收录顶点中dist最小者;
 *			if(这样的V不存在) break;
 *			collected[V] = true;
 *			for(V的每个邻接点W){
 *				if(collected[W] == false)
 *					if(dist[V] + E<v, w> < dist[W]){
 *						dist[W] = dist[V] + E<v, w>;
 *						path[W] = V;
 *					}
 *
 *			}
 *		}
 *      }// 不能解决有负边的情况
 *
 *      方法1：直接扫描所有为收录顶点O(V^2 + E) 对于稠密图效果好
 *      方法2：将dist存在最小堆中 O(log(V)) 对于稀疏图效果好
 *      	T = O(Vlog(V) + Elog(V)) = O(Elog(V))
 * */
