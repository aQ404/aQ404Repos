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

// 从List中删除值为e的所有元素
bool DeleteElemFromList(List *list,ElemType e){
    LNode *node = *list;
    int j=0;
    if (node->length == 0)
    {
        printf("顺序表为空，删除失败！！！");
        return false;
    }else
    {
        for (int i = 0; i < node->length; i++)
        {
            if (node->data[i] != e)
            {
                 node->data[j]=node->data[i];
                 j++; 
            }
        }
        node->length = j++;
        return true;
    }
    
    

}

// 从有序list中删除所有重复元素
bool DeleteRepeatElemFromList(List *list){
    LNode *node = *list;
    int j=1;
    if (node->length == 0)
    {
        printf("顺序表为空，删除失败！！！");
        return false;
    }else
    {
        for (int i = 1; i < node->length; i++)
        {
            if (node->data[i] != node->data[i-1])
            {
                 node->data[j] = node->data[i];
                 j++; 
            }
        }
        node->length = j++;
        return true;
    }
    
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