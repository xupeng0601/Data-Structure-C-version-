//
// Created by xupeng on 2021/2/20.
//头文件引入
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//定义线性表的最大长度
#define MaxSize 100
//定义线性表的类型
typedef int ElemType;

//顺序表结构
struct Line{
    ElemType data[MaxSize];
    ElemType length;
}SqList={{-2,-1,0,1,
          2,3,4,5,6,7}
          ,10
};
typedef struct Line *List;






//方法申明
bool ListInsert(List L,int i,ElemType x);
bool Del_Min(struct Line *L);
void Reverse(struct Line *L);
void Del_X(struct Line *L,int X);
void Del_QJ(struct Line *L,int s,int t);
void Del_QJ2(struct Line *L,int s,int t);
int findMissMin(int A[],int n);
int findMinNum(int A[],int n);

//全局变量
int idx;

int main(){
    //定义线性表二
    struct Line SxList = {{1,2,3,4,5,
            6},
             6
    };
    struct Line MergeList;
    //测试
//    Del_Min(&SqList);
//    Reverse(&SqList)
//    Del_X(&SqList,2);
//    Del_QJ(&SqList,2,6);
//    Del_QJ2(&SqList,2,6);
   /* for (int i = 0; i < SqList.length; ++i) {
        printf("%d\n",SqList.data[i]);
    }*/
//    printf("\nmin=%d\n", SqList.data[idx]);
//    printf("length = %d", SqList.length);

    int A[] = {3,4,3,4,3,4,3,4,3,2,-1};
    printf("length==%d\n", sizeof(A) / sizeof(int));
    int missMin = findMinNum(A,sizeof(A)/sizeof(int));
    printf("missMin = %d", missMin);
    return 0;
}

/**
 * 插入元素
 * @param L
 * @return
 */
bool ListInsert(List L, int i, ElemType x){
    if (i < 1 || i > L->length + 1) {
        printf("插入位置不合法");
        return false;
    }
    if (L->length >= MaxSize) {
        printf("表满");
        return false;
    }
    for (int j = L->length; j >= i; ++j) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i-1] = x;
    L->length++;
    return true;

}

bool Del_Min(struct Line *L){
    if (L->length == 0)
        return false;
    int min = 0;
    idx = -1;
    L->data[0] = min;
    for (int i = 1; i < L->length; ++i) {
        if (L->data[i] < min) {
            min = L->data[i];
            idx = i;
        }
    }
    L->data[idx] = min;
    return true;
}

void Reverse(struct Line *L){
    int temp=0;
    for (int i = 0; i < L->length/2; ++i) {
        temp =  L->data[i];
        L->data[i] = L->data[L->length -i-1];
        L->data[L->length - i-1] = temp;
    }
}
void Del_X(struct Line *L,int X){
    if (L->length == 0){
        printf("表空");
        return;
    }
    int k = 0 ; //记录线性表中等于k的个数
    for (int i = 0; i < L->length; ++i) {
        if(L->data[i] != X){
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->length = k;    //顺序表的长度等于K
}

void Del_QJ(struct Line *L,int s,int t){
    if (L->length == 0) {
        printf("表空");
        return;
    }
    if(s >= t){
        printf("s大于t");
        return;
    }
    int i = 0;
    int k = 0; //线性表中不在s-t之间的个数
    while (i<L->length){
        if (L->data[i] < s || L->data[i] > t) {
            L->data[k] = L->data[i];
            k++;

        }
        i++;
    }
    L->length = k;
}

void Del_QJ2(struct Line *L,int s,int t){
    int i,j;
    if(s>=t||L->length==0)
        return;
    for ( i=0; i<L->length&& L->data[i] < s; ++i);
    if (i>=L->length)
        return;
    for ( j=i; j<L->length&& L->data[j] <=t; ++j);
    for (;j<L->length;i++,j++) {
        L->data[i] = L->data[j];
    }
    L->length = i;
}

void MergeList(struct Line *L,struct Line *S,struct Line *M){
    int max =0;
    for (int i = 0; i < L->length + S->length; ++i) {
        if (L->data[i]>S->data[i])
            M->data[i] = S->data[i];
        else
            M->data[i] = L->data[i];
    }
}

/*
 * 基本设计思想：
 *
 * */
int findMissMin(int A[],int n){

    if (n == 0) {
        printf("空数组");
        return -1;
    }

    int i,c,count = 1;
    c = A[0];
    for ( i = 1; i < n; ++i) {
        if (A[i] == c){
            count++;
        }else{
            if(count > 0){
                count --;
            }else{
                c = A[i];
                count = 1;
            }
        }
    }

    if(count > 0){
        for ( i=count=0; i < n; ++i) {
            if(A[i] == c)
               count ++;
        }
        if(count > n/2){
            return c;
        }
    }
    return -1;
}

int findMinNum(int A[],int n){
    int i,*B;
    memset(B,0,sizeof(int)*n);
    for(i =0; i< n; i++){
        if(A[i]>0 && A[i]<=n){
            B[A[i]-1] = 1;
        }
    }
    for ( i = 0; i < n ; ++i) {
        if(B[i] == 0)
            break;
    }

    return i+1;
}

