#include <stdio.h>


/*
Q: ����N�����������У����������к� 

*/
int MaxSum(int a[],int N);
int MaxSum2(int a[],int N);
int Max3( int A, int B, int C );
int DivideAndConquer( int List[], int left, int right );
int MaxSum3( int List[], int N );

int main(){
	
	
	int a[] = {-1,-2,-3,7,2};             //�������� 
	int N = sizeof(a)/sizeof(int);       //���г��� 
	int maxSum;

	//����
//	maxSum = MaxSum(a,N); 
//	maxSum = MaxSum2(a,N);
	maxSum = MaxSum3(a,N);
	printf("%d\n",maxSum);
	
	return 0;
}


//�㷨һ ��iΪ��������㣬jΪ�������յ�, ��һ�ۼӶԱ�  ʱ�临�Ӷ�O(n^3) 
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



//�㷨��  ʱ�临�Ӷ�O(n^2) 
int MaxSum2(int a[],int N){
	int maxSum =a[0],thisSum;
	for(int i = 0; i < N; i++){
		thisSum = 0;
		for(int j = i; j<N; j++){
		  thisSum += a[j];             //����һ��ѭ���Ļ������ۼӶԱ� 
		  if(thisSum > maxSum)
		  	maxSum = thisSum;
		}
	}
	return maxSum;
}

//�㷨��  �ֶ���֮  ʱ�临�Ӷ�O(nlogn);
int Max3( int A, int B, int C ){
    return A > B ? A > C ? A : C : B > C ? B : C;  /* ����3�������е����ֵ */
}

int DivideAndConquer( int List[], int left, int right ){ 
    /* ���η���List[left]��List[right]��������к� */
    int MaxLeftSum, MaxRightSum; /* �������������Ľ� */
    int MaxLeftBorderSum, MaxRightBorderSum; /*��ſ�ֽ��ߵĽ��*/

    int LeftBorderSum, RightBorderSum;
    int center, i;

    if( left == right )  { /* �ݹ����ֹ����������ֻ��1������ */
        if( List[left] > 0 )  return List[left];
        else return 0;
    }

    /* ������"��"�Ĺ��� */
    center = ( left + right ) / 2; /* �ҵ��зֵ� */
    /* �ݹ�����������е����� */
    MaxLeftSum = DivideAndConquer( List, left, center );
    MaxRightSum = DivideAndConquer( List, center+1, right );

    /* �������ֽ��ߵ�������к� */
    MaxLeftBorderSum = 0; LeftBorderSum = 0;
    for( i=center; i>=left; i-- ) { /* ����������ɨ�� */
        LeftBorderSum += List[i];
        if( LeftBorderSum > MaxLeftBorderSum )
            MaxLeftBorderSum = LeftBorderSum;
    } /* ���ɨ����� */

    MaxRightBorderSum = 0; RightBorderSum = 0;
    for( i=center+1; i<=right; i++ ) { /* ����������ɨ�� */
        RightBorderSum += List[i];
        if( RightBorderSum > MaxRightBorderSum )
            MaxRightBorderSum = RightBorderSum;
    } /* �ұ�ɨ����� */

    /* ���淵��"��"�Ľ�� */
    return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}

int MaxSum3( int List[], int N ){ 
    /* ������ǰ2���㷨��ͬ�ĺ����ӿ� */
    return DivideAndConquer( List, 0, N-1 );
}

