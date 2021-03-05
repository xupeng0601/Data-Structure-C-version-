//插入排序
// Created by xupeng on 2021/3/4.
//

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>


typedef int ElemType;
ElemType a[] = {12,34,23,33,10,5,64,32};
int Length = sizeof(a)/sizeof(ElemType);

/*
 *直接插入排序
 */
void InsertSort(ElemType a[],int n){
    int i,j,temp;
    for(i = 1; i<n;i++)
        if(a[i]<a[i-1]) {
            temp = a[i];
            for (j = i - 1; temp < a[j]; --j)
                a[j + 1] = a[j];
            a[j+1] = temp;
        }
}

/**
 * 折半插入排序
 * @param a
 * @param n
 */

void BinaryInsertSort(ElemType a[], int n){
    int i,j,temp,low,high,mid;
    for (i = 1; i < n; ++i) {
        if(a[i]<a[i-1]){
            low = 0;
            high = i-1;
            temp = a[i];
            while (low <= high){
                mid = (low+high)/2;
                if (a[mid]>temp){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }
            for ( j = i-1; j >=high; j--) {
                a[j+1] = a[j];
            }
            a[high+1] = temp;
        }
    }
}

/**
 * 希尔排序
 * @param a
 * @param n
 */
void ShellSort(ElemType a[],int n){
    int i,j,temp,dk;
    for (dk = (n-1)/2; dk >=1 ; dk = dk/2) {
        for (i = dk; i < n; ++i) {
            if (a[i]<a[i-dk]){
                temp = a[i];
                for (j = i-dk; j>0&&temp<a[j]; j-=dk) {
                    a[j+dk] =a[j];
                }
                a[j+dk] = temp;
            }
        }
    }
}

void Print(ElemType a[],int n){
    for (int i = 0; i < n; ++i) {
        printf("%d\n",a[i]);
    }
    printf("\n");
}


//测试
int main(){
    Print(a,sizeof(a)/sizeof(ElemType));
//    InsertSort(a,sizeof(a)/sizeof(ElemType));
//    BinaryInsertSort(a,Length);
//    Print(a,Length);
    ShellSort(a,Length);
    Print(a,Length);
}