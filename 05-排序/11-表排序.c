/*
 * 间接排序
 * 	定义一个指针数组作为“表”（table）
 *
 *  A  		0   1   2   3   4   5   6   7
 * key 		f   d   e   a   g   b   h   e
 * table	0   1   2   3   5   5   6   7
 *
 * 如果仅要求按顺序输出，则输出：
 * A[table[0]], A[table[1]], ..., A[table[N-1]]
 * */

/*
 * 物理排序
 * N个数字的排列由若干个独立的环组成
 * T=O(mN)，m是每个A元素的复制时间, 复制时间大到不可忽略
 * */
