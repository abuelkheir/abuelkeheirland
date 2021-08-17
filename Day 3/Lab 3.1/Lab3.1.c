#include <stdio.h>
int calcMax(int num1,int num2);
//void printMyName();

void main(){
	/*
	printMyName();
	int x,y; 
	scanf("%d %d",&x,&y);
	int max = calcMax(x,y);
	printf("the max is %d",max);
	*/
	int x[10];
	float avg;
	int sum,i; 
	for( i=0;i<10;i++){
		printf("enter 10 numbers %d \n ",i);
		scanf("%d",&x[i]);
		sum = sum + x[i];
	}
	avg=(float)sum/i;
	printf("the sum is %d, the avg is %f : ",sum ,avg);
	
}

int calcMax(int num1,int num2){
	int max= num1; 
	if(num1>max)
		max=num1; 
	if(num2>max)
		max=num2;
	return max; 
}