#include <stdio.h>
#include <stdlib.h>

#include "include/Graph_1.h"
#include "include/Queue_1.h"

#define  MAX_VERTEX_NUM  100
#define  INFINITY 100000000
#define QUEUE_INIT_SIZE 100



int CreateUDN(MGraph *G)//无向网的创建
{
    int w,i,j,k;int v1,v2;
    (*G).kind=4;
    printf("Please input the number of vex & arc:");
    scanf("%d%d",&(*G).vexnum,&(*G).arcnum);

    for(i=0;i<(*G).vexnum;++i)
        for(j=0;j<(*G).vexnum;++j)
            {(*G).vex[i].Value=0;}

    printf("Please input all vex:");
    for(i=0;i<(*G).vexnum;++i)
        {scanf("%d",&(*G).vex[i].Value);}

    for(i=0;i<(*G).vexnum;++i)
        for(j=0;j<(*G).vexnum;++j)
        (*G).arcs[i][j]=INFINITY;

    printf("Please input all arc & value:\n");
    for(k=0;k<(*G).arcnum;++k)
    {
        scanf("%d%d%d",&v1,&v2,&w);//v1到v2边的权值为w
        i=LocateVex((*G),v1);
        j=LocateVex((*G),v2);
        (*G).arcs[i][j]=w;
        (*G).arcs[j][i]=w;
    }

    return 1;
}

int  Destroy(MGraph *G)
{
    if(G)  {free(G);printf("Destroy success!\n");return 1;}
    else   {printf("Destroy fail!\n");return 0;}
}

int print_Vex(MGraph G)//打印点
{
    int i;
    for(i=0;i<G.vexnum;i++)
        printf("%d ",G.vex[i].Value);
    printf("\n");
return 1;
}

int  print_Arc(MGraph G)//打印边
{
    int i,j;
    for(i=0;i<G.vexnum;i++)
    {
         for(j=0;j<G.vexnum;j++)
         {
             if(G.arcs[i][j]!=INFINITY)
                printf("%d\t",G.arcs[i][j]);
             else
                printf("#\t");
         }
         printf("\n");
    }
return 1;
}

int LocateVex(MGraph G,int v)//找到顶点v在图中的坐标位置
{
    int i;
    for(i=0;i<G.vexnum;++i)
        if(G.vex[i].Value==v)  break;
    if(i==G.vexnum)  return -1;
    else   return i;
}

int GetVex(MGraph G,int v)//找到标号为v的顶点
{
    return G.vex[v].Value;
}

int PutVex(MGraph *G,int v,int value)//将标号为v的顶点值赋为value
{
    (*G).vex[v].Value=value;
    return 1;
}

int FirstAdjVex(MGraph G,int v)//返回第一个与v相邻的顶点标号
{int i;
    for(i=0;i<G.vexnum;i++)
    {
        if(G.arcs[v][i]!=INFINITY)
            return i;
    }
    if(i==G.vexnum)  return -1;
}

int NextAdjVex(MGraph G,int v,int w)//返回相对于w的下一个与v相邻的顶点标号
{int i;
    for(i=w+1;i<G.vexnum;i++)
    {
        if(G.arcs[v][i]!=INFINITY)
            return i;
    }
    if(i==G.vexnum)  return -1;
}

int InsertVex(MGraph *G,int v)//将顶点v插入到图中
{int i;
    (*G).vex[(*G).vexnum].Value=v;
    for(i=0;i<=(*G).vexnum;i++)
    {
        (*G).arcs[i][(*G).vexnum]=INFINITY;
        (*G).arcs[(*G).vexnum][i]=INFINITY;
    }
    ++(*G).vexnum;
    return 1;
}

int DeleteVex(MGraph *G,int v)//将顶点v删除
{int i,j;
    int a=LocateVex((*G),v);
    --(*G).vexnum;
    for(i=a;i<(*G).vexnum;i++)
    {
        (*G).vex[i].Value=(*G).vex[i+1].Value;
        for(j=0;j<=(*G).vexnum;j++)
        {
            (*G).arcs[j][i]=(*G).arcs[j][i+1];
        }
    }
    for(i=a;i<(*G).vexnum;i++)
    {
        for(j=0;j<(*G).vexnum;j++)
        {
            (*G).arcs[i][j]=(*G).arcs[i+1][j];
        }
    }

    return 1;
}

int InsertArc(MGraph *G,int v,int w,int ww)//插入边（v,w）权值为ww
{
    int a=LocateVex(*G,v);
    int b=LocateVex(*G,w);
    (*G).arcs[a][b]=ww;
    (*G).arcs[b][a]=ww;
    return 1;
}

int DeleteArc(MGraph *G,int v,int w)//删除边（v,w）
{
    int a=LocateVex(*G,v);
    int b=LocateVex(*G,w);
    (*G).arcs[a][b]=INFINITY;
    (*G).arcs[b][a]=INFINITY;
    return 1;
}

int flag[MAX_VERTEX_NUM]={0};
void DFSTraverse(MGraph G)
{int v;
    for(v=0;v<G.vexnum;++v)
        flag[v]=0;
    for(v=0;v<G.vexnum;++v)
        if(flag[v]==0)  DFS(G,v);
}
void DFS(MGraph G,int v)
{int w;
    flag[v]=1;
    print(G.vex[v].Value);
    for(w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,w))
        if(flag[w]==0)  DFS(G,w);
}

int visited[MAX_VERTEX_NUM]={0};
void BFSTraverse(MGraph G)
{int v,u,w;SqQueue Q;
    for(v=0;v<G.vexnum;v++)
        visited[v]=0;
    InitQueue(&Q);
    for(v=0;v<G.vexnum;v++)
    {
        if(visited[v]==0)
        {
            visited[v]=1;
            printf("%d ",G.vex[v].Value);
            Enqueue(&Q,v);
            while(!QueueEmpty(&Q))
            {
                Outqueue(&Q,&u);
                for(w=FirstAdjVex(G,u);w>=0;w=NextAdjVex(G,u,w))
                {
                    if(visited[w]==0)
                    {
                        visited[w]=1;
                        printf("%d ",G.vex[w].Value);
                        Enqueue(&Q,w);
                    }
                }
            }
        }
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
