#include <stdio.h>

void main(){
	/*
	int x[10]={6,2,4,2,7,10,9,11,3,1};
	int temp;
	// sorting the array
	for(int i =0 ; i<10;i++){
	 for (int j = 0; j < 10-i-1; j++){
		if(x[j]>x[j+1]){
			// swap
			temp = x[j];
			x[j]=x[j+1];
			x[j+1] = temp;
			}
		}
	}
	
	printf("the min is %d \n ,the max is %d ",x[0],x[9]);*/
	
	int c1[5]={10,70,90,10,20};
	int c2[5]={30,100,49,75,90};
	int c3[5]={70,15,23,43,92};
	int allschool[15];
	int passedCnt;
	int failedCnt;
	int temp; 
	float sum=0;
	for(int i =0;i<5;i++){
		if(c1[i]>=50)
			passedCnt++;
		else	
			failedCnt++;
		if(c2[i]>=50)
			passedCnt++;
		else	
			failedCnt++;
		if(c3[i]>=50)
			passedCnt++;
		else	
			failedCnt++;
		
		allschool[i]=c1[i];
		allschool[i+4]=c2[i];
		allschool[i+9]=c3[i];
	}
	// sorting allschool array
	for(int i =0 ; i<10;i++){
			for (int j = 0; j < 10-i-1; j++){
			if(allschool[j]>allschool[j+1]){
				// swap
				temp = allschool[j];
				allschool[j]=allschool[j+1];
				allschool[j+1] = temp;
				}
	}  
	
	for(int i=0;i<15;i++){
		sum= allschool[i]+sum;
	}
	sum = temp; 
	sum = (float)temp/15;
	
	
} 
	printf("the min grade is %d \n the max grade is %d  \n The number of passed/ failed students is %d :: %d \n the aveerage is %f\n ",allschool[0],allschool[9],passedCnt,failedCnt,sum);

}
 
       
      
		
	
