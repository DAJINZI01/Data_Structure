#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode{
	int weight;
	struct TreeNode *lchild, *rchild;
}HuffmanTree, TreeNode;

/*O(Nlog2(N))*/
HuffmanTree* Huffman(MinHeap *H)
{	/*假设H->size个权值已经存在H->Elements[]->weight里*/
	int i; HuffmanTree *T;
	BuildMinHeap(H); /*将H->Elements[]按权值调整为最小堆*/
	for(i = 1; i < H->size; i++){ /*做H->size-1次合并*/
		T = (TreeNode *)malloc(sizeof(TreeNode));	
		T->lchild = DeleteMin(H); /*从最小堆中删除一个节点，作为新T的左节点*/
		T->rchild = DeleteMin(H); /*从最小堆中删除一个节点，作为新T的右节点*/
		T->weight = T->lchild->weight + T->rchild->weight;
		Insert(H, T); /*将新T插入到最小堆*/
	}
	T = DeleteMin(H); /*返回堆顶的树根*/
	return T;
}
/*
 * 如何根据节点不同的查找频率构造更有效的搜索树？
 * */

/*
 * 带权路径长度（WPL）：设二叉树有n个叶子节点，每个叶子节点带有权值Wk，从根节点到每个叶子节点的长度为Lk
 * 	则每个叶子节点的带权路径长度和就是：WPL = ∑WKLk
 * 哈夫曼树的特点：
 * 1、没有度为1的节点
 * 2、n个叶子节点的哈夫曼树共有2n-1个节点 N2 = N0 - 1
 * 3、哈夫曼树的任意非叶子节点的左右子树交换任是哈夫曼树
 * 4、对同一组取值（w1, w2, ... , wn），是否存在不同构的两颗哈夫曼树
 *
 * */

/*
 * 哈夫曼编码
 * 给定一段字符串，如何对字符串进行编码，可以使得字符串的编码存储空间最少
 * 7个字符
 *
 * 分析：
 * 1、用等长的ASCII编码
 * 2、用等长的3位编码
 * 3、不等长编码，出现频率高的字符用编码短些，出现频率低的字符可以编码长些
 *
 * 怎么进行不等长编码？
 * 如何避免二义性？
 * 前缀码  prefix code:任何字符的编码都不是另一个字符编码的前缀
 *
 * 用二叉树进行编码
 * （1）左右分子0、1
 * （2）字符只在叶子节点，不会出现前缀码，当字符出现在其他字符路径当中的时候，树的非叶节点的时候，会出现前缀码
 *
 * 怎么构造医科编码代价最小的二叉树？
 *
 *
 * */

int main()
{

	return 0;
}
