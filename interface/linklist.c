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
    LNode* tmp;
    scanf("%d",&e);
    while (e!=9999)
    {
        tmp = (LNode*)malloc(sizeof(LNode));
        tmp->data = e;
        tmp->next = node->next;
        node->next = tmp;
        scanf("%d",&e);
    }
    
}

// 尾插法建立单链表
void List_TailInsert(LinkList* L){
    LinkList node = *L;
    LNode *tmp ;
    int e;
    scanf("%d",&e);
    while (e != 9999)
    {
        tmp = (LNode*)malloc(sizeof(LNode));
        tmp->data = e;
        node->next = tmp;
        node = tmp;
        scanf("%d",&e);
    }
    node->next = NULL;
}

// 按序号查找结点值
LNode* GetElem(LinkList* L,int i){
    int j=0;
    LinkList node = (*L)->next;
    if (i == 0)
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
    bool flag =false;
    while (node != NULL)
    {
        if (node->data == e)
        {
            flag =true;
            break;
        }
        node = node->next;
        j++;
    }
    if (flag)
    {
        return j;
    }else
    {
        printf("该元素不在单链表中，输入错误！！！\n");
        return -1;
    }
    
}

//插入结点
bool InsertList(LinkList* L,ElemType e,int i){
    LNode *pre = *L,*tmp;
    int cnt = 0;
    while (pre&&cnt<i-1)
    {
        pre = pre->next;
        cnt++;
    }
    if (pre == NULL || cnt != i-1 )
    {
        printf("插入位置参数错误\n");
        return false;
    }else{
        tmp = (LNode*)malloc(sizeof(LNode));
        tmp->data = e;
        tmp->next = pre->next;
        pre->next = tmp;
        return true;
    }
}

//删除节点
bool DeleteList(LinkList* L,int i){
    LNode *pre,*tmp;
    int cnt = 0;
    pre = *L;
    while (pre && cnt != i-1)
    {
        pre = pre->next;
        cnt++;
    }
    if (pre == NULL || cnt != i-1 || pre->next == NULL)
    {
        printf("删除位置参数错误\n");
        return false;
    }else
    {
        tmp = pre->next;
        pre->next = tmp->next;
        free(tmp);
        return true;
    }  
}

// 求单链表的表长
int LengthOfList(LinkList* L){
    int count = 0;
    LinkList node = (*L)->next;
    while (node != NULL)
    {
        count++;
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