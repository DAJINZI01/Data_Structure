/*
 * 关键路径问题 由 绝对不允许延误 的活动组成的路径
 * AOE （Activity On Edge）网络
 * 	一般用于安排项目的工序, 工序和工序之间有先后的依赖关系
 * 	---------- ai表示活动 顶点表示活动到ai到此结束
 *
 * 	持续时间C<i, j>       	最早完成时间Earliest
 * 	------------>		顶点编号 
 * 	机动时间D<i, j>         最晚完成时间Latest
 *
 *	Q1: 整个工期有多长？ Earliest[8] = 18;
 *	Earliest[0] = 0;
 *	Earliest[j] = max{Earliest[i] + C<i, j>};
 *
 *	Q2: 哪几个组有机动时间？ 哪几个组是不能休息的，哪几个组是可以中间干别的事情
 *	Latest[8] = 18;
 *	Latest[i] = min{Latest[j] - C<i, j>};
 *	D<i, j> = Latest[j] - Earliest[i] - C<i, j>;
 *
 *
 *
 *
 *
 * */
