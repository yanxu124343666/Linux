#include <stdio.h>
#include <stdlib.h>
#include "include/Queue_1.h"
#define QUEUE_INIT_SIZE 100


int InitQueue(SqQueue *Q)//初始化队列
{
    (*Q).base=(int *)malloc(QUEUE_INIT_SIZE*sizeof(int));
    if(!(*Q).base)   {exit(-1);}
    (*Q).front=0;
    (*Q).rear=0;
    (*Q).QueueSize=QUEUE_INIT_SIZE;
    return 1;
}

int ClearQueue(SqQueue *Q)
{int i;
    while((*Q).front!=(*Q).rear)
    {
       (*Q).base[(*Q).front]=0;
       (*Q).front=((*Q).front+1)%(*Q).QueueSize;
    }
    if((*Q).front==(*Q).rear)   {printf("Clear success!\n");return 1;}
    else     {printf("Clear fail!\n");return 0;}
}

int DestoryQueue(SqQueue *Q)
{
    if((*Q).base)  {free((*Q).base);printf("Destroy success!\n");return 1;}
    else   {printf("Destroy fail!\n");return 0;}
}

int QueueEmpty(SqQueue *Q)//检验是否队空，空返回1
{
    if((*Q).rear%(*Q).QueueSize==(*Q).front)
        return 1;
    else
        return 0;
}
int Gethead(SqQueue *Q,int *p)
{
    *p=(*Q).base[(*Q).front];
    return 1;
}

int Enqueue(SqQueue *Q,int p)//进队
{
    (*Q).base[(*Q).rear]=p;
    (*Q).rear=((*Q).rear+1)%(*Q).QueueSize;
    return 1;
}

int Outqueue(SqQueue *Q,int *p)//出队
{
    if(QueueEmpty(Q)==0)
    {
        *p=(*Q).base[(*Q).front];
        (*Q).front=((*Q).front+1)%(*Q).QueueSize;
        return 1;
    }
    else
    {
        return 0;
    }
}


int QueueLength(SqQueue Q)
{
    return (Q.rear-Q.front+QUEUE_INIT_SIZE)%QUEUE_INIT_SIZE;
}

void PrintQueue(SqQueue Q)
{
    int i;
    for(i=Q.front;i<Q.rear;i++)
    {
        printf("%d ",Q.base[i]);
    }
    printf("\n");
}



