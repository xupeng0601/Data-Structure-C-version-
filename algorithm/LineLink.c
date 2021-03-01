//
// Created by xupeng on 2021/2/26.
//


#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>



typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode* next;
}LNode,*LinkLine;

void initLine(LinkLine L);
void createLine(LinkLine L);

int main(){

    LinkLine  L;
    initLine(L);
    createLine(L);
    printf("111\n");
    while (L!= NULL){
        printf("data:%d\n",L->data);
        L=L->next;
    }
    return 0;
}

void initLine(LinkLine L){
    L = NULL;
    printf("不带头结点的线性链表初始化成功\n");
}

void createLine(LinkLine L){
    LNode *S;ElemType x = 1;
    L = (LinkLine)malloc((sizeof(LinkLine)));
    while (x++<=10){
        S=(LNode*)malloc(sizeof (LNode));
        S->data =x;
        S->next = NULL;
        L->next =S;
    }
}

