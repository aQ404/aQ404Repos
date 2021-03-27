#include <stdlib.h>
#include <stdio.h>
#include"../include/list.h"
int main(){
    List list;
    InitList(&list);
    int n;
    printf("please input numbers of n = :");
    scanf("%d",&n);      
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&list->data[i]);
    }
    list->length=n;
    PrintList(&list);
    printf("The length of list == %d",LengthOfList(&list));
    printf("\n");
    printf("Is list empty ?  :%d",ListIsEmpty(&list));
    printf("\n");
    printf("Is list full ?  :%d",ListIsFull(&list));
    printf("\n");
    printf("The third elem of list e == %d",FindElemOfList(&list,3));
    printf("\n");
    printf("Insert the elem 8 into list of the Third \n");
    InsertElemIntoList(&list,3,8);
    PrintList(&list);
    ElemType e;
    DeleteElemFromList(&list,3,&e);
    printf("Delete the ith elem of lsit and e == %d ",e);
    printf("\n");
    PrintList(&list);
    return 0;
}