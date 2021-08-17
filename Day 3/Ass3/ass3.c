#include <stdio.h>

int  Add(int x , int y);
int subtract(int x , int y);
int mult(int x ,int y);
float div(int x , int y);
float rem(int x,int y);
void And(int x, int y);
void MyNot(int x);
void Myinc(int x);
void Mydec(int x);
void MyOr(int x, int y );
void MyXor(int x, int y );





void main(){
	int opcode; // operation code for the calculator.
	int temp1,temp2;
	int res;
	while(1){
		printf("Please enter a number of operation : \n ");
		scanf("%d",&opcode);
		
		switch(opcode){
			case 1:
				
				printf("please add 2 numbers : \n ");
				scanf("%d %d",&temp1,&temp2);
				res=Add(temp1,temp2);
				printf("%d \n ",res); 
				break;
				
			case 2:
				printf("please enter 2 numbers to sub : \n ");
				scanf("%d %d",&temp1,&temp2);
				res=subtract(temp1,temp2);
				printf("%d \n ",res); 
				break;
			
			case 3:
				printf("please enter 2 numbers to multiply: \n ");
				scanf("%d %d",&temp1,&temp2);
				res=subtract(temp1,temp2);
				printf("%d \n ",res); 
				break;
			
			case 4:
				printf("please enter 2 numbers to divide: \n ");
				scanf("%d %d",&temp1,&temp2);
				res=subtract(temp1,temp2);
				printf("%d \n ",res); 
				break;	
			case 0 :
				break;
			
		
			case 5:
				printf("please enter 2 numbers to and : \n ");
				scanf("%d %d",&temp1,&temp2);
				And(temp1,temp2);
			
			break;
			case 6:
				printf("please enter 2 numbers to or : \n ");
				scanf("%d %d",&temp1,&temp2);
				MyOr(temp1,temp2);
				break;
			case 7:
				printf("please enter one number : \n ");
				scanf("%d ",&temp1);
				MyNot(temp1);
				break;
			case 8:
				printf("please enter 2 numbers to Xor : \n ");
				scanf("%d %d",&temp1,&temp2);
				MyXor(temp1,temp2);
				break;
			case 9:
				printf("please enter 2 numbers to remainder: \n ");
				scanf("%d %d",&temp1,&temp2);
				res=rem(temp1,temp2);
				printf("%d \n ",res); 
				break;
			case 10:
				printf("please enter one number : \n ");
				scanf("%d ",&temp1);
				Myinc(temp1);
				break;
			case 11:
				printf("please enter one number : \n ");
				scanf("%d ",&temp1);
				Mydec(temp1);
				break;	
			
			
		}
	
		
		
	}
}

int Add(int x , int y){
	return x+y;
}
int subtract(int x , int y){
	return x-y;
}

int mult(int x ,int y){
	return x*y;
}

float div(int x , int y){
	return (float)x / (float) y; 
}

float rem(int x,int y){
	return x%y;
}

void And(int x, int y){
	printf("\n %d",x&y);
}
void MyOr(int x, int y){
	printf("\n %d",x|y);
}
void MyXor(int x,int y){
	printf("\n %d",x^y);
}
void MyNot(int x){
	printf("\n %d",!x);
}
void Myinc(int x){
	printf("%d",x++);
}
void Mydec(int x){
	printf("%d",x--);
}
