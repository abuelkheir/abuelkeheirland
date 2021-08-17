#include <stdio.h>
void SortArray(int *x, int length);
void main(){
	int arr[5]={3,4,3,1,2};
	SortArray(arr,5);
	for(int i =0 ; i<5;i++){
		printf("%d,",arr[i]);
	}
	
}


void SortArray(int x[], int length){
	int temp;
	for(int i =0 ; i<10;i++){
	 for (int j = 0; j < length-i-1; j++){
		if(x[j]>x[j+1]){
			// swap
			temp = x[j];
			x[j]=x[j+1];
			x[j+1] = temp;
			}
	}
}
}