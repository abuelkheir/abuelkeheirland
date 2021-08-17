#include <stdio.h>

void main(){
	
	 int i, j, rows, k = 0;  
    printf("Please enter the height of the pyramid");
    scanf ("%d", &rows);   
      
    for ( i =1; i <= rows; i++)  
    {  
        for ( j = 1; j <= rows - i; j++)  
        {  
            printf ("  ");   
        }  
        // relation used to print (2 * i -1)  
        for ( k = 1; k <= ( 2 * i - 1); k++)  
        {  
            printf ("* "); // print the Star  
        }  
        printf ("\n");  
    }  
}