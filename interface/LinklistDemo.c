#include<stdlib.h>
#include<stdio.h>
#include"../include/LinklistDemo.h"

/*// 初始化单链表(不带头结点的单链表)
void InitList(LinkList* L){
    *L = (LinkList)malloc(sizeof(LNode));
    (*L) = NULL;
}

// 尾插法建立单链表(不带头结点的单链表)
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

// 打印单链表中的元素(不带头结点的单链表)
void PrintList(LinkList* L){
    LNode* node = *L;
    int i=0;
    if (node != NULL)
    {
        printf("list[%d]==%d   ",i++,node->data);
        while (node->next != NULL&& i<5){
            node = node->next;
            printf("list[%d]==%d   ",i++,node->data);
            
        }
    }
    printf("\n");
}
*/
// 初始化单链表(带头结点的单链表)
void InitList(LinkList* L){
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
}

// 尾插法建立单链表(带有头节点的单链表)
void List_TailInsert(LinkList* L){
    LNode* node = *L;
    LNode *tmp;
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

// 删除不带头结点的单链表L中所有值为e的结点
void DeleteNoHeadList(LinkList *L,ElemType e){
    LNode* node;
    int count =0,count1 =0;
    if ((*L) == NULL)
    {
        return;
    }
    if ((*L)->data == e)
    {
        node = (*L);
        (*L) = (*L)->next;
        free(node);
        DeleteNoHeadList(L,e);
        count++;
    }else
    {
        DeleteNoHeadList(&(*L)->next,e);
        count1++;
    }
 
}

// 删除带头结点的单链表L中所有值为e的结点
void DeleteWithHeadList(LinkList *L,ElemType e){
    LNode *node = (*L)->next, *pre = *L, *q,*tmp;

    while (node != NULL)
    {
        if (node->data == e)
        {
            q = node;
            node = node->next;
            pre->next = node;
            free(q);
        }else
        {
            pre = node;
            node = node->next;
        }
    }
    
}

// 实现从头到尾反向输出每个结点的值
void ReserseOutput(LinkList *L){
    if ((*L)->next!=NULL)
    {
        ReserseOutput(&(*L)->next);
    }
    if ((*L) != NULL)
    {
        printf("%d  ",(*L)->data);
    }

}

void R_Ignore_Head(LinkList *L){
    if ((*L) != NULL)
    {
        ReserseOutput(&(*L)->next);
    }
    
}


// 将单链表中的元素反转
void ReserseList(LinkList *L){
    LNode *node = (*L)->next;
    LNode *tmp;

    if ((*L)->next == NULL)
    {
        printf("链表为空！！\n");
    }

    (*L)->next = NULL;

    while (node != NULL)
    {
        tmp = node->next;
        node->next = (*L)->next;
        (*L)->next = node;
        node = tmp;
    }
    
}

// 删除链表中最小元素
void DeleteMinElemOfList(LinkList *L){

}

// 打印单链表中的元素(带头结点的单链表)
void PrintList(LinkList* L){
    LNode* node = (*L)->next;
    int i=0;

    if (node == NULL)
    {
        printf("你错了！！！\n");
    }

    while (node != NULL)
    {
        printf("list[%d]==%d   ",i++,node->data);
        node = node->next;
    }
    printf("\n");
}