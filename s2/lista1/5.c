#include <stdio.h>
#include <string.h>
int main() {
    int V = 0;
    scanf("%d", &V);
    int vet[V];
    for (int i = 0; i < V; i++) {
        scanf("%d", &vet[i]);
    }
    getchar();
    char string[60];
    scanf("%[^\n]", string);
    for (int i = 0; i < V; i++) {
        int a = vet[i];
        printf("%c", string[a]); 
    }
    return 0;
}
