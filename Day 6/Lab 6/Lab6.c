#include <stdio.h>

typedef unsigned short int u16; 
typedef struct{
	u16 salary;
	u16 bonus;
	u16 deduction; 
	u16 total;
}Employee;
typedef struct{
	u16 id; 
	u16 physicsGrade;
	u16 mathGrade;
	u16 englishGrade;
	u16 chemGrade; 
}Student; 


void main(){
	/*
	Employee Ahmed; 
	Employee Mo;
	Employee Joe;
	
	Ahmed.salary=1000;
	Ahmed.bonus=500;
	Ahmed.deduction=200;
	Mo.salary=2000;
	Mo.bonus=1000;
	Mo.deduction=0;
	Ahmed.total= Ahmed.salary+Ahmed.bonus-Ahmed.deduction;
	Mo.total=Mo.salary+Mo.bonus-Mo.deduction;
	// not the same output of lab but the goal is understood 
	
	printf(" the value of Ahmed's salary is %d \n ", Ahmed.total);
	*/ 
	int tempId;
	Student x[2];
	x[0].id= 0;
	x[0].physicsGrade= 0;
	x[0].chemGrade= 0;
	x[0].mathGrade=0;
	x[0].englishGrade=0;
	
	x[1].id= 1;
	x[1].physicsGrade= 1;
	x[1].chemGrade= 1;
	x[1].mathGrade=1;
	x[1].englishGrade=1;
	
	printf("please enter id");
	scanf("%d",&tempId);
	if(tempId != 0 || tempId!=1 )
		printf("please enter right id ");
	printf("%d \n",x[tempId].id);
	printf("%d \n",x[tempId].physicsGrade);
	printf("%d \n",x[tempId].chemGrade);
	printf("%d \n",x[tempId].mathGrade);
	printf("%d \n",x[tempId].englishGrade);
		
}

