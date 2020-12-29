#include <stdlib.h>
#include <stdio.h>

#define bool char
#define true 1
#define false 0
#define ERROR 0

typedef int ElementType; 
typedef int Position;
struct SNode {
    ElementType *Data; /* �洢Ԫ�ص����� */
    Position Top;      /* ջ��ָ�� */
    int MaxSize;       /* ��ջ������� */
};
typedef struct SNode* Stack;


/*
Operation: ��ʼ��һ������ΪMaxSize��ջ 
*/
Stack CreateStack( int MaxSize )
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}

/*
Operation: �Ƿ�Ϊ��ջ 
*/ 
bool IsFull( Stack S )
{
    return (S->Top == S->MaxSize-1);
}

/*
Operation: ��ջ 
*/ 
bool Push( Stack S, ElementType X )
{
    if ( IsFull(S) ) {
        printf("��ջ��");
        return false;
    }
    else {
        S->Data[++(S->Top)] = X;
        return true;
    }
}

/*
Operation: �Ƿ�Ϊ��ջ 
*/ 
bool IsEmpty( Stack S )
{
    return (S->Top == -1);
}

/*
Operation: ��ջ 
*/ 
ElementType Pop( Stack S )
{
    if ( IsEmpty(S) ) {
        printf("��ջ��");
        return 0; /* ERROR��ElementType������ֵ����־���� */
    }
    else 
        return ( S->Data[(S->Top)--] );
}

int main()
{
	
}
