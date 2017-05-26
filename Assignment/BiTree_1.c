#include <stdio.h>
#include <stdlib.h>
#include "include/BiTree_1.h"
#define MAX_TREE_SIZE 100
#define QUEUE_INIT_SIZE 100




int initQueue(Queue *Q)//初始化队列
{
    (*Q).base=(BiTree *)malloc(QUEUE_INIT_SIZE*sizeof(BiTree));
    if(!(*Q).base)   {exit(-1);}
    (*Q).front=0;
    (*Q).rear=0;
    (*Q).QueueSize=QUEUE_INIT_SIZE;
    return 1;
}

int queueEmpty(Queue *Q)//检验是否队空，空返回1
{
    if((*Q).rear%(*Q).QueueSize==(*Q).front)
        return 1;
    else
        return 0;
}

int enqueue(Queue *Q,BiTree *p)//进队
{
    (*Q).base[(*Q).rear]=*p;
    (*Q).rear=((*Q).rear+1)%(*Q).QueueSize;
    return 1;
}

int outqueue(Queue *Q,BiTree * p)//出队
{
    if(QueueEmpty(Q)==0)
    {
        *p=(*Q).base[(*Q).front];
        (*Q).front++;
        return 1;
    }
    else
    {
        return 0;
    }
}

int InitBiTree(BiTree * T)
{
    (*T)=(BiTNode *)malloc(sizeof(BiTNode));
    (*T)->data=0;
    (*T)->lchild=NULL;
    (*T)->rchild=NULL;
    return 1;
}

int print(int e)//打印函数
{
    printf("%d ",e);
    return 1;
}

int createBiTree(BiTree *T)//创建一个二叉树（先序递归）输入-1表示NULL
{
    int ch;
    scanf("%d",&ch);
    if(ch==-1)  (*T)=NULL;
    else
    {
        if(!((*T)=(BiTNode *)malloc(sizeof(BiTNode))))   exit(-1);
        (*T)->data=ch;
        createBiTree(&((*T)->lchild));
        createBiTree(&((*T)->rchild));
    }
    
    return 1;
}

int ClearBiTree(BiTree *T)
{
    if(*T) {(*T)=NULL;printf("Clear success!\n");return 1;}
    else   {printf("Clear fail!\n");return 0;}
}

int DestoryBiTree(BiTree *T)
{
    if(T)  {free(T);printf("Destroy success!\n");return 1;}
    else   {printf("Destroy fail!\n");return 0;}
}

int BiTreeEmpty(BiTree * T)//检验树空
{
    if(*T==NULL)
        return 1;
    else
        return 0;
}

int LevelOrderTraverse(BiTree *T)//层序遍历
{
    BiTNode *p;
    Queue Q;initQueue(&Q);
    p=*T;
    if(p)   {enqueue(&Q,&p);}
    else    {return 0;}
    while(!queueEmpty(&Q))
    {
        outqueue(&Q,&p);
        printf("%d ",p->data);
        if(p->lchild)  {enqueue(&Q,&(p->lchild));}
        if(p->rchild)  {enqueue(&Q,&(p->rchild));}
    }
    return 1;
}

BiTree Parent(BiTree *T,BiTree *q)//返回q的父节点
{
    if(*q==*T)  return NULL;
    BiTNode *p;
    Queue Q;initQueue(&Q);
    p=*T;
    if(p)   {enqueue(&Q,&p);}
    else    {return 0;}
    while(!queueEmpty(&Q))
    {
        outqueue(&Q,&p);
        if(p->lchild)
        {
            if(p->lchild==*q)  {return  p;}
            enqueue(&Q,&(p->lchild));
        }
        if(p->rchild)
        {
            if(p->rchild==*q)  {return  p;}
            enqueue(&Q,&(p->rchild));
        }
    }
}

BiTree LeftSibling(BiTree *T,BiTree *q)//返回q的左兄弟
{
    BiTNode* p=Parent(T,q);
    if(*q==p->lchild)  return NULL;
    else    return (p->lchild);
}

BiTree RightSibling(BiTree *T,BiTree *q)//返回q的右兄弟
{
    BiTNode* p=Parent(T,q);
    if(*q==p->rchild)  return NULL;
    else    return (p->rchild);
}

BiTree LeftChild(BiTree *T,BiTree *p)//返回q的左儿子
{
    return ((*p)->lchild);
}

BiTree RightChild(BiTree *T,BiTree *p)//返回q的右儿子
{
    return ((*p)->rchild);
}

int Value(BiTree p)//返回p的值
{
    int a;
    if(p)   {a=(p)->data;return (p)->data;}
    else return -1;
}

int Assign(BiTree *T,BiTree *p,int e)//给p赋值e
{
    (*p)->data=e;
    return 1;
}

void InsertChild(BiTree *T,BiTree *p,int LR,BiTree c)//根据LR的值将c插入到p的左右结点中，p原本的左右结点为c的右儿子
{
    BiTree q;
    if(LR==0)
    {
        q=(*p)->lchild;
        (*p)->lchild=c;
        c->rchild=q;
    }
    else
    {
        q=(*p)->rchild;
        (*p)->rchild=c;
        c->rchild=q;
    }
}

void DeleteChild(BiTree *T,BiTree *p,int LR)//根据LR的值选择删除p的左或右结点
{
    if(LR==0)
    {
        (*p)->lchild=NULL;
    }
    else
    {
        (*p)->rchild=NULL;
    }
}

int PreOrderTraverse_1(BiTree T,int(* visit)(int e))//先序递归
{
    if(T)
    {
        if(visit(T->data))
            if(PreOrderTraverse_1(T->lchild,visit))
                 if(PreOrderTraverse_1(T->rchild,visit))  return 1;
        return 0;
    }else   return 1;
}

int InOrderTraverse_1(BiTree T,int(* visit)(int e))//中序递归
{
    if(T)
    {
        if(InOrderTraverse_1(T->lchild,visit))
            if(visit(T->data))
                 if(InOrderTraverse_1(T->rchild,visit))  return 1;
        return 0;
    }else   return 1;
}

int PostOrderTraverse_1(BiTree T,int(* visit)(int e))//后序递归
{
    if(T)
    {
        if(PostOrderTraverse_1(T->lchild,visit))
            if(PostOrderTraverse_1(T->rchild,visit))
                if(visit(T->data)) return 1;
        return 0;
    }else   return 1;
}

//测试树：1 2 4 -1 -1 5 7 -1 -1 -1 3 6 -1 -1 -1
