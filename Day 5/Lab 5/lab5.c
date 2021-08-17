#include <stdio.h>
int multarray(int *x,int* y,int size);
void main(){
	
	int size =5; 
	int a1[5]={1,1,1,1,1};
	int a2[5]={1,1,1,1,1};
	int mult = multarray(a1,a2,size);
	printf("the mult is %d",mult);
	
}

int multarray(int *x,int* y,int size){
	int sum=0;
	for(int i =0; i<size ; i++ ){
		sum= sum + (x[i]*y[i]);
	}
	return sum;
}