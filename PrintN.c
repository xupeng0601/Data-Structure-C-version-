#include <stdio.h>


//Q:实现一个函数，使得传入一个正整数N, 打印出1到N之前的所有整数 



void Print();
void PrintDG(int N);

int main(){
	//Print();
	PrintDG(10);
	
} 

//算法一 
void Print(){
	int N,I = 1;
	scanf("%d",&N);
	while(I<=N){
		printf("%d\n",I++);
	} 	
} 


//算法二  递归 
void PrintDG(int N){
	if(N){
		PrintDG(N-1);
		printf("%d\n",N);
	}
} 
