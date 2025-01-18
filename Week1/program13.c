#include<stdio.h>
int factorial(int n){

	if(n==1 || n==0){

		return 1;
	}
	return n*factorial(n-1);
}

int main(){

	int n;
	printf("enter the number:\n");
	scanf("%d",&n);
	int x = factorial(n);
	printf("%d",x);

}
