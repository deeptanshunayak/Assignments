#include<stdio.h>
int main(){
	int n;
	printf("enter the number:\n");
	scanf("%d",&n);
	 // Check if the number is odd or even using bitwise AND operator
	if(n&1==1){
		// If the LSB is 1, the number is odd
		printf("this is odd number");

	}
	else{
		// If the LSB is 0, the number is even
		printf("this is even numbers");
	}
	return 0;
}
