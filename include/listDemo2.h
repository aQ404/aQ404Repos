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

//将顺序表中元素逆置
void InveredList(List *list);

// 打印线性表的元素
void PrintList(List *list);

#endif