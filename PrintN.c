#include <stdio.h>


//Q:实现一个函数，使得传入一个正整数N, 打印出1到N之前的所有整数 

/*总结：针对算法一，算法二，当N的值足够大的时候，算法二就会奔溃 
        原因是递归程序对空间的占用量大，空间不足时，程序就会奔溃；
       当然，递归会让程序足够简洁
*/ 


void Print();
void PrintDG(int N);

int main(){
	//Print();
	PrintDG(10);
	
	
	retrun 0;	
} 

//算法一 
void Print(){
	int N,I = 1;
	scanf("%d",&N);
	while(I<=N){
		printf("%d\n",I++);
	} 	
	return;
} 


//算法二  递归 
void PrintDG(int N){
	if(N){
		PrintDG(N-1);
		printf("%d\n",N);
	}
	return;
} 
