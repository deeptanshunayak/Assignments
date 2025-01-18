#include<stdio.h>
int main(){

	int n;
	int n1=0;
	int n2=1;
         // Prompt the user to enter the limit for the Fibonacci series
	printf("enter the no you want series to be printed\n");
	scanf("%d",&n);
	// Print the first two numbers of the Fibonacci series
	printf("%d %d",n1,n2);
	int i=0;

	// Loop to generate and print the Fibonacci series until the current number exceeds the limit
	while(n2<n){

		int n3=n1+n2;
		printf(" %d ",n3);
		n1=n2;

		n2=n3;

	}
	return 0;

}
