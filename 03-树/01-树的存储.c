#include <stdio.h>
#define MaxSize 1024
/*
 * 树与非树
 * 	子树是不相交的
 * 	除了根节点外，每个节点有且仅有一个父节点
 * 	一棵N个节点的树有N-1条边
 *
 * 树的一些基本术语
 * 1、节点的度 (Degree)
 * 2、树的度
 * 3、叶子节点 (Leaf)
 * 4、父节点 (Parent)
 * 5、子节点 (Child)
 * 6、兄弟节点 (Sibling)
 * 7、路径和路径长度
 * 8、祖先节点 (Ancestor)
 * 9、子孙节点 (Descendant)
 * 10、节点的层次 (Level)
 * 11、树的深度 (Depth)
 *
 * */

/*
 * 树的表示
 * 	孩子兄弟表示法
 *
 * */

typedef int ElementType;
typedef struct PTNode{
	ElementType data;// 节点数据
	int parent;// 双亲位置
}PTNode;

typedef struct PTree{
	PTNode nodes[MaxSize];
	int r;// 根的位置
	int n;// 节点数目
}PTree;

int main()
{
	return 0;
}
