#include <Stdio.h>
int myAdd(int *x,int *y);
void main(){
	/* lab3
	int x=1;
	int y=2;
	int z; 
	z= myAdd(&x,&y);
	printf("the sum is %d",z);
	*/
	
	/* lab1 
	int x[5];
	for( i = 0 ; i<5  ;i++){
		printf("please enter numbers : \n");
		scanf("%d",&x[i]);
	}
	int searchNum;
	printf("please enter a number to search for : \n ");
	scanf("%d",&searchNum);
	int counter=0;
	int flag=0;
	
	for( i = 0 ; i<5  ;i++){
		if(searchNum==x[i]){
			counter++;
			flag = 1;
		}	
	}
	if(flag==1 )
		printf("the number %d  exists : %d  times \n",searchNum, counter);
	else
		printf("the number doesn't exist\n");*/
	
		
	/*lab2
	
	int x=5;
	printf("the value before change %d \n",x);
	
	int *ptr=&x;
	*ptr = 4;
	printf("the value before change %d \n",x);
	*/
	
	int x[5] = {1,1,1,1,1};
	int *ptr = x; 
	int sum=0;
	for(int i=0; i<5;i++){
		sum = sum+*ptr;
		ptr++;
	}
	printf("the sum is %d",sum);
}

int myAdd(int *x ,int *y){
	return *x+*y;
}