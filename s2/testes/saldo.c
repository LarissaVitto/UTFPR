#include <stdio.h>
void calcularSaldo(int n, float valores[n], float* saldo, float* cred, float* deb);
int main() {
    float saldo, cred, deb;
    float Vetor1[] = {200.99, -10.99, 5000, -600, 20};
    float Vetor2[] = {-999.99, 1000, 1500, -750.95};
    calcularSaldo(5, Vetor1, &saldo, &cred, &deb);
    calcularSaldo(4, Vetor2, &saldo, &cred, &deb);
    return 0;
}
void calcularSaldo(int n, float valores[n], float* saldo, float* cred, float* deb) {
    *saldo = 0;
    *cred = 0;
    *deb = 0;
    for (int i = 0; i < n; i++) {
        *saldo += valores[i];
        if (valores[i] < 0) {
            *deb += valores[i];
        } else {
            *cred += valores[i];
        }
    }
    printf("O Vetor de %d espacos tem o Saldo de: %f, o credito de: %f e o debito de: %f\n", n, *saldo, *cred, *deb);
}