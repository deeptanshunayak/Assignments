#include<stdio.h>
#include<math.h>
int main(){
	int n;
	printf("enter the number:\n");
	scanf("%d",&n);
	if(n==1 || n==0){
	printf("they are neither composite not prime");
	}
	 
	for(int i=2;i<=n;i++){
		int prime=1;
		// Inner loop to check divisors of `i` (from 2 to √i)
		for(int j=2;j*j<=i;j++){
			if(i%j==0){
				prime=0;	    
				break;
			}

		}
		if(prime){
			printf("%d ",i);
		}

	}
}
