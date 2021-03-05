//  链表算法题练习
// Created by xupeng on 2021/3/2.
//

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>


typedef int ElemType;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

LinkList L = NULL;   //全局链表


void Get_Common(LinkList A,LinkList B,LinkList C){
    LNode *a = A->next;
    LNode *b = B->next;
    while (a!=NULL && B!=NULL){
        if(a->data == b->data);
    }
}