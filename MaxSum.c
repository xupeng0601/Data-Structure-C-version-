#include <stdio.h>


/*
Q: 给定N个整数的序列，求最大的子列和 

*/
int MaxSum(int a[],int N);
int MaxSum2(int a[],int N);
int Max3( int A, int B, int C );
int DivideAndConquer( int List[], int left, int right );
int MaxSum3( int List[], int N );

int main(){
	
	
	int a[] = {-1,-2,-3,7,2};             //整数序列 
	int N = sizeof(a)/sizeof(int);       //序列长度 
	int maxSum;

	//测试
//	maxSum = MaxSum(a,N); 
//	maxSum = MaxSum2(a,N);
	maxSum = MaxSum3(a,N);
	printf("%d\n",maxSum);
	
	return 0;
}


//算法一 以i为子序列起点，j为子序列终点, 逐一累加对比  时间复杂度O(n^3) 
int MaxSum(int a[],int N){
	int maxSum =a[0],thisSum;
	for(int i = 0; i < N; i++){
		for(int j = i; j<N; j++){
			thisSum = 0; 
			for(int k = i; k <= j; k++){
				thisSum +=a[k];
				if(thisSum > maxSum){
					maxSum = thisSum;
				}
			}
		}
	}
	return maxSum;
}



//算法二  时间复杂度O(n^2) 
int MaxSum2(int a[],int N){
	int maxSum =a[0],thisSum;
	for(int i = 0; i < N; i++){
		thisSum = 0;
		for(int j = i; j<N; j++){
		  thisSum += a[j];             //在上一次循环的基础上累加对比 
		  if(thisSum > maxSum)
		  	maxSum = thisSum;
		}
	}
	return maxSum;
}

//算法三  分而治之  时间复杂度O(nlogn);
int Max3( int A, int B, int C ){
    return A > B ? A > C ? A : C : B > C ? B : C;  /* 返回3个整数中的最大值 */
}

int DivideAndConquer( int List[], int left, int right ){ 
    /* 分治法求List[left]到List[right]的最大子列和 */
    int MaxLeftSum, MaxRightSum; /* 存放左右子问题的解 */
    int MaxLeftBorderSum, MaxRightBorderSum; /*存放跨分界线的结果*/

    int LeftBorderSum, RightBorderSum;
    int center, i;

    if( left == right )  { /* 递归的终止条件，子列只有1个数字 */
        if( List[left] > 0 )  return List[left];
        else return 0;
    }

    /* 下面是"分"的过程 */
    center = ( left + right ) / 2; /* 找到中分点 */
    /* 递归求得两边子列的最大和 */
    MaxLeftSum = DivideAndConquer( List, left, center );
    MaxRightSum = DivideAndConquer( List, center+1, right );

    /* 下面求跨分界线的最大子列和 */
    MaxLeftBorderSum = 0; LeftBorderSum = 0;
    for( i=center; i>=left; i-- ) { /* 从中线向左扫描 */
        LeftBorderSum += List[i];
        if( LeftBorderSum > MaxLeftBorderSum )
            MaxLeftBorderSum = LeftBorderSum;
    } /* 左边扫描结束 */

    MaxRightBorderSum = 0; RightBorderSum = 0;
    for( i=center+1; i<=right; i++ ) { /* 从中线向右扫描 */
        RightBorderSum += List[i];
        if( RightBorderSum > MaxRightBorderSum )
            MaxRightBorderSum = RightBorderSum;
    } /* 右边扫描结束 */

    /* 下面返回"治"的结果 */
    return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}

int MaxSum3( int List[], int N ){ 
    /* 保持与前2种算法相同的函数接口 */
    return DivideAndConquer( List, 0, N-1 );
}

