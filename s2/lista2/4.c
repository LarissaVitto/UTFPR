#include <stdio.h>
double min(double a, double b);
double max(double a, double b);
    int main(){
    int i, n;
    double a, b;

    scanf("%i", &n);
    for (i = 0; i < n; i++) {
        scanf("%lf %lf", &a, &b);
        printf("%.2lf %.2lf\n", min(a, b), max(a, b));
    }
}
double min(double a, double b){//no moodle é só as função
    if(a > b){
        return(b);
    }else{
        return(a);
    }
}
double max(double a, double b){
    if(a < b){
        return(b);
    }else{
        return(a);
    }
}