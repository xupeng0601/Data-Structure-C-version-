//
// Created by xupeng on 2021/3/1.
//


#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

//���Ա��˳��洢--��̬����
#define MaxSize 50
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int length;             //��ǰ˳������󳤶�
}SqList;

/**
 * ��ʼ�����Ա�
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
 * ���
 * @param L
 * @return
 */
int Length(SqList L){
    return L.length;
}

/**
 * ��ֵ����Ԫ�ص�λ�ã����ص�һ�γ��ֵ�λ��
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
 * ��λ���ұ���Ԫ��
 * @param L
 * @param idx
 * @return
 */
ElemType GetElem(SqList L,int idx){
    if(idx < 1 ||idx > L.length-1){
        printf("�������Ϸ�");
        return NULL;
    }
    return L.data[idx -1];
}

/**
 * �ڱ��е�i��λ�ò���Ԫ��x
 * @param L
 * @param idx
 * @param x
 * @return
 */
bool Insert(SqList *L,int idx,ElemType x){
    if(idx < 1 || idx > L->length+1){
        printf("����λ�ò��Ϸ�");
        return false;
    }
    if (L->length >= MaxSize){
        printf("����");
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
 * ɾ�����е�i��λ�õ�Ԫ�أ����������Ԫ��
 * @param L
 * @param idx
 * @return
 */
int Delete(SqList *L,int idx){
    if (idx < 1 || idx > L->length) {
        printf("λ�ò��Ϸ�");
        return false;
    }
    if (L == NULL) {
        printf("���");
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
 * �����������Ԫ��ֵ
 * @param L
 */
void PrintList(SqList L){
    for (int i = 0; i < L.length; ++i) {
        printf("%d\n",L.data[i]);
    }
}

/**
 * �жϱ��
 * @param L
 * @return
 */
bool Empty(SqList L){
     return L.length == 0;
}



/**
 * �������Ա�
 * @param L
 */
void DestroyList(SqList *L) {
    free(L);
    L->length = 0;
}

int main(){

    SqList L;
    //��ʼ��
    InitList(&L);
    //����
    Insert(&L,1,2);
    Insert(&L,2,4);
    Insert(&L,3,5);
    Insert(&L,4,8);
    Insert(&L,5,3);
    //����
    PrintList(L);
    //ɾ��
    Delete(&L,3);
    printf("\n");
    PrintList(L);
    //��λ����
    ElemType x = GetElem(L,3);
    printf("\nx=%d\n",x);
    //��ֵ��λ
    int idx = LocateElem(L,3);
    printf("\nidx=%d\n",idx);
    //����
    DestroyList(&L);
    PrintList(L);
    printf("L.length = %d\n",L.length);
    //���³�ʼ��
    printf("\n");
    InitList(&L);
    //����
    Insert(&L,1,2);
    Insert(&L,2,4);
    PrintList(L);

}