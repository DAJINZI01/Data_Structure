#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TreeNode{
	ElementType data;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
}BinTree;


// 输出二叉树中的叶子节点 
void preRecursion(BinTree *bt){
	if(bt){
		if(!bt->lchild && !bt->rchild)
			printf(" <%d> ", bt->data);
		preRecursion(bt->lchild);
		preRecursion(bt->rchild);
	}
}

// 求树的高度
// height = max{lchild, rchild} + 1
// 必须先知道左右子树的高度
int postRecursionGetheight(BinTree *bt){
	if(bt == NULL)
		return 0;
	int lh = 0, rh = 0, maxH = 0;

	lh = postRecursionGetheight(bt->lchild);// 求左子树的高度
	rh = postRecursionGetheight(bt->rchild);// 求有子树的高度
	maxH = (lh > rh) ? lh : rh;// 取左右子树较大的深度
	return maxH + 1;// 返回树的高度
}

// 二元运算 表达式数及其遍历
// 叶子节点是 运算数
// 非叶子节点是 运算符号
// 先序 前缀表达式
// 中序 中缀表达式(受到优先级的影响, 可以通过输出一个树的时候加上括号)
// 后序 后缀表达式


// 两种遍历写确定一棵树, 一定要有中序, 不然无法确定左右序列
/*
 * 先根据先序遍历的第一个节点确定根节点
 * 根据 根节点 在中序遍历序列 中 分割左右两个子序列
 * 对左子树和右子树分别递归使用相同的办法分解
 *
 * */


int mian()
{

	return 0;
}
