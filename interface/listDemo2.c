#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include "../include/listDemo2.h"

// 初始化一个线性顺序表
void InitList(List *list){
    LNode* node ;
    node = (LNode*)malloc(sizeof(LNode));
    *list = node;
    for (int i = 0; i < MaxSize; i++)
    {
        node->data[i] = 0;
    }
    node->length = 0;
    
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

// 合并两个有序顺序表，结果仍为有序顺序表
List MergeList(List *list1,List *list2){
    LNode *node1 = *list1,*node2 = *list2;
    LNode *node3;
    int i = 0,j = 0,k = 0;
    node3 = (LNode*)malloc(sizeof(LNode));
    node3->length = (node1->length+node2->length);
    for (;i < node1->length && j < node2->length;)
    {
        if (node1->data[i] > node2->data[j])
        {
           node3->data[k] = node2->data[j];
           printf("node3[j==%d] == %d\n",j,node2->data[j]);
           j++;
           k++;
        }
        else
        {
            node3->data[k] = node1->data[i];
            printf("node3[i==%d] == %d\n",i,node1->data[i]);
            i++;
            k++;
        }
        
    }
    
    if (i < node1->length - 1)
    {
        for (int p = i; p < node1->length; p++)
        {
            node3->data[k] = node1->data[p];
            printf("node3[p==%d] == %d\n",p,node1->data[p]);
            k++;
        }
        
    }
    if (j < node2->length - 1)
    {
        for (int p = j; p < node2->length; p++)
        {
            node3->data[k] = node2->data[p];
            printf("node3[p==%d] == %d\n",p,node2->data[p]);
            k++;
        }
    }
    return node3;
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