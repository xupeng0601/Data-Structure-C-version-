#include <stdio.h>


//Q:ʵ��һ��������ʹ�ô���һ��������N, ��ӡ��1��N֮ǰ���������� 



void Print();
void PrintDG(int N);

int main(){
	//Print();
	PrintDG(10);
	
} 

//�㷨һ 
void Print(){
	int N,I = 1;
	scanf("%d",&N);
	while(I<=N){
		printf("%d\n",I++);
	} 	
} 


//�㷨��  �ݹ� 
void PrintDG(int N){
	if(N){
		PrintDG(N-1);
		printf("%d\n",N);
	}
} 
