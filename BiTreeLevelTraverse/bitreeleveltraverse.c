/**
 * 用队列作为辅助手段层序遍历二叉树
 * author： 王小平
 * date： 2015/12/04
 */

#include <stdio.h>
#include <stdlib.h>

/* 二叉链表表示的二叉树 */
typedef char TElemType;
typedef struct BiTNode   /* 结点结构 */
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

/* 前序遍历建立二叉树 */
void PreCreateBiTree(BiTree *T)
{
	TElemType ch;
	scanf("%c", &ch);
	
	if('#' == ch)
		*T = NULL;
	else {
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = ch;
		PreCreateBiTree(&((*T)->lchild));
		PreCreateBiTree(&((*T)->rchild));
	}
}

/* 顺序循环队列 */
#define MAXSIZE 100
typedef BiTree QElemType;
typedef struct
{
	QElemType data[MAXSIZE];
	int front, rear;     // 分别存放队头和队尾的位置
} SqQueue, *SqQueuePtr;

/* 初始化队列 */
void InitQueue(SqQueuePtr Q)
{
	Q->front = 0;
	Q->rear = 0;
}

/* 判断队列空 */
int QEmpty(SqQueuePtr Q)
{
	return (Q->front == Q->rear);
}

/* 判断队列满 */
int QFull(SqQueuePtr Q)
{
	return ((Q->rear + 1) % MAXSIZE == Q->front);
}

/* 从队尾入队列 */
typedef int Status;
#define OK 1
#define ERROR 0
Status EnQueue(SqQueuePtr Q, QElemType e)
{
	if(QFull(Q))   /* 队列满则返回错误 */
		return ERROR;

	Q->data[Q->rear++] = e;
	return OK;
}

/* 从队头出队列 */
Status DeQueue(SqQueuePtr Q, QElemType *e)
{
	if(QEmpty(Q))
		return ERROR;   /* 队列空则返回错误 */

	*e = Q->data[Q->front++];
	return OK;
}

/* 层序遍历二叉树 */
void LevelTraverse(BiTree T)
{
	SqQueuePtr queue;
	queue = (SqQueuePtr)malloc(sizeof(SqQueue));
	InitQueue(queue);

	/* 1、将二叉树的根结点入队列
	 * 2、将队头元素出队列
	 * 3、并将队头元素的左子树的根结点（非空）右子树的根结点（非空）分别入队列
	 * 4、重复2、3，直至队列中没有元素
	 */
	EnQueue(queue, T);
	QElemType tmp;
	while(!QEmpty(queue)) {
		DeQueue(queue, &tmp);
		printf("%3c", tmp->data);
		if(tmp->lchild)
			EnQueue(queue, tmp->lchild);
		if(tmp->rchild)
			EnQueue(queue, tmp->rchild);
	}
	printf("\n");
}

int main()
{
	BiTree tree;
	printf("Please input a binary tree:\n");
	PreCreateBiTree(&tree);

	printf("The result of level traverse:\n");
	LevelTraverse(tree);

	return 0;
}
