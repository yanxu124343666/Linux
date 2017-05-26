#ifndef _CALC_H
#define _CALC_H

#define  MAX_VERTEX_NUM  100
#define  INFINITY 100000000
#define QUEUE_INIT_SIZE 100


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


int Dequeue(SqQueue *Q,int *p);
int CreateUDN(MGraph *G);
int Destroy(MGraph *G);
int print(int e);
int print_Vex(MGraph G);
int print_Arc(MGraph G);
int LocateVex(MGraph G,int v);
int GetVex(MGraph G,int v);
int PutVex(MGraph *G,int v,int value);
int FirstAdjVex(MGraph G,int v);
int NextAdjVex(MGraph G,int v,int w);
int InsertVex(MGraph *G,int v);
int DeleteVex(MGraph *G,int v);
int InsertArc(MGraph *G,int v,int w,int ww);
int DeleteArc(MGraph *G,int v,int w);
void DFS(MGraph G,int v);
void DFSTraverse(MGraph G);
void BFSTraverse(MGraph G);

#endif //_CALC_H
