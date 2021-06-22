#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"../include/stack.h"

int main(){
    Stack S; 
    CreateStack(&S);
    printf("%d\n",IsEmptyStack(&S));
    printf("%d\n",IsFullStack(&S));
    PushStack(&S,3);
    printf("%d\n",IsEmptyStack(&S));
    printf("%d\n",IsFullStack(&S));
    printf("弹出的栈顶元素为:%d\n",PopStack(&S));
    printf("%d\n",IsEmptyStack(&S));
    printf("%d\n",IsFullStack(&S));
}