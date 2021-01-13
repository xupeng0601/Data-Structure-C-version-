//
// Created by xupeng on 2021/1/13.
//
#include <stdio.h>
#include <math.h>


double f(double x,double a[],int n);

int main(){

   /*测试*/
   double x = 1.1;
   double a[] = {1,2,3,4,5};
   int n = 5;

   double res = f(x, a, n);
   printf("多项式求和结果为: %fl\n", res);

   return 0;

}


/**
 * 逐项累加法
 * @param x  未知数的值
 * @param a  多项式系数集合
 * @param n  多项式的项数
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
 * @param n    多项式的项数
 * @return     多项式值
 */
double f1(double x,double a[],int n)
{
    double sum = 0;
    while (n){
        sum += a[n-1] + a[n]*x;
    }
    return sum;
}