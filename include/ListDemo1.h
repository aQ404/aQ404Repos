#ifndef LIST_H
#define LIST_H  
#include <stdbool.h>
#include<stdio.h>



#define MaxSize 10
#define ElemType int

typedef struct LNode
{
    ElemType data[MaxSize];
    ElemType length;   
}LNode;

typedef struct LNode* List;

// 初始化一个线性顺序表
void InitList(List *list);

//删除顺序表中最小元素
bool DeleteMinNums(List *list,ElemType *e);

// 找到顺序表中最小元素
ElemType FindMinNum(List *list , ElemType *e);

// 打印线性表的元素
void PrintList(List *list);

#endif