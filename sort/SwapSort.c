//交换排序
// Created by xupeng on 2021/3/4.
//

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>


typedef int ElemType;
ElemType A[]= {12,24,6,8,4,2,10};
int Length = sizeof (A)/sizeof (ElemType);

void Print(ElemType a[],int n){
    for (int i = 0; i < n; ++i) {
        printf("%d\n",a[i]);
    }
    printf("\n");
}

void BubbleSort(ElemType a[],int n){
    bool flag;
    int i,j,temp;
    for (i = 0;  i<n-1 ; i++) {
        flag = false;
        for (j = 0; j<n-i-1; j++) {
            if(a[j]>a[j+1]){
                flag = true;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        if(!flag){
            return;
        }
    }
}
int Partition(ElemType a[],int low,int high){
    ElemType pivot = A[low];
    while (low <= high){
        while (low<high && a[high] >= pivot){
            --high;
            a[low] = a[high];
        }
        while(low<high && a[low] <= pivot){
            ++low;
            a[high] = a[low];
        }
    }
}

int main(){
    Print(A,Length);
    BubbleSort(A,Length);
    Print(A,Length);
}

