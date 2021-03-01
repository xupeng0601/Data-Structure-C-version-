//
// Created by xupeng on 2021/3/1.
//


#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

//线性表的顺序存储--静态分配
#define MaxSize 50
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int length;             //当前顺序表的最大长度
}SqList;

/**
 * 初始化线性表
 * @param L
 * @return
 */
bool InitList(SqList *L){
    for (int i = 0; i < MaxSize ; ++i) {
        L->data[i] = 0;
    }
    L->length = 0;
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
    if (L->length >= MaxSize){
        printf("表满");
        return false;
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