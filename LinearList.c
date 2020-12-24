#include <stdio.h>
#include <stdlib.h> 

/*
DATA STRUCTURE: Linear List
数组实现 

*/

#define MAXSIZE 100



typedef struct LNode* List; 
struct LNode{
	int Data[MAXSIZE];
	int Last;    //线性表中最后一个元素的索引 
}; 
struct LNode L;
List Ptrl;

//函数声明 
List MakeEmpty();
int FindByEle(int element,List Ptrl); 
void InsertByIdx(int index,int element,List Ptrl);

/*
访问下标为i的元素  L.Data[i]或者 Ptrl->Data[i];
线性表的长度： Last + 1; 
*/

int main(){
	
	Ptrl = MakeEmpty();
	printf("%d\n",Ptrl->Last);
	
	
}


/*
Operation->初始化 创建空的顺序表 
*/
List MakeEmpty(){
	List Ptrl = malloc(sizeof(struct LNode));
	Ptrl->Last = -1;  //-1表示表中没有元素 
	return Ptrl;
} 


/*

Operation->查找元素在线性表中第一次出现的位置 ,如果没有出现，返回-1 

element: 元素值
Ptrl:    线性表 
*/ 
int FindByEle(int element,List Ptrl){
	int length = Ptrl.Last ;
	int res = -1,i = 0;
	while(i++ <= length){
		if(element == Ptrl->Data[i]){
			res = i;
			return;
		}
	} 
	return res;
	
} 


/*
Operation->在第i个位置插入一个元素 ,要求整个线性表必须保持连续，中间不能有空值 
*/
void InsertByIdx(int index,int element,List Ptrl){
	if(Ptrl.Last = MAXSIZE - 1){
		printf("表满"); 
	}
	if(index < 0 || index > Ptrl->Last+1){
		printf("参数不合法")
	}
	
	for(int i = index;i<=Last ;i++){
		Ptrl->Data[i+1] =Ptrl->Data[i]; 
	} 
	Ptrl->Data[index] = element;
	Ptrl->Last++;
	return;
} 


