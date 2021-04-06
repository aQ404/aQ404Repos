#ifndef LISTDEMO2_H
#define LISTDEMO2_H  
#include <stdbool.h>
#include<stdio.h>



#define MaxSize 10
#ifndef ElemType
 #define ElemType int
#endif


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

// 从List中删除值为e的所有元素
bool DeleteElemFromList(List *list,ElemType e);

// 从有序list中删除所有重复元素
bool DeleteRepeatElemFromList(List *list);

// 打印线性表的元素
void PrintList(List *list);

#endif