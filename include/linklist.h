#ifndef LINKLIST_H
#define LINKLIST_H 
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

// 头插法建立单链表
void List_HeadInsert(LinkList* L);

// 尾插法建立单链表
void List_TailInsert(LinkList* L);

// 按序号查找结点值
LNode* GetElem(LinkList* L,int i);

// 按值查找表结点
int LocateElem(LinkList* L,ElemType e);

//插入结点
bool InsertList(LinkList* L,ElemType e,int i);

//删除节点
bool DeleteList(LinkList* L,int i);

// 求单链表的表长
int LengthOfList(LinkList* L);

// 打印单链表中的元素
void PrintList(LinkList* L);

#endif