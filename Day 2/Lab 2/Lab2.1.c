#include<stdio.h>

void main(){
	/*
	int x = 0;
	int y = 1;
	printf("true in cc is %d \n",x&y);
	printf("false in cc is %d ", x|y);
	*/
	/*
	int grade; 
	printf("Please enter your grade :  \n ");
	scanf("%d",&grade);
	if(grade<0 || grade >100 )
		printf("please enter valid grade ");
	if(grade>= 0 && grade< 50)
		printf("You failed");
	else if (grade>= 50&&grade<=65)
		printf("Your grade is normal");
	else if(grade>=65&&grade<=75)
		printf("Your grade is Good");
	else if (grade>=75&&grade<85)
		printf("Your grade is very good ");
	else if (grade >= 85 && grade <= 100)
		printf("your grade is excellent"); */ 
	/*
	int id;
	printf("Please enter your ID :  \n ");
	scanf("%d",&id);
	switch(id){
		case 1234:
			printf("Ahmed");
			break;
		case 1242:
			printf("mohamed");
			break;
		case 5312:
			printf("alaa");
			break;
		default:
			printf("out of range ");
			break; */ 
	int id;
	int sum = 0 ;
	float avg;
	for(int i =0 ; i <5;i++){
		if(i==0)
			printf("Please enter number :  \n ");
		scanf("%d",&id);
		sum=sum+id;
	}
	avg= (float)sum / 5; 
	printf("the sum is %d \n the avg is %f", sum , avg);
			

	}
	
	

	
