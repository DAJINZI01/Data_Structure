#include <stdio.h>
#include <stdlib.h>

typedef enum{Link, Thread} PointerThr;
// Link == 0 指针，Thread == 1 线索

typedef char ElementType;
typedef struct BiThrNode{
	ElementType data;
	PointerThr ltag, rtag;// 左右标志
	struct BiThrNode *lchild, *rchild;// 左右指针
}BiThrNode, *BiThrTree;


/* for(p = firstNode(T); p; p = succ(p))
 * 	visit(p);
 *
 * 中序线索化链表的遍历
 * 中序遍历的第一个节点？
 * 	左子树上处于“最左下”, 没有左子树的节点
 * 在中序线索化链表中节点的后继？
 * 	对于节点p，若要找其后继节点，
 *	p->rtag = 1 时，p->rchild即为p的后继节点
 * 	p->rtag = 0 时，说明p有右子树，此时p的中序后继节点即为其右子树的“最左下端”的节点
 * 在中序线索二叉树中找前驱节点
 *	p->ltag = 1 时，p->lchild即为p的前驱
 * 	p->ltag = 0 时，p->lchind指向p的左孩子
 * 	由中序遍历的规律可知，作为根p的前驱节点，它是中序遍历
 * 	的左子树是访问的最后一个节点, 即左子树的“最右下端”节点。
 * */
