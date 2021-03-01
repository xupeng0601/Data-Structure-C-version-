//
// Created by xupeng on 2021/3/1.
//

//单链表的定义
typedef int Element;
typedef struct LNode{
    Element data;
    struct LNode *next;
}LNode,*LinkList;

bool InitList(LinkList L);
void test(int **x);

int main(){
//    LinkList L;
//    InitList(L);
    int x =100;
    int *p = x;
    printf("传入之前x=%d\n",x);
    printf("传入之前p=%d\n",p);

    test(*p);
    printf("传入之后x=%d\n",x);
}

void test(int **x){
    x= 2020;
    printf("test程序里面x=%d\n",x);
}

//初始化一个空的单链表
bool InitList(LinkList L){
    L = NULL; //空表，占时没有任何节点
    return true;
}