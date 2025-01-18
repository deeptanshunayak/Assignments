#include <stdio.h>
#include <math.h>
//function to print the Ap
void print_ap(int a, int r, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a + i * r);
    }
    printf("\n");
}
//function to print the Gp
void print_gp(int a, int r, int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", a * pow(r, i));
    }
    printf("\n");
}
//function to print the Hp

void print_hp(int a, int r, int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", 1.0 / (a + i * r));
    }
    printf("\n");
}

int main() {
    int a, r, n;

    printf("Enter the first term (a): ");
    scanf("%d", &a);

    printf("Enter the common difference (r for AP and HP, ratio for GP): ");
    scanf("%d", &r);

    printf("Enter the number of terms (n): ");
    scanf("%d", &n);
    printf("Ap\n");
    print_ap(a, r, n);
     printf("Gp\n");
    print_gp(a, r, n);
     printf("Hp\n");
    print_hp(a, r, n);

    return 0;
}

