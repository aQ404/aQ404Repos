#include<stdlib.h>
#include<stdio.h>
#include"../include/linklist.h"

// 头插法建立单链表
void List_HeadInsert(LinkList* L){
    LinkList node = *L;
    ElemType e;
    LNode* s;
    scanf("%d",&e);
    while (e!=9999)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = e;
        s->next = node->next;
        node->next = s;
        scanf("%d",&e);
    }
    
}

// 尾插法建立单链表
void List_TailInsert(LinkList* L);

// 按序号查找结点值
LNode* GetElem(LinkList* L,int i);

// 按值查找表结点
LNode* LocateElem(LinkList* L);

//插入结点
bool InsertList(LinkList* L,ElemType e,int i);

//删除节点
bool DeleteList(LinkList* L,int i);

// 求单链表的表长
int LengthOfList(LinkList* L);

// 打印单链表中的元素
void PrintList(LinkList* L){
    LinkList node = (*L)->next;
    int i=0;
    while (node!=NULL)
    {
        printf("list[%d]==%d   ",i++,node->data);
        node = node->next;
    }
    printf("\n");
}