#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"../include/LinklistDemo.h"
int main(){
    LinkList L;
    InitList(&L);
    // List_TailInsert(&L);
    // PrintList(&L);
    LinkList L1,L2;
    InitList(&L1);
    InitList(&L2);
    List_TailInsert(&L1);
    List_TailInsert(&L2);
    PrintList(&L1);
    PrintList(&L2);
    // DeleteNoHeadList(&L,1);
    // DeleteWithHeadList(&L,1);
    // R_Ignore_Head(&L);
    // ReserseList(&L);
    // DeleteMinElemOfList(&L);
    // SortLinkedList(&L);
    // DeleteRangeList(&L,1,3);
    // L = FindCommonNode(&L1,&L2);
    // PrintIncrease(&L);
    // SplitList02(&L);
    // DeleteRepeatingElems(&L);
    // printf("\n");
    MergeList(&L1,&L2);
    PrintList(&L1);
    return 0;
}