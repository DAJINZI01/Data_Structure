#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TreeNode{
	ElementType data;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
}BinTree;

/*
 * “平衡因子（Balance Factor, BF）”：BF(T) = Hl - Hr;
 * 其中Hl 和 Hr分别为T的左右子树的高度
 *
 * 平均查找长度（ASL）
 *
 * 平衡二叉树（Balance  Binary Tree）（AVL树）
 * 空树，或者
 * 任 一节点 左右子树的高度差绝对值不超过1，即BF(T)<=1
 *
 * 平衡二叉树的高度能达到log2(n)吗？
 * n(h) = n(h-1) + n(h-2) + 1
 * n(h) = F(h+2) - 1
 * h = log2(n)
 * 给定节点数为n的AVL树的最大高度为O(log2(n))
 *
 * */

/*
 * 平衡二叉树的调整
 * 	不平衡的“发现者”，“麻烦节点”在发现者右子树的右边，因而叫RR插入，需要RR旋转（右单旋）
 * 	不平衡的“发现者”，“麻烦节点”在发现者左子树的左边，因而叫LL插入，需要LL旋转（左单旋）
 * 	不平衡的“发现者”，“麻烦节点”在发现者左子树的右边，因而叫LR插入，需要LR旋转
 * 	不平衡的“发现者”，“麻烦节点”在发现者右子树的左边，因而叫RL插入，需要RL旋转
 *
 * 	注意：有时候插入元素即使不需要调整结构，也可能重新计算一些平衡因子
 * */


int main()
{

	return 0;
}
