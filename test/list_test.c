#include <stdlib.h>
#include <stdio.h>
#include"../include/list.h"
int main(){
    List list;
    InitList(&list);
    int n;
    printf("请输入元素的个数n= ：");
    scanf("%d",&n);
    printf("\n");       
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&list->data[i]);
    }
    PrintList(&list);
    printf("线性表list的长度length= ：",LengthOfList(&list));
    printf("\n");
    printf("线性表list是否为空 ：",ListIsEmpty(&list));
    printf("\n");
    printf("线性表list是否已满 ：",ListIsFull(&list));
    printf("\n");
    printf("线性表list的第3个元素e= ：",FindElemOfList(&list,3));
    printf("\n");
    printf("在线性表list中的第3个位置插入元素8\n");
    InsertElemIntoList(&list,3,8);
    PrintList(&list);
    ElemType e;
    DeleteElemFromList(&list,3,&e);
    printf("删除线性表list的第3个元素,删除的元素e= %d: ",e);
    printf("\n");
    PrintList(&list);
    return 0;
}