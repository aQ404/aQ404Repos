#include<stdio.h>


#define MaxSize 10


typedef int ElemType;

typedef struct sqList
{
    /* data */
    ElemType data[MaxSize];
    ElemType length;
}SqList;


void InitList(SqList *L){
    int i;
    for (i=0; i < MaxSize; i++){
        L->data[i] = 0;
    }
    L->length =0;
}


void CreatList(SqList *L,int n){
    if (n<1||n>MaxSize+1){
        printf("非法输入！！");
    }else{
        for (int i = 0; i < n ; i++){
            scanf("%d",&L->data[i]);                                                                                                                                                                                                                                                                    
            L->length++;
        }
    }
}


int LengthOfList(SqList *L){
    return L->length;
}

int IsFullList(SqList *L){
    if (L->length==MaxSize){
        return 1;
    }else
        return 0;
}

int IsEmpty(SqList *L){
    if (L->length == 0){
        return 1;
    }else{
        return 0;
    }
    
}


ElemType GetElem(SqList *L,int i){
    if (i<1||i<L->length+1){
       printf("返回失败！！！\n");
       return NULL;
    }
    
    return L->data[i-1];
}

int LocateElem(SqList *L, ElemType e){
    for(int i = 0;i<L->length;i++){
        if (L->data[i]==e)
        {
            /* code */
            return i+1;
        }
    }
    return 0;
}


int ListInsert(SqList *L, int i, ElemType e){
    if(i<1||i>L->length+1){
        return 0;
    }
    if (L->length>=MaxSize){
        /* code */
        return 0;
    }
    for (int j = L->length; j>=i; j--){
        /* code */
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = e;
    L->length++;
    return 1;
    
}

void PrintList(SqList *L){
    for (int i = 0; i < L->length; i++)
    {
        /* code */
        printf("%d   ",L->data[i]);
    }
    printf("\n");
    
}
ElemType ListDetele(SqList *L,int k,ElemType *e1){
    if(k<1||k>L->length+1){
        return 0;
    }
    *e1=L->data[k-1];
    for (int j = k; j < L->length; j++){
        /* code */
        L->data[j-1] = L->data[j];
    }
    L->length--;
    return 1;
}


int main(){
    SqList L;
    InitList(&L);
    int n;
    printf("输入数据的个数n=:");
    printf("\n");
    scanf("%d",&n);
    CreatList(&L,n);
    PrintList(&L);
    printf("顺序表的长度length=%d\n",LengthOfList(&L));
    printf("请输入你想在那个位置i插入元素e:\n");
    int i,e;
    scanf("%d%d",&i,&e);
    ListInsert(&L,i,e);
    PrintList(&L);
    printf("请输入你想删除那个位置i的元素:\n");
    int k;
    scanf("%d",&k);
    ElemType e1;
    ListDetele(&L,k,&e1);
    PrintList(&L);
    printf("删除的元素是：%d\n",e1); 

    return 0;
}