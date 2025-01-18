#include<stdio.h>
//function to check number is even or odd
void checkeven(int n){
	if(n%2==0){
		printf("the number is even\n");
	}
	else{
		printf("the number is odd\n");
	}
}
//function to check number is positive or negative
void checksign(int n){
	if(n>0){
		printf("the number is positive");
	}
	else{
		printf("the number is negative");
	}
}
int main(){
	int n;
	printf("enter the number\n");
	scanf("%d",&n);
	checkeven(n);
	checksign(n);

}
