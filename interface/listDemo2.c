#include<stdbool.h>
#include<stdio.h>
#include "../include/listDemo2.h"

// 初始化一个线性顺序表
void InitList(List *list){
    LNode* node = *list;
    for (int i = 0; i < MaxSize; i++)
    {
        node->data[i]=0;
    }
    node->length=0;
    
}

//将顺序表中元素逆置
void InveredList(List *list){
    LNode *node = *list;
    ElemType temp;
    for (int i = 0; i < (node->length/2); i++)
    {
        temp = node->data[node->length-1-i];
        node->data[node->length-1-i]=node->data[0+i];
        node->data[0+i] = temp;
    }
    printf("node->length/2 == %d\n",node->length/2);
    
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