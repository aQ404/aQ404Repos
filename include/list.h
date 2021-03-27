#ifndef __LIST_H_
#define __LIST_H_
#include <stdbool.h>

#define MaxSize 100
#define ElemType int

typedef struct LNode
{
    ElemType data[MaxSize];
    ElemType length;   
}LNode;

typedef struct LNode* List;

// 初始化一个线性顺序表
void InitList(List *list);

// 判断线性表是否为空，若是则返回true，否则返回false
bool ListIsEmpty(List *list);

// 判断线性表是否已满，已满则返回true，否则返回false
bool ListIsFull(List *list);

// 根据指定位置的位序i,返回L中相应的元素e
ElemType FindElemOfList(List *list,int i);

// 在List的指定位序i前插入一个新元素e；成功返回true，失败返回flase
bool InsertElemIntoList(List *lsit,int i,ElemType e);

// 从List中删除指定位序i的元素；成功返回true，失败返回flase，并保存删除的元素
bool DeleteElemFromList(List *list,int i, ElemType *e);

// 返回线性表的长度length
int LengthOfList(List *list);

// 打印线性表的元素
void PrintList(List *list);

#endif