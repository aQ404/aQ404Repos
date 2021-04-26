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
    LNode *node = (*L)->next,*pre = (*L);
    LNode *Minpre = pre,*Min = node;
    while (node)
    {
        if (node->data<Min->data)
        {
            Min = node;
            Minpre = pre;
        }
        pre = node;
        node = node->next;
    }

    Minpre->next = Min->next;
    free(Min);
}

// 排序，使单链表递增有序
void SortLinkedList(LinkList* L){
    LNode* node = (*L)->next;
    // 冒泡排序
    // while (node)
    // {
    //    LNode *tmp =node->next;
    //    while (tmp)
    //    {
    //        if(tmp->data<node->data){
    //            ElemType e =node->data;
    //            node->data = tmp->data;
    //            tmp->data = e;
    //        }
    //        tmp = tmp->next;
    //    }
    //    node = node->next;
       
    // }
    // 插入排序
    LNode *tail = node;
    
    while (tail->next)
    {
        tail = tail->next;
    }
    
    LNode *r;
    r = tail;
    while (node != tail)
    {
        LNode *pre = (*L);
        LNode *minpre = pre,*min = node;
        while (node != tail)
        {
            if (node->data < min->data)
            {
                min = node;
                minpre = pre;
            }
            pre = node;
            node = node->next;
        }
        minpre->next = min->next;
        r->next = min;
        r = min;
        node= (*L)->next;
    }
    r->next = NULL;
    node = (*L)->next;
    LNode *tmp = node->next;
    while (node)
    {
        if (node->data > tail->data)
        {
            
            tail->next = node->next;
            node->next = tail;
            ElemType temp = node->data;
            node->data = tail->data;
            tail->data = temp;
            break;
        }
        
        node = node->next;
    }
    (*L)->next = tmp;
}

// 删除介于给定的两个值之间的元素结点
void DeleteRangeList(LinkList *L,int min,int max){
    LNode *node = (*L)->next, *pre = *L;
    while (node)
    {
        if (node->data >= min && node->data<=max)
        {
            pre->next = node->next;
            free(node);
            node = pre->next;
        }
        else
        {
            pre = node;
            node = node->next;
        }
        
    }
    
}

// 找出两个链表的公共结点
LinkList FindCommonNode(LinkList *L1,LinkList *L2){
    LNode *node1 = (*L1)->next,*node2 = (*L2)->next;
    LinkList L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *node = L;
    while (node1)
    {
        node2 = (*L2)->next;
        while (node2)
        {
            if (node1->data == node2->data)
            {
                LNode* tmp = (LNode*)malloc(sizeof(LNode));
                tmp->data = node1->data;
                node->next = tmp;
                node = tmp;
            }
            node2 = node2->next;
        }
        node1 = node1->next;
    }
    node->next = NULL;
    return L;
    
}

// 按递增次序输出单链表的元素，并释放结点所占空间
void PrintIncrease(LinkList *L){
    LNode *node = (*L)->next, *pre = *L;
    LNode *minpre = pre,*min;
    while (node)
    {
        pre = *L;
        minpre = pre;
        min = node;
        while (node)
        {
            if(node->data < min->data){
                min=node;
                minpre = pre;
            }
            pre = node ;
            node = node->next;
        }
        printf("%d  ",min->data);
        minpre->next = min->next;
        free(min);
        node = (*L)->next;
        
    }
    free(node);
    printf("\n");
    
}

// 单链表拆分成A，B，保持其相对顺序不变
void SplitList(LinkList *L){
    LNode *node = (*L)->next;
    LinkList L1,L2;
    InitList(&L1);
    InitList(&L2);
    LNode *node1 = (L1),*node2 = (L2);
    int i=0;
    while (node)
    {
        if (i % 2 == 0)
        {
            node1->next = node;
            node1 = node;
        }else 
        {
            node2->next = node;
            node2 = node;
        }
        node = node->next;
        i++;
    }
    node1->next = NULL;
    node2->next = NULL;
    printf("----以下是L1的元素-----\n");
    PrintList(&L1);
    printf("----L1输出完成---\n");
    printf("\n");
    printf("----以下是L2的元素-----\n");
    PrintList(&L2);
    printf("----L2输出完成---\n");
    printf("\n");
}

// 将带头结点的单链表拆分成两个线性表，使得A = {a1,a2,...an},B = {bn,...b2,b1}
void SplitList02(LinkList *L){
    LNode *node = (*L)->next;
    int i = 1;
    LinkList La;
    LinkList Lb;
    InitList(&La);
    InitList(&Lb);
    LNode *rA = La,*rB = Lb;
    rB->next = NULL;
    while (node)
    {
        LNode *tmp = node->next;
        if (i % 2 == 1)
        {
            rA->next = node;
            rA = node;
            
        }else
        {
            node->next = rB->next;
            rB->next = node;
        }
        node = tmp;
        i++;
    }
    rA->next = NULL;
    printf("----以下是La的元素-----\n");
    PrintList(&La);
    printf("----La输出完成---\n");
    printf("\n");
    printf("----以下是Lb的元素-----\n");
    PrintList(&Lb);
    printf("----Lb输出完成---\n");
    printf("\n");
}

// 删除单链表中重复元素
void DeleteRepeatingElems(LinkList *L){
    LNode *node = (*L)->next;


    // 如果单链表无序
    /*while (node)
    {
        LNode *tmpper = node;
        LNode *tmp = node->next;
        while (tmp)
        {
            if (tmp->data == node->data)
            {
                tmpper->next = tmp->next;
                free(tmp);
                tmp = tmpper->next;
            }else
            {
                tmpper = tmp;
                tmp = tmp->next;
            }              
        }
        node = node->next;
    }*/


    // 如果单链表有序
    while (node->next)
    {
        LNode *p = node->next;
        if (node->data == p->data)
        {
            node->next = p->next;
            free(p);
        }else
        {
            node = node->next;
        }
    }
    
}

// 合并两个递增单链表，使得合并后为递减单链表
void MergeList(LinkList *L1,LinkList *L2){
    LNode *rA = (*L1)->next;
    LNode *rB = (*L2)->next;
    (*L1)->next = NULL;

    while (rA)
    {
        if (rB == NULL)
        {
            break;
        }
        if (rA->data < rB->data)
        {
            LNode *tmp = rA->next;
            rA->next = (*L1)->next;
            (*L1)->next = rA;
            rA = tmp;
        }else
        {
            LNode *tmp = rB->next;
            rB->next = (*L1)->next;
            (*L1)->next = rB;
            rB = tmp;
        }
    }
    if (rA)
    {
        rB = rA;
    }
    
    while (rB)
    {
        LNode *tmp = rB->next;
        rB->next = (*L1)->next;
        (*L1)->next = rB;
        rB = tmp;
    }
    free((*L2));
    
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
        printf("list[%d]==%d   ",++i,node->data);
        node = node->next;
    }
    printf("\n");
}