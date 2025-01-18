#include<stdio.h>
void printarray(int arr1[],int n){

	for(int i=0;i<n;i++){
		printf("%d ",arr1[i]);
	}
}

void sorting(int arr[],int n){
	int i,key,j;

	for(int i=1;i<n;i++){
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}


}

void merge(int arr1[],int arr2[],int n1,int n2){
	int merge[100];
	for(int i=0;i<n1;i++){
		merge[i]=arr1[i];
	}
	for(int i=0;i<n2;i++){
		merge[i+n1]=arr2[i];
	}
	int n = n1+n2;
	sorting(merge,n);
	printf("the values after sorting:\n");
	printarray(merge,n);
	if(n%2==0){
		int x = (merge[n/2]+merge[n/2 -1])/2;
		printf("the median is %d",x);
	}
	else{
		printf("the median is %d",merge[n/2]);
	}

}

void arrayv(int arr1[],int n){
	printf("enter the values in array:");	
	for(int i=0;i<n;i++){
		scanf("%d",&arr1[i]);
	}
}

void takeinputs(int arr1[],int arr2[]){
	printf("enter the no of elements in array1:\n");
	int n1,n2;
	scanf("%d",&n1);
	printf("enter the no of elements in array2:\n");
	scanf("%d",&n2);
	arrayv(arr1,n1);
	arrayv(arr2,n2);
	merge(arr1,arr2,n1,n2);
}

int main(){

	int arr1[100];
	int arr2[100]; 


	takeinputs(arr1,arr2);
	return 0;
}
