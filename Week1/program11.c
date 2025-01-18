#include<stdio.h>
#include<limits.h>
int main(){

	int n;

	int s;

	printf("enter the number for circular right and left shift\n");
	scanf("%d",&n);
	printf("enter the number for no of shifts\n");
	scanf("%d",&s);


	int bitsize=sizeof(n)*CHAR_BIT;



	int x = n>>s;
	int y= n<<(bitsize-s);
	int result1= x|y;




	int a=n<<s;
	int b=n>>(bitsize-s);
	int result2=a|b;
	printf("for right circular shift result is %d\n",result1);
	printf("for left circular shift result is %d\n",result2);
}
