#ifndef _CALC_H
#define _CALC_H

#define MAX_TREE_SIZE 100
#define QUEUE_INIT_SIZE 100

typedef struct BiTNode//二叉树
{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,* BiTree;

typedef struct Queue{
    BiTree *base;
    int front;
    int rear;
    int QueueSize;
}Queue;


int initQueue(Queue *Q);
int queueEmpty(Queue *Q);
int enqueue(Queue *Q,BiTree *p);
int outqueue(Queue *Q,BiTree * p);
int InitBiTree(BiTree * T);
int print(int e);
int createBiTree(BiTree *T);
int ClearBiTree(BiTree *T);
int DestoryBiTree(BiTree *T);
int BiTreeEmpty(BiTree * T);
int LevelOrderTraverse(BiTree *T);
BiTree Parent(BiTree *T,BiTree *q);
BiTree LeftSibling(BiTree *T,BiTree *q);
BiTree RightSibling(BiTree *T,BiTree *q);
BiTree LeftChild(BiTree *T,BiTree *p);
BiTree RightChild(BiTree *T,BiTree *p);
int Value(BiTree p);
int Assign(BiTree *T,BiTree *p,int e);
void InsertChild(BiTree *T,BiTree *p,int LR,BiTree c);
void DeleteChild(BiTree *T,BiTree *p,int LR);
int PreOrderTraverse_1(BiTree T,int(* visit)(int e));
int InOrderTraverse_1(BiTree T,int(* visit)(int e));
int PostOrderTraverse_1(BiTree T,int(* visit)(int e));


#endif //_CALC_H
