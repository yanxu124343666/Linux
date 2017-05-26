#ifndef _CALC_H
#define _CALC_H

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct//栈（非递归的先序、中序、后序使用）
{
    int *base;
    int *top;
    int  stacksize;
}SqStack;


int InitStack(SqStack* S);
int ClearStack(SqStack *S);
int DestoryStack(SqStack *S);
int Push(SqStack *S,int x);
int StackLength(SqStack S);
int Pop(SqStack *S,int *x);
int Gettop(SqStack *S,int *x);
int StackEmpty(SqStack  *S);
int PrintStack(SqStack *S);

#endif //_CALC_H
