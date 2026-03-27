#include <stdio.h>
int comp(double a, double b);
int main(){
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("%i\n", comp(a, b));
    return 0;
}
int comp(double a, double b){ //no moodle é só isso aqui e o include
    if(a == b){
        return(0);
    }else if(a > b){
        return(1);
    }else{
        return(-1);
    }
}
