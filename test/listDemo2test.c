#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"../include/ListDemo2.h"

int main(){
    List list;
    InitList(&list);
    int n;
    printf("please input numbers of n == ");
    scanf("%d",&n);      
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&list->data[i]);
    }
    list->length=n;
    InveredList(&list);
    PrintList(&list);
    return 0;
    
}