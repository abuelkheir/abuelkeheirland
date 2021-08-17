#include <stdio.h>

void main(){
	int x,y,z;
	printf("please enter 3 numbers \n ");
	scanf("%d %d %d",&x,&y,&z);
	int max= x ; 
	if(y>max)
		max=y; 
	if(z>max)
		max=z;
	printf("the max number is %d" , max);
	
}