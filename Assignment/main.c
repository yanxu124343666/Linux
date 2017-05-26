#include <stdio.h>
#include <malloc.h>

#include "include/BiTree_1.h"
#include "include/Queue_1.h"
#include "include/Stack_1.h"
#include "include/Graph_1.h"

#define MAX_VERTEX_NUM 100

typedef struct//栈（非递归的先序、中序、后序使用）
{
    int *base;
    int *top;
    int  stacksize;
}SqStack;

typedef struct SqQueue{
    int *base;
    int front;
    int rear;
    int QueueSize;
}SqQueue;


typedef int AdjMatrix;
typedef struct
{
    int Value;

}VertexType;
typedef struct
{
    VertexType vex[MAX_VERTEX_NUM];//顶点向量
    AdjMatrix  arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//邻接矩阵
    int vexnum,arcnum;//图的当前顶点数和弧数
    int kind;//图的类型:1有向图；2有相网；3无向图；4无向网
}MGraph;


void StackTest()
{
    SqStack S;
    int i,x;
    InitStack(&S);
    for(i=0;i<10;i++)
        {Push(&S,i);}

    printf("是否栈空（1->空  0->不空）：");
    printf("%d\n",StackEmpty(&S));

    printf("此时栈为：");
    PrintStack(&S);

    printf("删除栈中元素：\n");
    Pop(&S,&x);
    printf("%d\n",x);
    Pop(&S,&x);
    printf("%d\n",x);

    printf("取栈顶：");
    Gettop(&S,&x);
    printf("%d\n",x);

    printf("此时栈为：");
    PrintStack(&S);
    printf("此时栈的长度为：");
    printf("%d\n",StackLength(S));

    ClearStack(&S);
    DestoryStack(&S);
}

void QueueTest()
{
    SqQueue Q;
    InitQueue(&Q);
    int i,x;
    for(i=0;i<10;i++)
        Enqueue(&Q,i);
    printf("当前队列为：");
    PrintQueue(Q);
    
    printf("出队元素为：\n");
    for(i=0;i<4;i++)
    {Outqueue(&Q,&x);printf("%d\n",x);}
    printf("当前队列为：");
    PrintQueue(Q);
    
    Gethead(&Q,&x);printf("当前队头：%d\n",x);
    printf("是否队空(1->空  0->非空)：%d\n",QueueEmpty(&Q));
    printf("队列长度为：%d\n",QueueLength(Q));
    ClearQueue(&Q);
    DestoryQueue(&Q);
}

//测试树：1 2 4 -1 -1 5 7 -1 -1 -1 3 6 -1 -1 -1
void BiTreeTest()
{
    BiTree T,q,c;
    printf("请先序输入一棵二叉树：\n");
    createBiTree(&T);
    InitBiTree(&c);


    if(!BiTreeEmpty(&T))
    {   q=T->lchild;q=q->rchild;//设定一个q

        printf("层序遍历：");
        LevelOrderTraverse(&T);printf("\n");//层序
        printf("先序遍历：");       
        PreOrderTraverse_1(T,print);printf("\n");//先序
        printf("中序遍历：");
        InOrderTraverse_1(T,print);printf("\n");//中序
        printf("后序遍历：");
        PostOrderTraverse_1(T,print);printf("\n");//后序
        printf("q结点的值：");
        printf("%d\n",Value(q));//打印
        printf("q的父节点：");
        printf("%d\n",(Parent(&T,&q)->data));//q的父节点
        printf("q的左兄弟：");
        printf("%d\n",Value((LeftSibling(&T,&q))));//左兄弟
        printf("q的右兄弟：");
        printf("%d\n",Value((RightSibling(&T,&q))));//右兄弟
        printf("q的左儿子：");
        printf("%d\n",Value((LeftChild(&T,&q))));//左儿子
        printf("q的右儿子：");
        printf("%d\n",Value((RightChild(&T,&q))));//右儿子
        printf("q赋完新值100\n先序遍历："); 
        Assign(&T,&q,100);//给q赋值100
        PreOrderTraverse_1(T,print);printf("\n");
        printf("q的左儿子值变成0，原q的左儿子变成0的右儿子\n先序遍历：");
        InsertChild(&T,&q,0,c);//让q的左儿子变成c，c的右儿子为原q的左儿子
        PreOrderTraverse_1(T,print);printf("\n");
        printf("删除q的左儿子\n先序遍历：");
        DeleteChild(&T,&q,0);//删除q的左儿子
        PreOrderTraverse_1(T,print);printf("\n");

        ClearBiTree(&T);
    }
}

/*测试数据：
5 6
1 2 3 4 5
1 2 8
2 4 9
4 3 11
3 5 10
1 3 6
1 5 7*/
void GraphTest()
{
    MGraph G;
    CreateUDN(&G);

    printf("深度优先搜索图：");
    DFSTraverse(G);
    printf("\n");
    printf("广度优先搜索图：");
    BFSTraverse(G);
    printf("\n");
    printf("图的点及边的情况为：");
    print_Vex(G);
    print_Arc(G);

    int lll=LocateVex(G,3);
    printf("3的位置为：%d\n",lll);
    printf("此位置上的值为：%d\n",GetVex(G,lll));
    PutVex(&G,lll,111);
    printf("替换后此位置上的值为：%d\n",GetVex(G,lll));
    int kkk=FirstAdjVex(G,lll);
    printf("111的第一个邻接点的值为：%d\n",GetVex(G,kkk));
    kkk=NextAdjVex(G,lll,kkk);
    printf("111的相对于上个点的邻接点的值为：%d\n",GetVex(G,kkk));

    printf("深度优先搜索图：");
    DFSTraverse(G);
    printf("\n");
    printf("广度优先搜索图：");
    BFSTraverse(G);
    printf("\n");

    InsertArc(&G,1,4,100);
    printf("插入权为100的边（1，4）后，图的边情况为：\n");
    print_Arc(G);

    DeleteArc(&G,1,2);
    printf("删除权为8的边（1，2）后，图的边情况为：\n");
    print_Arc(G);

    InsertVex(&G,888);
    printf("插入新节点888后，图的点及边的情况为：");
    print_Vex(G);
    print_Arc(G);

    DeleteVex(&G,111);
    printf("删除旧节点111后，图的点及边的情况为：");
    print_Vex(G);
    print_Arc(G);

    printf("深度优先搜索图：");
    DFSTraverse(G);
    printf("\n");
    printf("广度优先搜索图：");
    BFSTraverse(G);
    printf("\n");
    
}

int main(void)
{
    printf("Queue:\n");
    QueueTest();
    printf("\n");

    printf("Stack:\n");
    StackTest();
    printf("\n");

    printf("Graph:\n");
    GraphTest();
    printf("\n");

    printf("BiTree:\n");
    BiTreeTest();
    printf("\n");

    return 0;
}
