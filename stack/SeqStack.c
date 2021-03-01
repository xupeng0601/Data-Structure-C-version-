//线性表 栈-顺序存储结构
// Created by xupeng on 2021/2/23.
//

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#define MaxSize 50      //定义栈中的最大元素个数

typedef int Element;
typedef struct Stack{
    Element data[MaxSize];    //存放栈中元素
    int top;       //栈顶指针
}Stack,*SeqStack;

SeqStack InitStack();

int main(){
    SeqStack S = InitStack();
    printf("stack.top: %d",S->top);

}

/*
 * 初始化栈
 * */
SeqStack InitStack(){
    SeqStack S = (SeqStack)malloc(sizeof(SeqStack));
    S->top = -1;
}

/*
 * 栈判空
 * */
bool StackEmpty(SeqStack S){
    if (S->top == -1) {
        return true;
    }
    return false;
}

/*
 * 进栈
 * */
bool Push(SeqStack S,Element x){
    if(S->top = MaxSize - 1) {
        printf("栈满");
        return false;
    }
    S->data[++S->top] = x;  //指针加一，数据入栈
    return true;
}
/*
 * 出栈
 * */
Element Pop(SeqStack S){
    if (S->top == -1) {
        printf("栈空");
        return NULL;
    }
    return S->data[S->top--];  //先出栈，指针再减1
}

/*
 * 读取栈顶元素
 * */
Element GetTop(SeqStack S){
    if (S->top == -1) {
        printf("栈空");
        return NULL;
    }
    return S->data[S->top];
}