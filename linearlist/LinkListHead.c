//���Ա� ��ʽ�洢  ������  ��ͷ���
// Created by xupeng on 2021/3/1.
//

//���Ա�  ��ʽ���� ������ --����ͷ���
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

LinkList L = NULL;   //ȫ������


/**
 * ���
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
 * ͷ�巨����������
 */
bool  List_HeadInsert(){
    L = (LinkList)malloc(sizeof(LNode));
    if (L == NULL) {
        printf("�ռ䲻��");
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
 * β�巨����������
 */
bool List_TailInsert(){
    L = (LinkList)malloc(sizeof(LNode));
    if (L == NULL) {
        printf("�ռ䲻��");
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
 * ��ʼ��--��ͷ���
 */
bool InitList(){
    L = (LinkList)malloc(sizeof(LNode)); //��ʼ��ͷ���
    if (L == NULL) {
        printf("�ڴ治�㣬����ʧ��");
        return false;
    }
    L->next = NULL;  //�ձ�û���κνڵ�
    return true;
}

/**
 * ��λ����
 */
LNode* GetElem(int i){
    if(i < 1 || i > Length()){
        printf("�������Ϸ�");
        return NULL;
    }
    int j = 0;
    LNode *p = L;
    while (++j <= i){
        p=p->next;
    }
    if(p==NULL){
        printf("�������Ϸ�");
        return NULL;
    }
    return p;
}

/**
 * ��ֵ����
 */
LNode* LocateElem(LinkList L,ElemType e){
    if (L->next == NULL){
        printf("���");
        return NULL;
    }
    LNode *p = L->next;
    while (p->data != e && p!=NULL) {
        p = p->next;
    }
    return p;
}

/**
 * �ڸ����ڵ�֮ǰ����Ԫ��
 */
bool InsertPriorNode(LNode *p,ElemType x){
    if(p==NULL){
        printf("�������Ϸ�");
        return false;
    }
    LNode *s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL) {
        printf("�ڴ治��");
        return false;
    }
    s->next = p->next;      //��p�ڵ�֮�����s,p��ֵ����s,x����p
    p->next =s;
    s->data = p->data;
    p->data = x;
    return true;
}

/**
 * �ڸ����ڵ�֮�����Ԫ��
 */
bool InsertNextNode(LNode *p,ElemType x){
    LNode *s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL) {
        printf("�ڴ治��");
        return false;
    }
    s->data = x;
    s->next = p->next;
    p->next = s;
    return true;
}



/**
 * ��λ��Ϊi��λ�ò���x,λ����ڵ���i��Ԫ�غ���һλ��������+1
 * λ���ȡֵ��ΧΪ1������ĳ���+1
 */
bool InsertByIdx(int idx,ElemType x){
    if (idx < 1 || idx > Length()){
        printf("�������Ϸ�");
        return false;
    }
    int i = 0;
    LNode *p = L->next;                //ָ��ǰ�ڵ�ָ��
    while ( ++i <= idx){       //�ҵ�λ��Ϊi��ǰһ���ڵ�
          p = L->next;
    }
    InsertPriorNode(p,x);
    return true;
}


/**
 * ��ӡ
 */
void Print(){
    if(L->next==NULL){
        printf("���");
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
 * ɾ��λ��Ϊi�Ľڵ㣬����������
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
 * �п�
 */
bool Empty(LinkList L){
    return (L->next) == NULL;
}

int main(){
    //β�巨����������
    List_TailInsert();
    printf("length=%d\n",Length());
    Print();

 /*   //ͷ�巨����������
    List_HeadInsert();
    Print();*/
   //����Ԫ��
   printf("\n");
   InsertByIdx(1,20);
   InsertByIdx(2,10);
   InsertPriorNode(L->next,50);
   InsertNextNode(L->next,40);
   Print();

   //����
   printf("\n");
   printf("GetElem:%d\n",GetElem(10)->data);
   Print();

   //ɾ��
   printf("\n");
   ElemType res =  DeleteByIdx(2);
   printf("res=%d\n",res);
   Print();

}
