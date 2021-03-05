//线性表  链式储存 单链表 --不带头结点
// Created by xupeng on 2021/3/1.
//


#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>


typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;


/**
 * 初始化--不带头结点
 */
bool InitList(LinkList L){
    L = NULL;  //空表，没有任何节点
    return true;
}
/**
 * 在给定节点之前插入元素
 */
bool InsertPriorNode(LNode *p,ElemType x){
    if(p==NULL){
        return false;
    }
    LNode *s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL) {
        printf("内存不足");
        return false;
    }
    s->next = p->next;      //在p节点之后插入s,p的值赋给s,x赋给p
    p->next =s;
    s->data = p->data
    p->data = x;
    return true;
}

/**
 * 在给定节点之后插入元素
 */
bool InsertNextNode(LNode *p,ElemType x){
    LNode *s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL) {
        printf("内存不足");
        return false;
    }
    s->data = x;
    s->next = p->next;
    p->next = s;
    return true;
}

/**
 * 在位序为i的位置插入x
 */
bool Insert(LinkList L,int idx,ElemType x){
    if (idx < 1){
        printf("参数不合法");
        return false;
    }
    LNode *s =(LNode*)malloc(sizeof(LNode));
    if(i==1){
        s->data = x;
        s->next = L;
        L = s;
        return true;
    }
    int i = 1;
    LNode *p;                //指向当前节点指针
    while (p!=NULL && i++ < idx){       //找到位序为i的前一个节点
        p = L->next;
    }
    if(p == NULL){
        printf("i值过大，不合法");
        return false;
    }
    //在指定节点后插入
    InsertNextNode(p,x);
    return true;
}

/**
 * 判空
 */
bool Empty(LinkList L){
    return L == NULL;
}

