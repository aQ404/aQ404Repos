#include<stdlib.h>
#include<stdio.h>
#include"../include/LinklistDemo.h"

// 初始化单链表
void InitList(LinkList* L){
    *L = (LinkList)malloc(sizeof(LNode));
    (*L) = NULL;
}


// 尾插法建立单链表
void List_TailInsert(LinkList* L){
    LinkList node;
    LNode *tmp ;
    int e;
    scanf("%d",&e);
    if (e!=9999)
    {
        tmp = (LNode*)malloc(sizeof(LNode));
        tmp->data = e;
        (*L) = tmp;
        node = *L;
        scanf("%d",&e);
        while (e != 9999)
        {
            tmp = (LNode*)malloc(sizeof(LNode));
            tmp->data = e;
            node->next = tmp;
            node = tmp;
            scanf("%d",&e);
        }
    }
    node->next = NULL;
}


// 删除不带头结点的单链表L中所有值为e的结点
void DeleteNoHeadList(LinkList L,ElemType e){
    LNode *node;
    if (L == NULL)
    {
        return ;
    }
    if (L->data = e)
    {
        node = L;
        L = L->next;
        free(node);
        DeleteNoHeadList(L,e);
    }else
    {
        DeleteNoHeadList(L->next,e);
    }
 
}

// 打印单链表中的元素
void PrintList(LinkList* L){
    LNode* node = *L;
    int i=0;
    if (node != NULL)
    {
        printf("list[%d]==%d   ",i++,node->data);
        while (node->next != NULL){
            node = node->next;
            printf("list[%d]==%d   ",i++,node->data);
            
        }
    }
    printf("\n");
}