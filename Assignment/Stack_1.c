#include <stdio.h>
#include <stdlib.h>
#include "include/Stack_1.h"
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10


int InitStack(SqStack* S)//’ªµƒ≥ı ºªØ
{
      (*S).base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
      if((*S).base==NULL)    exit (-1);
      (*S).top=(*S).base;          //ø’’ª±Í÷æ
      (*S).stacksize =STACK_INIT_SIZE;
      return 1;
}

int ClearStack(SqStack *S)
{
    while((*S).top>(*S).base)
    {
        --(*S).top;
        *((*S).top)=0;
        
    }
    
    if((*S).top==(*S).base)
        {printf("Clear success!\n");return 1;}
    else
        {printf("Clear fail!\n");return 0;}

}

int DestoryStack(SqStack *S)
{
    if((*S).base)  {free((*S).base);printf("Destroy success!\n");return 1;}
    else   {printf("Destroy fail!\n");return 0;}
}

int Push(SqStack *S,int x)//»Î’ª
{
     if(((*S).top-(*S).base)>=(*S).stacksize)
     {
         (*S).base=(int *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(int));
         if(!(*S).base)  exit(-1);
         (*S).top=(*S).base+(*S).stacksize;
         (*S).stacksize+=STACKINCREMENT;
     }
         *((*S).top)=x;
         (*S).top++;
         return 1;
}

int StackLength(SqStack S)
{
    return (S.top-S.base);
}

int Pop(SqStack *S,int *x)//≥ˆ’ª
{
      if ((*S).top==(*S).base)
      {
          printf("’ªø’£°\n");
          return 0;
      }
      else
      {
          *x=*(--(*S).top);
          return 1;
      }
}

int Gettop(SqStack *S,int *x)//»°’ª∂•
{
    if ((*S).top==(*S).base)
      {
          printf("’ªø’£°\n");
          return 0;
      }
    else
     {
         *x=*((*S).top-1);
         return 1;
     }
}

int StackEmpty(SqStack  *S)//ºÏ—È «∑Ò’ªø’£¨ø’∑µ1
{
    if ((*S).top==(*S).base)
                  return  1 ;
    else
                  return  0 ;
}

int  PrintStack(SqStack *S)
{
    int *p;
    for(p=(*S).base;p<(*S).top;p++)
        printf("%d ",*p);
    printf("\n");
    return 1;
}


