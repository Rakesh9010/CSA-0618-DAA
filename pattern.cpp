#include <stdio.h>

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        
        for (int space = 1; space <= n - i; space++) {
            printf("  ");
        }

        
        for (int j = 1; j <= i; j++) {
            printf("%2d", j);

            
            if (j < i) {
                printf(" ");
            }
        }

        
        printf("\n");
    }

    return 0;
}
