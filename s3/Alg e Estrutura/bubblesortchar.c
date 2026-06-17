#include <stdio.h>
void bubblesort(char* str, int n) {
    for (int j = 0; j < n - 1; j++) {
        for (int i = 0; i < n - 1 - j; i++) {
            if (str[i] > str[i+1]) {
                char aux = str[i];
                str[i] = str[i+1];
                str[i+1] = aux;
            }
        }
    }
}

int main() {
    char str[100];

    printf("Digite uma string: ");
    scanf("%s", str); 

    bubblesort(str, strlen(str)); 

    printf("\nString ordenada:\n");
    for (int i = 0; i < strlen(str); i++) {
        printf("%c\n", str[i]);
    }

    return 0;
}