#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"../include/LinklistDemo.h"
int main(){
    LinkList L;
    InitList(&L);
    List_TailInsert(&L);
    PrintList(&L);
    PrintList(&L);
    DeleteNoHeadList(L,1);
    PrintList(&L);
    return 0;
}