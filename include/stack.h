#ifndef STACK_H
#define STACK_H 
#include <stdbool.h>
#include <stdio.h>

#define MaxSize 10
#define ElemType int

typedef struct SNode{
    ElemType *data;
    ElemType top;
}Stack;

//生成空栈
bool CreateStack(Stack* S);

//判断栈满
bool IsFullStack(Stack* S);

// 判断栈是否为空
bool IsEmptyStack(Stack* S);

// 将元素e压入栈
bool PushStack(Stack* S,ElemType e);

// 将栈顶元素弹出，即删除并返回栈顶元素
ElemType PopStack(Stack* S);

#endif