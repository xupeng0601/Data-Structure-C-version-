#include <stdlib.h>
#include <stdio.h>

#define bool char
#define true 1
#define false 0
#define ERROR 0

typedef int ElementType; 
typedef int Position;
struct SNode {
    ElementType *Data; /* 存储元素的数组 */
    Position Top;      /* 栈顶指针 */
    int MaxSize;       /* 堆栈最大容量 */
};
typedef struct SNode* Stack;


/*
Operation: 初始化一个容量为MaxSize的栈 
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
Operation: 是否为满栈 
*/ 
bool IsFull( Stack S )
{
    return (S->Top == S->MaxSize-1);
}

/*
Operation: 入栈 
*/ 
bool Push( Stack S, ElementType X )
{
    if ( IsFull(S) ) {
        printf("堆栈满");
        return false;
    }
    else {
        S->Data[++(S->Top)] = X;
        return true;
    }
}

/*
Operation: 是否为空栈 
*/ 
bool IsEmpty( Stack S )
{
    return (S->Top == -1);
}

/*
Operation: 出栈 
*/ 
ElementType Pop( Stack S )
{
    if ( IsEmpty(S) ) {
        printf("堆栈空");
        return 0; /* ERROR是ElementType的特殊值，标志错误 */
    }
    else 
        return ( S->Data[(S->Top)--] );
}

int main()
{
	
}
