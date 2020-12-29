#include <stdio.h>


int BinarySearch(int* arr,int length,int value){
	int left,right,mid,NotFound = -1;
	left = 0;
	right = length;


	while(left <= right){
		mid = (left + right)/2;
		if(arr[mid]> value){
			right = mid - 1;
		}else if(arr[mid] < value){
			left = mid + 1;
		}else{
			return mid;
		}
	}
	return NotFound;
}

int main(){
	
	int arr[]= {1,2,3,4,5,6,55,77,88};
	int idx = BinarySearch(arr,sizeof(arr)/sizeof(int),55);
	printf("%d\n",idx);
	
}
