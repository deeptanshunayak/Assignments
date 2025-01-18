#include<stdio.h>
struct srudent{
	int arr[10];
	int a;
	char b;
	double c;

};
union employee{
	int a;
	char b;
};
int main(){

	printf("the size of int %lu \n",sizeof(int));
	printf("the size of float %lu\n",sizeof(float));
	printf("the size of double %lu\n",sizeof(double));
	printf("the size of short int %lu\n",sizeof(short));
	int arr[10];
	int a;
	int *p = &a;
	printf("the sixe of pointer is %lu\n",sizeof(p));
	printf("the size of the array is %lu\n",sizeof(arr));
	printf("the size of structure is %ld\n",sizeof(struct srudent));
	printf("the size of union is %ld\n",sizeof(union employee));
}
