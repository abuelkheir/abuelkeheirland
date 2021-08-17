#include <stdio.h>

typedef unsigned short int u16; 
typedef signed char s8; 
typedef unsigned short int u16; 
typedef unsigned long int u32;



/* test  of sizes 
	typedef struct{
	u16 x; 
	u32 y;
	u16  z; 
	u32 k ; 
	
}testStruct; */ 



typedef union {
	struct {
	u8 bit_0: 1;
	u8 bit_1: 1; 
	u8 bit_2: 1;
	u8 bit_3: 1;
	u8 bit_4: 1;
	u8 bit_5: 1;
	u8 bit_6: 1;
	u8 bit_7: 1;
	}bit;s 
	u8 byte; 
}Register; 
void main(){
	
	
	
}