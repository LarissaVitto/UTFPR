#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j <= i - 1) {
                printf("- ");
            } else {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    for (int j = 1; j < n; j++) {
        printf("- ");
    }
    printf("- "); //gambiarra
    return 0;
}
