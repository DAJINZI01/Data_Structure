#include <stdio.h>
#include <stdlib.h>

typedef int  ElementType;

typedef struct BTNode{
	ElementType data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BinTree, BTNode;


/*
 * 二叉搜索树：一棵二叉树，可以为空，如果不空，满足一下性质：
 * 1、非空左子树的所有键值小于根节点的键值
 * 2、非空右子树的所有键值大于根节点的键值
 * 3、左右子树都是二叉搜索树
 *
 *
 * */


/*
 * find 
 * 查找从根节点开始，如果为空，返回NULL
 * 若搜索树非空，根据节点关键字和X进行比较
 * 	< > =
 * */

BinTree*  find(BinTree *bt, ElementType x){
	if(bt == NULL)
		return NULL;
	if(x < bt->data)
		return find(bt->lchild, x);
	else if(x > bt->data)
		return find(bt->rchild, x);
	else 
		return bt;

}

BinTree*  iterFind(BinTree *bt, ElementType x){
	while(bt){
		if(x < bt->data)
			bt = bt->lchild;// 向左子树移动，继续查找
		else if(x > bt->data)
			bt = bt->rchild;// 向右子树移动，继续查找
		else 
			return bt;// 查找成功，返回该节点的地址
	
	}
	return NULL;// 查找失败
}

/*
 * 查找最大和最小元素
 * 最小元素一定在树的最右分支的端节点上
 * 最大元素一定在树的最左分支的端节点上
 *
 * */

BinTree* findMin(BinTree *bt){
	if(bt == NULL)
		return NULL;// 空的二叉搜索树，返回NULL
	if(bt->lchild == NULL)
		return bt;// 找到最左叶子节点并返回
	else  
		return findMin(bt->lchild);//沿左分支继续查找
}

// 非递归
BinTree* findMax(BinTree *bt){
	if(bt)
		while(bt->rchild)
			bt = bt->rchild;
			// 沿右分支一直到最右叶子节点
	return bt;
}

/*
 * 插入
 * 分析：关键是要找到元素应该插入的位置，可以采用与find类似的方法
 *
 * */
BinTree* insert(BinTree *bt, ElementType x){
	if(bt == NULL){
		// 若树为空，生成并返回一个节点的二叉搜索树
		bt = (BinTree *)malloc(sizeof(BinTree));
		bt->data = x;
		bt->lchild = bt->rchild = NULL;
	}

	if(x < bt->data)
		// 递归插入左子树
		bt->lchild = insert(bt->lchild, x);
	else if(x > bt->data)
		bt->rchild = insert(bt->rchild, x);
	// else x 已经存在，什么都不做

	return bt;
}

/*
 * 删除
 * 考虑三种情况
 * 1、删除的是叶节点，直接删除，并修改父节点的指针-置为NULL
 * 2、删除的节点只有一个孩子节点，将其父节点的指针指向要删除节点的孩子节点
 * 3、删除的节点有左、右两颗子树，用另一个节点替代删除的节点：右子树的最小元素 或者 左子树的最大元素
 * 	左子树的最大值，一定在最右边，一定没有右儿子。
 * 	右子树的最小值，一定在最左边，一定没有左儿子。
 * */

BinTree* Delete(BinTree *bt, ElementType x){
	BinTree *temp = NULL;
	if(!bt) printf("要删除的元素没有找到！");
	else if(x < bt->data)
		// 左子树递归删除
		bt->lchild = Delete(bt->lchild, x);
	else if(x > bt->data)
		// 右子树递归删除
		bt->rchild = Delete(bt->rchild, x);
	else {// 找到要删除的节点
		if(bt->lchild && bt->rchild){
			// 要删除的节点有左右两个子节点
			// 在右子树中找到最小的元素填充删除节点
			temp = findMin(bt->rchild);
			bt->data = temp->data;
			// 删除节点的右子树中删除最小元素，一定是没有左孩子，属于只有一个孩子节点的情况
			bt->rchild = Delete(bt->rchild, bt->data);
		}
		else{
			// 被删除节点有一个或无子节点
			temp = bt;
			if(!bt->lchild)
				// 有右孩子或无子节点
				bt = bt->rchild;
			else if(!bt->rchild)
				// 有左孩子或无子节点
				bt = bt->lchild;
			free(temp);
		}
	}
	return bt;
}


int main()
{

	return 0;
}
