//顺序表的动态分配
// Created by xupeng on 2021/3/1.
//

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define InitSize 5  //初始化顺序表的最大容量
#define Size 5  //每次扩容的大小

typedef int ElemType;
typedef struct {
    ElemType *data;
    int length,MaxSize; //线性表的长度和当前最大容量
}SqList;

/**
 * 初始化
 */
bool InitList(SqList *L){
    L->data = (ElemType*)malloc(sizeof(ElemType)*InitSize);
    L->length =0;
    L->MaxSize = InitSize;
    return true;
}

/**
 * 动态扩容
 */
bool IncreaseSize(SqList *L,int size){
    if (size <= 0) {
        printf("size参数不和法");
        return false;
    }
    int *p = L->data;
    L->data = (ElemType *) malloc(sizeof(ElemType) *(L->MaxSize+size));
    for (int i = 0; i < L->length; ++i) {
        L->data[i] = p[i];
    }
    L->MaxSize+=size;
    free(p);
    return true;
}

/**
 * 求表长
 * @param L
 * @return
 */
int Length(SqList L){
    return L.length;
}

/**
 * 按值查找元素的位置，返回第一次出现的位置
 * @param L
 * @param x
 * @return
 */
int LocateElem(SqList L,ElemType x){
    for (int i = 0; i < L.length; ++i) {
        if(L.data[i] == x){
            return i+1;
        }
    }
    return -1;
}
/**
 * 按位查找表中元素
 * @param L
 * @param idx
 * @return
 */
ElemType GetElem(SqList L,int idx){
    if(idx < 1 ||idx > L.length-1){
        printf("参数不合法");
        return NULL;
    }
    return L.data[idx -1];
}

/**
 * 在表中第i个位置插入元素x
 * @param L
 * @param idx
 * @param x
 * @return
 */
bool Insert(SqList *L,int idx,ElemType x){
    if(idx < 1 || idx > L->length+1){
        printf("插入位置不合法");
        return false;
    }
    if (L->length >= L->MaxSize){
        IncreaseSize(L,Size);
    }
    for (int i = L->length-1; i >= idx -1 ; i--) {
        L->data[i] = L->data[i+1];
    }
    L->data[idx-1] = x;
    L->length++;
    return true;
}

/**
 * 删除表中第i个位置的元素，并返回这个元素
 * @param L
 * @param idx
 * @return
 */
int Delete(SqList *L,int idx){
    if (idx < 1 || idx > L->length) {
        printf("位置不合法");
        return false;
    }
    if (L == NULL) {
        printf("表空");
        return false;
    }
    ElemType result = L->data[idx -1];
    for (int i = idx -1; i < L->length -1; ++i) {
        L->data[i] = L->data[i+1];
    }
    L->length--;
    return result;
}

/**
 * 输出表中所有元素值
 * @param L
 */
void PrintList(SqList L){
    for (int i = 0; i < L.length; ++i) {
        printf("%d\n",L.data[i]);
    }
}

/**
 * 判断表空
 * @param L
 * @return
 */
bool Empty(SqList L){
    return L.length == 0;
}



/**
 * 销毁线性表
 * @param L
 */
void DestroyList(SqList *L) {
    free(L);
    L->length = 0;
}

int main(){

    SqList L;
    //初始化
    InitList(&L);
    //插入
    Insert(&L,1,2);
    Insert(&L,2,4);
    Insert(&L,3,5);
    Insert(&L,4,8);
    Insert(&L,5,3);
    Insert(&L,6,9);
    printf("L->length=%d and L->MaxSize=%d\n",L.length,L.MaxSize);
    //遍历
    PrintList(L);
    //删除
    Delete(&L,3);
    printf("\n");
    PrintList(L);
    //按位查找
    ElemType x = GetElem(L,3);
    printf("\nx=%d\n",x);
    //按值查位
    int idx = LocateElem(L,3);
    printf("\nidx=%d\n",idx);
    //销毁
    DestroyList(&L);
    PrintList(L);
    printf("L.length = %d\n",L.length);
    //重新初始化
    printf("\n");
    InitList(&L);
    //插入
    Insert(&L,1,2);
    Insert(&L,2,4);
    PrintList(L);

}

