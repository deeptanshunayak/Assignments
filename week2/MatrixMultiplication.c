#include<stdio.h>
#include<stdlib.h>
void printtmatrix(int **arr,int n,int m);
void takeinputs(int **arr,int n,int m);
void allocatememory(int ***arr);


void main(){


 int **arr;
 allocatememory(&arr);



}


void allocatememory(int ***arr){


int n,m;
printf("enter the rows of matrix\n");
scanf("%d",&n);
printf("enter the coumn of the matrix\n");
scanf("%d",&m);

*arr=(int **)malloc(n*sizeof(int *));

for(int i=0;i<n;i++){

(*arr)[i]=(int *)malloc(m*sizeof(int));
}
takeinputs(*arr,n,m);
printmatrix(*arr,n,m);
}
void takeinputs(int **arr,int n,int m){

for(int i=0;i<n;i++){

	for(int j=0;j<m;j++){
	scanf("%d",&arr[i][j]);
	
	}

}
 
}
void printmatrix(int **arr,int n,int m){

for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){
        printf("%d ",arr[i][j]);

        }
	printf("\n");

}



}



