#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"../include/linklist.h"
int main(){
    LinkList L;
    L = (LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    List_HeadInsert(&L);
    PrintList(&L);

}