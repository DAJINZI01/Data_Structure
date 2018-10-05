/*
 * 编译处理时，涉及变量及属性（如：变量类型）的管理：
 * 	插入：新变量定义
 * 	查找：变量的引用
 * 动态查找问题
 *
 * 利用查找树（搜索树）进行变量管理
 * 	两个变量名（字符串）比较的效率不高
 * 	是否可以先把字符串转换为数字，在处理？
 *
 * 已知的几种查找方法：
 * 	顺序查找		O(N)
 * 	二分查找（静态查找）	O(log2N)
 * 	二叉搜索树		O(h) h为二叉查找树的高度
 * 	平衡二叉树		O(log2N)
 *
 * 在登录QQ的时候，QQ服务器是古河核对你的身份？
 * 面对庞大的用户群，如何快速找到用户信息？
 *
 * 看看是否可以用二分法查找
 * 十亿用户，用二分查找30次
 * 十亿用户 X 1k = 1024G，1T连续空间
 * 按QQ号大小有序存储：在连续存储空间中，插入和删除一个新的QQ号码需要移动大量数据
 *
 * */

/*
 * 散列表（哈希表）
 * 类型名称：符号表（SymbolTable）
 * 数据对象集：符号表是“名字（Name）- 属性（Attribute）”对的集合
 * 操作集：Table ∈ SymbolTable, Name ∈ NameType, Attr ∈ AttributeType
 * 
 * // 创建一个长度为TableSize的符号表
 * SymbolTable InitializeTable(int TableSize);
 * // 查找特定名字Name是否在符号表Table中
 * Boolean IsIn(SymbolTable Table, NameType Name);
 * // 获取Table中指定Name对应的属性
 * AttributeType Find(SymbolTable Table, NameType Name);
 * // 将Table中指定名字Name的属性修改为Attr
 * SymbolTable Modify(SymbolTable Table, NameType Name, AttributeType Attr);
 * // 向Table中插入一个新名字Name及其属性Attr
 * SymbolTable Insert(SymbolTable Table, NameType Name, AttributeType Attr);
 * // 从Table中删除一个名字Name及其属性
 * SymbolTable Delete(SymbolTable Table, NameType Name);
 *
 * */

/*
 * 问题：如何快速搜索到需要的关键词？如果关键词不方便比较怎么办？
 * 	查找的本质：已知对象找位置
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
 * 如果没有冲突，T查询 = T插入 = T删除 = O(1)
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
 * 2、除留余数法: h(key) = key mod p	p = TableSize, 素数
 * 3、数字分析法: 分析数字关键字在各位上的变化情况，取比较随机的位作为散列地址
 *	取11位手机号码key的后4位作为地址：
 *	散列函数为：h(key) = atoi(key+7) (char* key)
 *	如：关键字key是18位的身份证号码
 *	省2市2区2 年4月2日2 该辖区中的序号3 校验位1
 * 4、折叠法: 把关键字分割成位数相同的几个部分，然后叠加
 * 	ex: 56793542
 * 		542
 * 		793
 * 	+	056
 * 	--------------
 * 		1391 	h(56793542) = 391
 *
 * 5、平方取中法: 函数值能够被每一位所影响
 * 	ex: 56793542
 *		56793542
 *	X	56793542
 *	------------------
 *	322550 641 2905764 h(56793542) = 641

 * 	
 * 字符关键词的散列函数构造
 * 1、一个简单的散列函数---ASCII码加和法 会容易产生聚集
 * 2、简单的改进---前3个字符移位法	冲突：string、street、strong、structure等等
 * 3、好的散列函数--移位法 	级数
 *
 * Index Hash(const char *key, int TableSize){
 *	unsigned int h = 0; // 散列函数值，初始化为0
 *	while(*key != '\0')
 *		h = (h << 5) + *key++;
 *	return h % TableSize;
 * }
 * 
 * 冲突处理的方法
 * 换个位置：开放地址法(Open Addressing), 一旦产生了冲突（该地址已有其它的元素） 按某种规则寻找另一空地址
 * 若放生了第i次冲突，试探的下一个地址将增加di，基本公式：
 * 	hi(key) = (h(key) + di) mod TableSize (1 <= i < tableSize)
 * 	计算出来的只有有可能超过地址空间，通过求余，它就回来了
 * 	线性探测(d = i)、平方探测(d = ±i^2)、双散列(d = i * h2(key))
 * 同一个位置的冲突对象组织在一起(一个链表)：链地址法
 * 
 * 1、线性探测法（Linear Probing）
 * 	线性探测法：以增量序列1, 2, ..., (TableSize -1)。
 * 	循环探测依次存储地址		--- 注意“聚集”现象，这个地方的冲突会越来越多
 *
 * 散列表查找性能分析
 * 	成功平均查找长度 (ASLs) 在散列表中的元素就是成功的
 * 	不成功的查找长度 (ASLu)
 *
 * 平方探测法：如果散列表的长度TableSize是某个4k+3（k是整数）形成的素数时，
 * 	平方探测法既可以探查到整个散列表空间
 *
 * 再散列（Rehashing）
 * */
