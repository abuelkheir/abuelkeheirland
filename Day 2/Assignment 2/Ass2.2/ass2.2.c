#include <stdio.h>
void main(){
	int id = 18106689;
	int password =123;
	int temp; 
	printf("plesae enter your id ");
	scanf("%d",&temp);
	if(temp== id ){
		printf("\n Please enter your password \n ");
		scanf("%d",&temp);
		if (temp == password)
			printf("user name : Ahmed");
		else 
			printf("password is incorrect");
			
		}
	else
		printf("Id is invalid");
	
	
}
