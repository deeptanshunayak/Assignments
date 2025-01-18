#include<stdio.h>
//function to print the binary representation of the number
void printbits(int n){
	int bitsize=32;	
	for(int i=bitsize-1;i>=0;i--){

		int bit = (n>>i)&1;

		printf("%d",bit);


	}
	printf("\n");
}
//function to compute the 2s compliment and print binary representation of it
void checkfor2s(int n){

	int abs = -n;//absolute value of the number
	int onec=~abs;//compute 1s compliment
	int twoc=onec +1;//compute 2s compliment
	printf("2s compliment of the no:\n");
	printbits(twoc);
	printf("negative binary representation\n");
	printbits(n);
}
int main(){

	int n;
	printf("enter the number\n");
	scanf("%d",&n);
            
	// If the number is negative, compute and display its 2's complement representation

	if(n<0){

		checkfor2s(n);


	}
	else{

		printbits(n);
	}


}
