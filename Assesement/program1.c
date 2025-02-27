#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, target;
    

   
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if(n<5){
    printf("please enter minimum 5 elements");
    return 0;
    }
    
    int *arr = (int *)malloc(n*sizeof(int *));
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    printf("Enter the target difference: ");
    scanf("%d", &target);

    
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {  
            if (abs(arr[i] - arr[j]) == target) {  
                printf("Pair found: %d %d\n", arr[i], arr[j]);
                return 0;  
            }
        }
    }

    printf("No pair found with the given difference.\n");
    return 0;
}

