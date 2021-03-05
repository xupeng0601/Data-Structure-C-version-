//线性表  链式存储  双链表 带头结点
// Created by xupeng on 2021/3/2.
//
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>


typedef int ElemType
typedef struct DNode{
    ElemType data;
    struct DNode *prior,*next;   //指向前继节点和后继节点
}DNode,*DLinkList;


DLinkList  L;  //全局链表

bool InitList(){
    L = (DLinkList)malloc(sizeof(DNode));
    if (L == NULL){
        printf("空间不足");
        return false;
    }
    L->next = NULL;
    L->prior = NULL;
    return true;

}