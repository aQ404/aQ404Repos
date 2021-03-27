#include <stdbool.h>
#include<stdio.h>
#include<stdlib.h>



#define MaxSize 10
#define ElemType int

typedef struct LNode
{
    ElemType data[MaxSize];
    ElemType length;   
}LNode;

typedef struct LNode* List;

// 初始化一个线性顺序表
void InitList(List *list);

// 判断线性表是否为空，若是则返回true，否则返回false
bool ListIsEmpty(List *list);

// 判断线性表是否已满，已满则返回true，否则返回false
bool ListIsFull(List *list);

// 根据指定位置的位序i,返回L中相应的元素e
ElemType FindElemOfList(List *list,int i);

// 在List的指定位序i前插入一个新元素e；成功返回true，失败返回flase
bool InsertElemIntoList(List *lsit,int i,ElemType e);

// 从List中删除指定位序i的元素；成功返回true，失败返回flase，并保存删除的元素
bool DeleteElemFromList(List *list,int i, ElemType *e);

// 返回线性表的长度length
int LengthOfList(List *list);

// 打印线性表的元素
void PrintList(List *list);




void InitList(List *list){
    LNode* node = *list;
    for (int i = 0; i < MaxSize; i++)
    {
        node->data[i]=0;
    }
    node->length=0;
    
}
// 判断线性表是否为空，若是则返回true，否则返回false
bool ListIsEmpty(List *list){
    LNode* node = *list;
    if (node->length==0){
        return true;
    }else{
        return false;
    }
}

// 判断线性表是否已满，已满则返回true，否则返回false
bool ListIsFull(List *list){
    LNode* node = *list;
    if (node->length==MaxSize)
    {
        return true;
    }else
    {
        return false;
    }
}

// 根据指定位置的位序i,返回L中相应的元素e
ElemType FindElemOfList(List *list,int i){
    LNode* node = *list;
    return node->data[i-1];
}

// 在List的指定位序i前插入一个新元素e；成功返回true，失败返回flase
bool InsertElemIntoList(List *lsit,int i,ElemType e){
    LNode* node = *lsit;
    if (node->length==MaxSize)
    {
        printf("顺序表已满，插入失败！！！");
        printf("\n");
        return false;
    }else
    {
        if (i<1||i>node->length+1)
        {
            printf("非法输入，程序终止！！！");
            exit(0);
        }else
        {
            for (int j = node->length; j >=i; j--)
            {
                node->data[j]=node->data[j-1];
            }
            node->data[i-1]=e;
            node->length++;
            printf("插入成功！！！");
            printf("\n");
            return true;
        }
    }
}

// 从List中删除指定位序i的元素；成功返回true，失败返回flase，并保存删除的元素
bool DeleteElemFromList(List *list,int i, ElemType *e){
    LNode* node = *list;
    if (node->length==0)
    {
        printf("顺序表中没有元素，删除失败！！！");
        printf("\n");
        return false;
    }else
    {
        if (i<1||i>node->length+1)
        {
            printf("非法输入，程序终止！！！");
            exit(0);
        }else{
            *e = node->data[i-1];
            for (int j = i; j < node->length; j++)
            {
                node->data[j-1]=node->data[j];
            }
            node->length--;
            printf("删除成功！！！");
            printf("\n");
            return true;
        }
    }
    
    
}

// 返回线性表的长度length
int LengthOfList(List *list){
    LNode *node = *list;
    return node->length;
}

// 打印顺序表的元素
void PrintList(List* list){
    LNode *node = *list;
    for (int i = 0; i < node->length; i++)
    {
        printf("lsit[%d]=%d    ", i,node->data[i]);
    }
    printf("\n");
}
int main(){
    List list;
    InitList(&list);
    int n;
    printf("请输入元素的个数");
    scanf("%d",&n);
    list->length=n;   
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&list->data[i]);
    }
    PrintList(&list);
    printf("线性表list的长度length= %d：",LengthOfList(&list));
    printf("\n");
    printf("线性表list是否为空 ：%d",ListIsEmpty(&list));
    printf("\n");
    printf("线性表list是否已满 ：%d",ListIsFull(&list));
    printf("\n");
    printf("线性表list的第3个元素e= %d：",FindElemOfList(&list,3));
    printf("\n");
    printf("在线性表list中的第3个位置插入元素8\n");
    InsertElemIntoList(&list,3,8);
    PrintList(&list);
    ElemType e;
    DeleteElemFromList(&list,3,&e);
    printf("删除线性表list的第3个元素,删除的元素e= %d: ",e);
    printf("\n");
    PrintList(&list);
    return 0;
}