#include<stdio.h>
int main(){

	int n;
	printf("enter the number\n");
	scanf("%d",&n);
	int sum=0;
	 // Loop to find all divisors of n (excluding n itself)
	for(int i=1;i<=n/2;i++){
		if(n%i==0){

			sum=sum+i;

		}

	}
          // Check if the sum of divisors equals the original number
	if(sum==n){
		printf("It is a perfect number\n");

	}
	else{

		printf("not a perfect number");
	}
	return 0;
}
