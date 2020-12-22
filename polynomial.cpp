#include <stdio.h>
#include <math.h>
#include <time.h>
//�����ظ����ô��� 
#define MAXK 1e6

/*
����ʽ����:
Q:����һ������ʽ�ڸ���x���ֵ  function -> f,f1
  f1��Ч�ʱ�f2�����һ�������������ӣ�ӦΪf1�漰ָ�����㣬�ȽϺķ�ʱ�� 
Q:

*/
clock_t start,stop;
double duration;

double f1(int n,double a[],double x);
double f2(int n,double a[],double x);


 

int main(){
	
	printf("%d\n",CLK_TCK);
	
	
	//����
	int N = 100;   //����ʽ���� 
	double a[101];   //����ʽϵ������ 
	double x = 1.1;  //�Ա���ȡֵ 
	a[0] = 1.0;
	for(int i = 1; i <=100 ;i++){
		a[i] = 1.0/i;
	}
	
	start = clock();
	for(int i = 0; i < MAXK; i ++){
	    f1(N - 1,a,1.1); 
	} 
	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK/MAXK;
	printf("ticksl = %f\n",(double)(stop-start));
	printf("duration = %.4e\n",duration);
	
	
	start = clock();
	for(int i = 0; i < MAXK; i ++){
	    f2(N - 1,a,1.1); 
	} 
	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK/MAXK;
	printf("ticks2 = %f\n",(double)(stop-start));
	printf("duration = %.4e\n",duration);
	
	
	
}


/*  �㷨һ 
n   ���� 
a   ϵ������
x   �Ա��� 
*/
double f1(int n,double a[],double x){
	double sum = a[0];
	while(n){
		sum += a[n]*pow(x,n--);
	}
	return sum; 
}

/*
�㷨�� 
�ؾ����㷨--�ṫ���� 
 
*/
double f2(int n,double a[],double x){
	double sum = a[n];
	while(n--){
		sum = (a[n-1] + sum*x);
	}
	return sum;
}
