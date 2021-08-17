#include <stdio.h>

void main(){
	int id = 18106689;
	int password =123;
	int temp; 
	printf("plesae enter your id\n");
	scanf("%d",&temp);
	if(temp== id ){
		for(int i =1;i<4;i++){
		printf("\n Please enter your password you have up to 3 trials \n ");
		scanf("%d",&temp);
		if (temp == password){
			printf("Welcome");
		    break;}
		else 
			printf("password is incorrect \n");
			
		}
		}
	else
		printf("Id isn't registered");
}