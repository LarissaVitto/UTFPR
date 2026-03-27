#include <stdio.h>
#include <stdlib.h>
void convertelb(double *pkg);
int main(){
    double kg = 0;
    scanf("\n%lf", &kg);
    converte(&kg);
    printf("\nKg para Libras: %lf", kg);
    return 0;
}
void convertelb(double *pkg){
    *pkg = (*pkg) / 0.4536;
}
void convertekg(double *pkg){
    *pkg = (*pkg) / 0.4536; //tem q termina
}

