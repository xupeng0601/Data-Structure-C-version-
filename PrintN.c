#include <stdio.h>


//Q:ʵ��һ��������ʹ�ô���һ��������N, ��ӡ��1��N֮ǰ���������� 

/*�ܽ᣺����㷨һ���㷨������N��ֵ�㹻���ʱ���㷨���ͻᱼ�� 
        ԭ���ǵݹ����Կռ��ռ�����󣬿ռ䲻��ʱ������ͻᱼ����
       ��Ȼ���ݹ���ó����㹻���
*/ 


void Print();
void PrintDG(int N);

int main(){
	//Print();
	PrintDG(10);
	
	
	retrun 0;	
} 

//�㷨һ 
void Print(){
	int N,I = 1;
	scanf("%d",&N);
	while(I<=N){
		printf("%d\n",I++);
	} 	
	return;
} 


//�㷨��  �ݹ� 
void PrintDG(int N){
	if(N){
		PrintDG(N-1);
		printf("%d\n",N);
	}
	return;
} 
