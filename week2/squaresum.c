#include <stdio.h>


int squaresum(int n);
int main()
{
	int n;

	printf("enter the number:");

	scanf("%d",&n);

	printf("the sum of sqauares is: %d",squaresum(n));
	return 0;
}
int squaresum(int n){
	int result=1;
	int sum=0;
	for(int i=1;i<=n;i++){
		result=i*i;
		printf("%d ",result);

	}
	for(int i=1;i<=n;i++){
		result=i*i;        sum=sum+result;
	}
	return sum;

}

