/*
 * 什么是最小生成树（Mininum Spanning Tree）
 * 最小生成树存在 <=> 图连通
 * 是一棵树
 * 	无回路
 *	v个顶点，一定有v-1条边
 * 是生成树
 *	包含所有的顶点
 *	v-1条边都在图里
 *	向生成树中任意添加一条边都一定构成回路
 * 边的权重和最小
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
 *
 * Kruskal算法 -- 将森林合并成树
 * void Kruskal(Graph G)
 * {
 *	MST = {};
 *	while(MST 中不到v-1条边 && E中还有边){
 *		从E中取一条权重最小的边E<v, w>;
 *		将E<v, w>从E中删除;
 *		if(E<v, w> 不在MST中 构成回路)
 *			将E<v, w>加入MST;
 *		
 *		else
 *			彻底无视E<v, w>;
 *	}
 *	if(MST 中不到 v-1 条边)
 *		Error("生成树不存在");
 *
 * }
 *
 * */
