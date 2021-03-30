#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include"../include/ListDemo1.h"

// 初始化一个线性顺序表
void InitList(List *list){
    LNode* node = *list;
    for (int i = 0; i < MaxSize; i++)
    {
        node->data[i]=0;
    }
    node->length=0;
    
}

//删除顺序表中最小元素
bool DeleteMinNums(List *list,ElemType *e){
    LNode* node = *list;
    
    if (node->length==0)
    {
        printf("List is empty ,delete fail!!!!");
        return false;
    }else
    { 
        ElemType e1 ;
        int j = FindMinNum(list,&e1);
        *e=node->data[j];
        node->data[j] = node->data[node->length-1];
        node->data[node->length-1]=0;
        node->length--;
        return true;
    }
}

// 找到顺序表中最小元素
ElemType FindMinNum(List *list , ElemType *e){
    LNode* node = *list;
    *e = node->data[0];
    int j=0;
    for (int i = 1; i < node->length; i++)
    {
        if (*e > node->data[i])
        {
            *e = node->data[i];
            j=i;
        }
    }
    return j;//返回最小值的下标
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