#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"../include/ListDemo1.h"

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
    ElemType e;
    bool falg = DeleteMinNums(&list,&e);
    if (falg == true)
    {
        printf("Delete Success !!!\nthe number of delete is %d\ngti",e);
        PrintList(&list);
    }else
    {
        printf("Delete fail!!!!");
        exit(0);
    }

    return 0;
    
    

}