
#include <stdio.h>
#include <stdlib.h>

void allocatememory(int ***arr, int rows, int cols);
void takeinputs(int **arr, int rows, int cols);
void printtmatrix(int **arr, int rows, int cols);
void matrixmultiplication(int **mat1, int **mat2, int ***result, int r1, int c1, int c2);

int main() {
    int **mat1, **mat2, **result;
    int r1, c1, r2, c2;

    printf("Enter the rows and columns of the first matrix:\n");
    scanf("%d %d", &r1, &c1);

    allocatememory(&mat1, r1, c1);

    printf("Enter elements of the first matrix:\n");
    takeinputs(mat1, r1, c1);

    printf("Enter the rows and columns of the second matrix:\n");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Matrix multiplication not possible\n");
        return 1;
    }

    allocatememory(&mat2, r2, c2);

    printf("Enter elements of the second matrix:\n");
    takeinputs(mat2, r2, c2);

    allocatememory(&result, r1, c2);

    matrixmultiplication(mat1, mat2, &result, r1, c1, c2);

    printf("The result of matrix multiplication is:\n");
    printtmatrix(result, r1, c2);

    for (int i = 0; i < r1; i++) free(mat1[i]);
    free(mat1);

    for (int i = 0; i < r2; i++) free(mat2[i]);
    free(mat2);

    for (int i = 0; i < r1; i++) free(result[i]);
    free(result);

    return 0;
}

void allocatememory(int ***arr, int rows, int cols) {
    *arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        (*arr)[i] = (int *)malloc(cols * sizeof(int));
    }
}

void takeinputs(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void printtmatrix(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void matrixmultiplication(int **mat1, int **mat2, int ***result, int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            (*result)[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                (*result)[i][j] += mat1[i][k] * mat2[k][j];
            
	    }
	}
    }
}

