#include <stdio.h>
#include <stdlib.h> 

/*
DATA STRUCTURE: Linear List
����ʵ�� 

*/

#define MAXSIZE 100



typedef struct LNode* List; 
struct LNode{
	int Data[MAXSIZE];
	int Last;    //���Ա������һ��Ԫ�ص����� 
}; 
struct LNode L;
List Ptrl;

//�������� 
List MakeEmpty();
int FindByEle(int element,List Ptrl); 
void InsertByIdx(int index,int element,List Ptrl);

/*
�����±�Ϊi��Ԫ��  L.Data[i]���� Ptrl->Data[i];
���Ա�ĳ��ȣ� Last + 1; 
*/

int main(){
	
	Ptrl = MakeEmpty();
	printf("%d\n",Ptrl->Last);
	
	
}


/*
Operation->��ʼ�� �����յ�˳��� 
*/
List MakeEmpty(){
	List Ptrl = malloc(sizeof(struct LNode));
	Ptrl->Last = -1;  //-1��ʾ����û��Ԫ�� 
	return Ptrl;
} 


/*

Operation->����Ԫ�������Ա��е�һ�γ��ֵ�λ�� ,���û�г��֣�����-1 

element: Ԫ��ֵ
Ptrl:    ���Ա� 
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
Operation->�ڵ�i��λ�ò���һ��Ԫ�� ,Ҫ���������Ա���뱣���������м䲻���п�ֵ 
*/
void InsertByIdx(int index,int element,List Ptrl){
	if(Ptrl.Last = MAXSIZE - 1){
		printf("����"); 
	}
	if(index < 0 || index > Ptrl->Last+1){
		printf("�������Ϸ�")
	}
	
	for(int i = index;i<=Last ;i++){
		Ptrl->Data[i+1] =Ptrl->Data[i]; 
	} 
	Ptrl->Data[index] = element;
	Ptrl->Last++;
	return;
} 


