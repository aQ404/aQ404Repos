#include<stdio.h>

void Increment(int a){
    a = a+1;
    
}



int main(){
    
    int a=1025;
    int *p;
    // int **q = &p;
    // int ***r = &q;
    // p=&a;
    // Increment(a);
    // printf("%d\n",*p);
    // printf("%d\n",*q);
    // printf("%d\n",*(*q));
    // printf("%d\n",**r);
    // printf("%d\n",***r);
    // printf("size of integer is %d bytes\n",sizeof(int));
    // printf("Address = %d, value = %d\n",p,*p);
    // char *p0;
    // p0 = (char*)p;
    // printf("size of integer is %d bytes\n",sizeof(int));
    // printf("Address = %d, value = %d\n",p0,*p0);
    int nums[5];
    for(int i=0 ; i< 5 ; i++){
        scanf("%d",&nums[i]);
    }
    p=&nums[0];
    for(int i=0 ; i < 5;i++){
        printf("nums[%d] = %d\n",i,*(p+i));
    }
    return 0;
}