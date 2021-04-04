#include<stdio.h>
#include<stdlib.h>
#include"../include/list.h"

// 初始化一个线性顺序表
void InitList(List *list){
    LNode* node = *list;
    for (int i = 0; i < MaxSize; i++)
    {
        node->data[i]=0;
    }
    node->length=0;
}
// 判断线性表是否为空，若是则返回true，否则返回false
bool ListIsEmpty(List *list){
    LNode* node = *list;
    if (node->length==0){
        return true;
    }else{
        return false;
    }
}

// 判断线性表是否已满，已满则返回true，否则返回false
bool ListIsFull(List *list){
    LNode* node = *list;
    if (node->length==MaxSize)
    {
        return true;
    }else
    {
        return false;
    }
}

// 根据指定位置的位序i,返回L中相应的元素e
ElemType FindElemOfList(List *list,int i){
    LNode* node = *list;
    return node->data[i-1];
}

// 在List的指定位序i前插入一个新元素e；成功返回true，失败返回flase
bool InsertElemIntoList(List *lsit,int i,ElemType e){
    LNode* node = *lsit;
    if (node->length==MaxSize)
    {
        printf("list is full , Insert fail!!!!!");
        printf("\n");
        return false;
    }else
    {
        if (i<1||i>node->length+1)
        {
            printf("Illegal input, program termination!!!");
            exit(0);
        }else
        {
            for (int j = node->length; j >=i; j--)
            {
                node->data[j]=node->data[j-1];
            }
            node->data[i-1]=e;
            node->length++;
            printf("Insert success!!!!");
            printf("\n");
            return true;
        }
    }
}

// 从List中删除指定位序i的元素；成功返回true，失败返回flase，并保存删除的元素
bool DeleteElemFromList(List *list,int i, ElemType *e){
    LNode* node = *list;
    if (node->length==0)
    {
        printf("list id empty , delete fail!!!!!");
        printf("\n");
        return false;
    }else
    {
        if (i<1||i>node->length+1)
        {
            printf("Illegal input, program termination!!!");
            exit(0);
        }else{
            *e = node->data[i-1];
            for (int j = i; j < node->length; j++)
            {
                node->data[j-1]=node->data[j];
            }
            node->length--;
            printf("delete success!!!!");
            printf("\n");
            return true;
        }
    }
    
    
}

// 返回线性表的长度length
int LengthOfList(List *list){
    LNode *node = *list;
    return node->length;
}

// 打印顺序表的元素
void PrintList(List* list){
    LNode *node = *list;
    for (int i = 0; i < node->length; i++)
    {
        printf("lsit[%d]=%d    ", i,node->data[i]);
    }
    printf("\n");
}