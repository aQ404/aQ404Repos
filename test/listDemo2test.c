#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"../include/ListDemo2.h"

int main(){
    
    // List list2;
    List list1;
    InitList(&list1);
    // InitList(&list2);
    int n,m;
    printf("please input numbers of n ");
    scanf("%d",&n);      
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&list1->data[i]);
    }
    list1->length=n;
    // for (int i = 0; i < m; i++)
    // {
    //     scanf("%d",&list2->data[i]);
    // }
    // list2->length=m;
    // InveredList(&list1,0,list1->length-1,list1->length);
    PrintList(&list1);
    InsertintoList(&list1,5);
    PrintList(&list1);
    // PrintList(&list2);
    // List list3;
    // InitList(&list3);
    // list3 = MergeList(&list1,&list2);
    // PrintList(&list3);
    // PrintList(&list2);
    // DeleteElemFromList(&list,2);
    // PrintList(&list);
    // DeleteRepeatElemFromList(&list);
    // PrintList(&list);
    return 0;
    
}