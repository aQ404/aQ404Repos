#ifndef LINKLISTDEMO_H
#define LINKLISTDEMO_H 
#include <stdbool.h>
#include<stdio.h>

#define MaxSize 10
#define ElemType int

typedef struct LNode
{
   ElemType data;
   struct LNode* next;
}LNode,*LinkList;

// 初始化单链表
void InitList(LinkList* L);

// 尾插法建立单链表
void List_TailInsert(LinkList* L);

// 删除不带头结点的单链表L中所有值为e的结点
void DeleteNoHeadList(LinkList *L,ElemType e);

// 求单链表的表长
int LengthOfList(LinkList* L);


// 打印单链表中的元素
void PrintList(LinkList* L);

#endif