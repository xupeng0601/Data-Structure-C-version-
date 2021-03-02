//线性表 链式存储  单链表  带头结点
// Created by xupeng on 2021/3/1.
//

//线性表  链式储存 单链表 --不带头结点
// Created by xupeng on 2021/3/1.
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


/**
 * 求表长
 */
int Length(){
    LNode *p = L->next;
    int len = 0;
    while(p!=NULL){
        len++;
        p=p->next;
    }
    return len;
}
/**
 * 头插法建立单链表
 */
bool  List_HeadInsert(){
    L = (LinkList)malloc(sizeof(LNode));
    if (L == NULL) {
        printf("空间不足");
        return false;
    }
    int x = 1; LNode *s;
    L->next = NULL;
    while (x <= 10){
        s= (LNode*)malloc(sizeof(LNode));
        s->data = x++;
        s->next = L->next;
        L->next = s;
    }
    return true;
}

/**
 * 尾插法建立单链表
 */
bool List_TailInsert(){
    L = (LinkList)malloc(sizeof(LNode));
    if (L == NULL) {
        printf("空间不足");
        return false;
    }
    int x = 1;
    LNode *s, *r = L;
    while(x<=10){
        s=(LNode*)malloc(sizeof(LNode));
        s->data = x++;
        r->next = s;
        r = s;
    }
    r->next =NULL;
    return true;
}

/**
 * 初始化--带头结点
 */
bool InitList(){
    L = (LinkList)malloc(sizeof(LNode)); //初始化头结点
    if (L == NULL) {
        printf("内存不足，分配失败");
        return false;
    }
    L->next = NULL;  //空表，没有任何节点
    return true;
}

/**
 * 按位查找
 */
LNode* GetElem(int i){
    if(i < 1 || i > Length()){
        printf("参数不合法");
        return NULL;
    }
    int j = 0;
    LNode *p = L;
    while (++j <= i){
        p=p->next;
    }
    if(p==NULL){
        printf("参数不合法");
        return NULL;
    }
    return p;
}

/**
 * 按值查找
 */
LNode* LocateElem(LinkList L,ElemType e){
    if (L->next == NULL){
        printf("表空");
        return NULL;
    }
    LNode *p = L->next;
    while (p->data != e && p!=NULL) {
        p = p->next;
    }
    return p;
}

/**
 * 在给定节点之前插入元素
 */
bool InsertPriorNode(LNode *p,ElemType x){
    if(p==NULL){
        printf("参数不合法");
        return false;
    }
    LNode *s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL) {
        printf("内存不足");
        return false;
    }
    s->next = p->next;      //在p节点之后插入s,p的值赋给s,x赋给p
    p->next =s;
    s->data = p->data;
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
 * 在位序为i的位置插入x,位序大于等于i的元素后移一位，链表长度+1
 * 位序的取值范围为1到链表的长度+1
 */
bool InsertByIdx(int idx,ElemType x){
    if (idx < 1 || idx > Length()){
        printf("参数不合法");
        return false;
    }
    int i = 0;
    LNode *p = L->next;                //指向当前节点指针
    while ( ++i <= idx){       //找到位序为i的前一个节点
          p = L->next;
    }
    InsertPriorNode(p,x);
    return true;
}


/**
 * 打印
 */
void Print(){
    if(L->next==NULL){
        printf("表空");
        return;
    }
    LNode *p = L->next;
    while (p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
    return;
}

/**
 * 删除位序为i的节点，并返回数据
 * @param idx
 * @return
 */
ElemType DeleteByIdx(int idx){
    LNode *p = GetElem(idx-1);
    LNode *q = p->next;
    ElemType result = p->next->data;
    p->next = q->next;
    free(q);
    return result;
}

/**
 * 判空
 */
bool Empty(LinkList L){
    return (L->next) == NULL;
}

int main(){
    //尾插法建立单链表
    List_TailInsert();
    printf("length=%d\n",Length());
    Print();

 /*   //头插法建立单链表
    List_HeadInsert();
    Print();*/
   //插入元素
   printf("\n");
   InsertByIdx(1,20);
   InsertByIdx(2,10);
   InsertPriorNode(L->next,50);
   InsertNextNode(L->next,40);
   Print();

   //查找
   printf("\n");
   printf("GetElem:%d\n",GetElem(10)->data);
   Print();

   //删除
   printf("\n");
   ElemType res =  DeleteByIdx(2);
   printf("res=%d\n",res);
   Print();

}
