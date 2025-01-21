#include <stdio.h>
#include <stdlib.h>

void printtmatrix(int **arr, int n, int m);
void takeinputs(int **arr, int n, int m);
void allocatememory(int ***arr);

int main() {
    int **arr,**brr,**result;
    int r1,c1,r2,c2;
    printf("Enter the rows of the matrix1:\n ");
    scanf("%d", &r1);
    printf("Enter the columns of the matrix1:\n ");
    scanf("%d", &c1);

    printf("for the first array\n"):
    allocatememory(&arr);

    printf("Enter the rows of the matrix2:\n");
    scanf("%d", &n);
    printf("Enter the columns of the matrix:\n ");
    scanf("%d", &m);

    printf("for the second array\n");
    allocatememory(&brr);
    
    return 0;
}

void allocatememory(int ***arr) {

    
    *arr = (int **)malloc(n * sizeof(int *));
    

    
    for (int i = 0; i < n; i++) {
        (*arr)[i] = (int *)malloc(m * sizeof(int));
        
    }

  
    takeinputs(*arr, n, m);

    
    printtmatrix(*arr, n, m);

    for (int i = 0; i < n; i++) {
        free((*arr)[i]);
    }
    free(*arr);
}

void takeinputs(int **arr, int n, int m) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Element [%d][%d]: ", i, j);
           scanf("%d", &arr[i][j]);
        }
    }
}

void printtmatrix(int **arr, int n, int m) {
    printf("The matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
void multiplication(int **arr,int **brr,int n,int m,int x,int y){

	for(int i=0;i<r1;i++){
	
		for(int j=0;i<c2;j++){
		
			for(int k=0;k<c1;k++){
			
			(*result)[i][j]+=arr[i][k]*arr[k][j];
			
			}
		
		}
	}



}
