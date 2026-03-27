#include <stdio.h>
#include <math.h>
void calcDist(double x1, double y1, double x2, double y2, double *dist);
int main(){
    double x1, y1, x2, y2, dist;
    scanf("%lf %lf", &x1, &y1);
    scanf("%lf %lf", &x2, &y2);
    calcDist(x1, y1, x2, y2, &dist); //pq so quer editar a dist ai ela vai de ponteiro
    printf("\n Dist = %lf ", dist);
    return 0;
}
void calcDist(double x1, double y1, double x2, double y2, double *dist){
    double dx = x2 - x1;
    double dy = y2 - y1;
    *dist = sqrt(dx * dx + dy * dy);
}

