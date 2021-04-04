#include<stdlib.h>
#include<stdio.h>
#include"../include/linklist.h"

// 初始化单链表
void InitList(LinkList* L){
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
}

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
void List_TailInsert(LinkList* L){
    LinkList node = *L;
    LNode *s ;
    int e;
    scanf("%d",&e);
    while (e != 9999)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = e;
        node->next = s;
        node = s;
        scanf("%d",&e);
    }
    node->next = NULL;
}

// 按序号查找结点值
LNode* GetElem(LinkList* L,int i){
    int j=1;
    LinkList node = (*L)->next;
    if (i == 1)
    {
        return node;
    }
    
    if (i < 1)
    {
        return NULL;
    }
    
    while (node != NULL && j<i)
    {
        node = node->next;
        j++;  
    }
    return node;
}

// 按值查找表结点
int LocateElem(LinkList* L,ElemType e){
    LNode* node = (*L)->next;
    int j=0;
    while (node != NULL && node->data != e)
    {
        node = node->next;
        j++;
    }
    return j;
}

//插入结点
bool InsertList(LinkList* L,ElemType e,int i);

//删除节点
bool DeleteList(LinkList* L,int i);

// 求单链表的表长
int LengthOfList(LinkList* L){
    int count = 0;
    LinkList node = (*L)->next;
    while (node != NULL)
    {
        count++;
        printf("count == %d\n",count);
        node = node->next;
    }
    return count;
}

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