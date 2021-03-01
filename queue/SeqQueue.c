//
// Created by xupeng on 2021/2/23.
//
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#define MaxSize 50 //定义队列中的最大个数

typedef int ElemType;
typedef struct SeqQueue{
    ElemType data[MaxSize]; //存放队列元素
    int front,rear;        //队头指针和队尾指针
}*SeqQueue;


int main(){

}

/**
 * 初始化
 * @param Q
 */
void InitQueue(SeqQueue Q){
    Q = (SeqQueue)malloc(sizeof(SeqQueue));
    Q->rear = Q->front = 0;    //初始化队尾，队首指针
}

/**
 * 判断队空
 * @param Q
 * @return
 */
bool isEmpty(SeqQueue Q,ElemType x){
    if (Q->rear == Q->front) return true;
    return false;
}

/**
 * 入队
 * @param Q
 * @param x
 * @return
 */
bool Enqueue(SeqQueue Q,ElemType x){
    if((Q->rear + 1)%MaxSize == Q->front){
        printf("队满");
        return false;
    }
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear+1)/MaxSize;
}

/**
 * 出队
 * @param Q
 * @param x
 * @return
 */
bool DeQueue(SeqQueue Q,ElemType x){
    if (Q->rear == Q->front) return false;
    x = Q->data[Q->front];
    Q->front = (Q->front+1)%MaxSize;
    return true;
}


