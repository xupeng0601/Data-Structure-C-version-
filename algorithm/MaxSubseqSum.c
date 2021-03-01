//
// Created by xupeng on 2021/1/25.
//

#include <stdio.h>


int f1(int a[],int length);
/**
 * 测试
 * @return
 */
int main(){

    int a[8] = {1,-1,2,4,7,8,-11,-3};
    int max;
    int length = sizeof(a)/sizeof(int);
    max = f1(a,length);

    printf("%d\n",length);
    printf("f1 max = %d\n",max);

    return 0;
}

/**
 *
 * @param a         数组序列
 * @param length    序列长度
 * @return
 */
int f1(int a[],int length){
    int i,j;    //i表示子列左端，j表示子列右端
    int SubseqSum = a[0];  //a[i]到a[j]的子列和
    int MAX = a[0];        //最大子列和
    for(i = 0;i < length;i++){
         SubseqSum = a[i];
        if(a[i] > MAX)
            MAX = a[i];
        for(j = i+1;j < length;j++){
            SubseqSum += a[j];
            if(SubseqSum > MAX)
                MAX = SubseqSum;
        }
    }
    return MAX;
}