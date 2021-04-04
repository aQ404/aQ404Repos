#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"../include/linklist.h"
int main(){
    LinkList L;
    InitList(&L);
    // List_HeadInsert(&L);
    List_TailInsert(&L);
    PrintList(&L);
    printf("单链表的第一个元素为list[%d] == %d\n",0,GetElem(&L,1)->data);
    printf("单链表的第二个元素为list[%d] == %d\n",1,GetElem(&L,2)->data);
    printf("单链表的第三个元素为list[%d] == %d\n",2,GetElem(&L,3)->data);
    printf("单链表的第四个元素为list[%d] == %d\n",3,GetElem(&L,4)->data);
    printf("单链表中元素1在为序j == %d\n",LocateElem(&L,1));
    printf("单链表中元素4在为序j == %d\n",LocateElem(&L,4));
    printf("单链表中元素5在为序j == %d\n",LocateElem(&L,5));
    printf("单链表的长度length == %d\n",LengthOfList(&L));
    
}