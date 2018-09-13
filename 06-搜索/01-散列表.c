/*
 * 问题：如何快速搜索到需要的关键词？如果关键词不方便比较怎么办？
 * 	查找的本子：已知对象找位置
 * 	有序安排对象：全序、半序
 * 	直接“算出”对象的位置：散列
 *
 * 散列查找法的两项基本工作：
 * 	计算位置：构造 散列函数 确定关键字存储位置
 * 	解决冲突：应用某种策略解决多个关键词位置相同的问题
 *
 * 时间复杂度几乎是常量：O(1)，即查找时间与问题规模无关！
 *
 * 装填因子（Loading Factor）:
 * 	设散列表空间大小为m，填入表中元素个数是n，则称α = n / m为散列表的装填因子
 *
 * “散列（hashing）”的基本思想是：
 * 1)以关键字key为自变量，通过一个确定的函数h(散列函数)，
 *   计算出相应的函数值h(key)，作为数据对象的存储地址
 * 2)可能不同的关键字映射到同一个散列地址上
 * 	h(key1) = h(key2)，称为冲突（Collision）
 * 	-----需要某种解决冲突的策略
 *
 * 一个好的散列函数一般考虑两个因素：
 * 1、计算简单，以便提高转换速度
 * 2、关键词对应的地址空间分布均匀，以尽量减少冲突。
 *
 * 数字关键词的散列函数构造
 * 1、直接定址法
 * 2、除留余数法
 * 3、数字分析法
 * 4、折叠法
 * 5、平方取中法
 * 字符关键词的散列函数构造
 * 
 * 冲突处理的方法
 * 换个位置：开放地址法, 按某种规则寻找另一个位置
 * 	线性探测(d = i)、平方探测(d = i^2)、双散列
 * 同一个位置的冲突对象组织在一起(一个链表)：链地址法
 *
 *
 * 散列表查找性能分析
 * 	成功平均查找长度 (ASLs)
 * 	不成功的查找长度 (ASLu)
 *
 * 平方探测法：如果散列表的长度TableSize是某个4k+3（k是整数）形成的素数时，
 * 	平方探测法既可以探查到整个散列表空间
 *
 * 再散列（Rehashing）
 * */


