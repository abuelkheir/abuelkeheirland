#include <stdio.h>
void main(){
	printf(" Please enter two numbers \n");
	int x,y;
	double answer; // one variable to print all values in it 
	scanf("%d %d",&x,&y);
	answer=x+y;
	printf("the sum is %f \n",answer);
	answer =x*y; 
	printf("the mult is %f \n",answer);
	answer= (float)x / (float)y; 
	printf("the division is %f \n",answer);
	answer= x %y ; 
	printf("the modulus is %f \n",answer);
	
}