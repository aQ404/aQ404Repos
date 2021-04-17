#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"../include/LinklistDemo.h"
int main(){
    LinkList L;
    InitList(&L);
    List_TailInsert(&L);
    PrintList(&L);
    // DeleteNoHeadList(&L,1);
    // DeleteWithHeadList(&L,1);
    // R_Ignore_Head(&L);
    // ReserseList(&L);
    DeleteMinElemOfList(&L);
    // printf("\n");
    PrintList(&L);
    return 0;
}