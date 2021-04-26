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

// 删除带头结点的单链表L中所有值为e的结点
void DeleteWithHeadList(LinkList *L,ElemType e);

// 实现从头到尾反向输出每个结点的值
void ReserseOutput(LinkList *L);
void R_Ignore_Head(LinkList *L);


// 将单链表中的元素反转
void ReserseList(LinkList *L);

// 删除链表中最小元素
void DeleteMinElemOfList(LinkList *L);

// 求单链表的表长
int LengthOfList(LinkList* L);

// 排序，使单链表递增有序
void SortLinkedList(LinkList* L);

// 删除介于给定的两个值之间的元素结点
void DeleteRangeList(LinkList *L,int min,int max);

// 找出两个链表的公共结点
LinkList FindCommonNode(LinkList *L1,LinkList *L2);

// 按递增次序输出单链表的元素，并释放结点所占空间
void PrintIncrease(LinkList *L);

// 单链表拆分成A，B，保持其相对顺序不变
void SplitList(LinkList *L);

// 将带头结点的单链表拆分成两个线性表，使得A = {a1,a2,...an},B = {bn,...b2,b1}
void SplitList02(LinkList *L);

// 删除单链表中重复元素
void DeleteRepeatingElems(LinkList *L);

// 合并两个递增单链表，使得合并后为递减单链表
void MergeList(LinkList *L1,LinkList *l2);

// 打印单链表中的元素
void PrintList(LinkList* L);


#endif