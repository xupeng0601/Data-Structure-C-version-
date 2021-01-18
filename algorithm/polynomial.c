//
// Created by xupeng on 2021/1/13.
//
#include <stdio.h>
#include <math.h>
#include <time.h>

#define COUNT 1e7  /*被测函数运行次数*/

clock_t start, stop;
double duration;  /*记录被测函数运行时间，单位为秒*/


double f(double x,double a[],int n);
double f1(double x,double a[],int n);

int main(){

   /*测试*/
   double x = 1.1;          /*变量值*/
   double a[100] = {1.0};   /*多项式常数集合*/
   int n = 100;             /*多项式的最高次数*/
   for (int i = 1; i <= 100; i++) {
        a[i] = 1.0/i;
    }

    double res = 0.0;
    start = clock();
    for (int i = 1; i < COUNT; ++i) {
       res = f(x, a, n);
    }
    stop = clock();
    duration = (double)(stop - start)/CLK_TCK/COUNT;
    printf("duration: %6.2e\n",duration);

    start = clock();
    for (int i = 1; i < COUNT; ++i) {
       res = f1(x, a, n);
    }
    stop = clock();
    duration = (double)(stop - start)/CLK_TCK/COUNT;
    printf("duration: %6.2e\n",duration);

   return 0;

}


/**
 * 逐项累加法
 * @param x  未知数的值
 * @param a  多项式系数集合
 * @param n  多项式的最高次幂
 * @return   多项式值
 */
double f(double x,double a[],int n)
{
    double sum = a[0];
    for (int i = 1; i <= n; ++i) {
        sum += a[i]*pow(x,i);
    }
    return sum;
}

/**
 * 秦九韶算法--提供公因子
 * @param x    未知数的值
 * @param a    多项式系数集合
 * @param n    多项式的最高次幂
 * @return     多项式值
 */
double f1(double x,double a[],int n)
{
    double sum = a[n];
    while (n){
        sum = a[n-1] + sum*x;
        n--;
    }
    return sum;
}
