/*
 * 什么是最小生成树（Mininum Spanning Tree）
 * 最小生成树存在 <=> 图连通
 * 是一棵 树
 * 	无回路
 *	v个顶点，一定有v-1条边
 * 是 生成 树
 *	包含所有的顶点
 *	v-1条边都在图里
 *	向生成树中任意添加一条边都一定构成回路
 * 边的权重和 最小
 *
 * 贪心算法
 * 什么是“贪”：每一步都是最好的
 * 什么是“好”：权重最小的边
 * 需要约束：
 * 	只能用图里有的边
 * 	只能正好用掉v-1边
 * 	不能有回路
 *
 *
 * Prim算法 -- 让一棵小树长大
 * void Prim(){
 * 	MST = {s};
 * 	while(1){
 *		V = 未收录顶点中dist最小者; // dist[V] = E(s, V)或正无穷 parent[s] = -1
 *		if(这样的V不存在) break;
 *		将V收录进MST; // dist[v] = 0;
 *		for(V的每个邻接点W)
 *			if(W未被收录) // dist[W] != 0
 *				if(E(v, w) < dist[W]){
 *					dist[w] = E(v, w);
 *					parent[W] = V;
 *				}
 * 	}
 * 	if(MST中收录的顶点不到V个)
 * 		Error("图不连通");
 *
 * }// T = O(V^2) 稠密图合算
 *
 * Kruskal算法 -- 将森林合并成树
 * void Kruskal(Graph G)
 * {
 *	MST = {};
 *	while(MST 中不到v-1条边 && E中还有边){
 *		从E中取一条权重最小的边E<v, w>;// 最小堆
 *		将E<v, w>从E中删除;
 *		if(E<v, w> 不在MST中 构成回路) // 并查集
 *			将E<v, w>加入MST;
 *		
 *		else
 *			彻底无视E<v, w>;// 生成树不要，E中也要删除
 *	}
 *	if(MST 中不到 v-1 条边)
 *		Error("生成树不存在");
 *
 * }// T = O(Elog(E)) 稀疏图合算
 *
 * */
