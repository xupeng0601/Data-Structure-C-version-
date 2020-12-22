#include <stdio.h>
#include <math.h>
#include <time.h>
//函数重复调用次数 
#define MAXK 1e6

/*
多项式函数:
Q:计算一个多项式在给定x点的值  function -> f,f1
  f1的效率比f2慢大概一个数量级的样子，应为f1涉及指数运算，比较耗费时间 
Q:

*/
clock_t start,stop;
double duration;

double f1(int n,double a[],double x);
double f2(int n,double a[],double x);


 

int main(){
	
	printf("%d\n",CLK_TCK);
	
	
	//测试
	int N = 100;   //多项式项数 
	double a[101];   //多项式系数集合 
	double x = 1.1;  //自变量取值 
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


/*  算法一 
n   阶数 
a   系数集合
x   自变量 
*/
double f1(int n,double a[],double x){
	double sum = a[0];
	while(n){
		sum += a[n]*pow(x,n--);
	}
	return sum; 
}

/*
算法二 
秦九韶算法--提公因子 
 
*/
double f2(int n,double a[],double x){
	double sum = a[n];
	while(n--){
		sum = (a[n-1] + sum*x);
	}
	return sum;
}
