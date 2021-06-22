#include<stdlib.h>
#include<stdio.h>
#include"../include/stack.h"

//生成空栈
bool CreateStack(Stack* S){
    S = (Stack*)malloc(sizeof(Stack));
    S->data = (ElemType*)malloc(sizeof(ElemType));
    S->top = -1;
}

//判断栈满
bool IsFullStack(Stack* S){
    return (S->top == MaxSize-1);
}

// 判断栈是否为空
bool IsEmptyStack(Stack* S){
    printf("S.top == %d\n",S->top);
    return (S->top == -1);
}

// 将元素e压入栈
bool PushStack(Stack* S,ElemType e){
    if (IsFullStack(S))
    {
        printf("堆栈已满！！！\n");
        return false;
    }
    S->data[++(S->top)] = e;
    return true;
}

// 将栈顶元素弹出，即删除并返回栈顶元素
ElemType PopStack(Stack* S){
    if (IsEmptyStack(S))
    {
        printf("堆栈为空！！！\n");
        return false;
    }
    return S->data[(S->top)--];
}