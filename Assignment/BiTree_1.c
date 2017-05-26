#include <stdio.h>
#include <stdlib.h>
#include "include/BiTree_1.h"
#define MAX_TREE_SIZE 100
#define QUEUE_INIT_SIZE 100




int initQueue(Queue *Q)//��ʼ������
{
    (*Q).base=(BiTree *)malloc(QUEUE_INIT_SIZE*sizeof(BiTree));
    if(!(*Q).base)   {exit(-1);}
    (*Q).front=0;
    (*Q).rear=0;
    (*Q).QueueSize=QUEUE_INIT_SIZE;
    return 1;
}

int queueEmpty(Queue *Q)//�����Ƿ�ӿգ��շ���1
{
    if((*Q).rear%(*Q).QueueSize==(*Q).front)
        return 1;
    else
        return 0;
}

int enqueue(Queue *Q,BiTree *p)//����
{
    (*Q).base[(*Q).rear]=*p;
    (*Q).rear=((*Q).rear+1)%(*Q).QueueSize;
    return 1;
}

int outqueue(Queue *Q,BiTree * p)//����
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

int print(int e)//��ӡ����
{
    printf("%d ",e);
    return 1;
}

int createBiTree(BiTree *T)//����һ��������������ݹ飩����-1��ʾNULL
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

int BiTreeEmpty(BiTree * T)//��������
{
    if(*T==NULL)
        return 1;
    else
        return 0;
}

int LevelOrderTraverse(BiTree *T)//�������
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

BiTree Parent(BiTree *T,BiTree *q)//����q�ĸ��ڵ�
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

BiTree LeftSibling(BiTree *T,BiTree *q)//����q�����ֵ�
{
    BiTNode* p=Parent(T,q);
    if(*q==p->lchild)  return NULL;
    else    return (p->lchild);
}

BiTree RightSibling(BiTree *T,BiTree *q)//����q�����ֵ�
{
    BiTNode* p=Parent(T,q);
    if(*q==p->rchild)  return NULL;
    else    return (p->rchild);
}

BiTree LeftChild(BiTree *T,BiTree *p)//����q�������
{
    return ((*p)->lchild);
}

BiTree RightChild(BiTree *T,BiTree *p)//����q���Ҷ���
{
    return ((*p)->rchild);
}

int Value(BiTree p)//����p��ֵ
{
    int a;
    if(p)   {a=(p)->data;return (p)->data;}
    else return -1;
}

int Assign(BiTree *T,BiTree *p,int e)//��p��ֵe
{
    (*p)->data=e;
    return 1;
}

void InsertChild(BiTree *T,BiTree *p,int LR,BiTree c)//����LR��ֵ��c���뵽p�����ҽ���У�pԭ�������ҽ��Ϊc���Ҷ���
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

void DeleteChild(BiTree *T,BiTree *p,int LR)//����LR��ֵѡ��ɾ��p������ҽ��
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

int PreOrderTraverse_1(BiTree T,int(* visit)(int e))//����ݹ�
{
    if(T)
    {
        if(visit(T->data))
            if(PreOrderTraverse_1(T->lchild,visit))
                 if(PreOrderTraverse_1(T->rchild,visit))  return 1;
        return 0;
    }else   return 1;
}

int InOrderTraverse_1(BiTree T,int(* visit)(int e))//����ݹ�
{
    if(T)
    {
        if(InOrderTraverse_1(T->lchild,visit))
            if(visit(T->data))
                 if(InOrderTraverse_1(T->rchild,visit))  return 1;
        return 0;
    }else   return 1;
}

int PostOrderTraverse_1(BiTree T,int(* visit)(int e))//����ݹ�
{
    if(T)
    {
        if(PostOrderTraverse_1(T->lchild,visit))
            if(PostOrderTraverse_1(T->rchild,visit))
                if(visit(T->data)) return 1;
        return 0;
    }else   return 1;
}

//��������1 2 4 -1 -1 5 7 -1 -1 -1 3 6 -1 -1 -1
