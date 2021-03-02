//
// Created by xupeng on 2021/2/22.
//

#include <malloc.h>
#include <stdio.h>

//单链表节点描述
typedef struct LNode{
     int data;
     struct LNode *next;
}LNode,*LinkList;

LinkList HeadInsert();
LinkList TailInsert();
LNode* GetElem(LinkList L,int i);

int main() {
    TailInsert();
    return 0;
}
/*
 *头插法建立单链表
 * */
LinkList HeadInsert(){
    LNode *s; int x = 1;
    LinkList L = (LinkList)malloc(sizeof(LinkList)); //创建链表
    L->next = NULL;                                  // 初始化空链表
    while (x++!=10){          //输入到10结束循环
//        scanf("%d",&x);
        s=(LNode*)malloc(sizeof(LNode));
        s->next = L->next;
        s->data = x;
        L->next = s;
    }
    return L;
}

/*
 * 尾插法建立单链表
 * */
LinkList TailInsert(){
    LinkList L = (LinkList)malloc(sizeof (LinkList));
    int x = 1;LNode *s,*r =L;
    L->next = NULL;
    while(x!=10){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x++;
        r->next =s;
        r = s;
    }
    r->next =NULL;
    LNode *p=L->next;
    while (p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
    return L;
}

/*
 * 按序号查找节点值
 * */
LNode* GetElem(LinkList L,int i){
    int count = 0;
    LNode* node = L->next;
    while(node->next != NULL){
       count++;
       if(count == i){
           return node;
       }
       node = node->next;
   }
   return NULL;
}
