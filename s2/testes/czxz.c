#include<stdio.h>
typedef struct p{
    int idx[5];
    float v[5];
}dx;

void run(dx *d){
    d->idx[0] = 0;
    d->v[0] = 1;
    for(int i=1;i<5;i++){
         d->idx[i] = i;
         d->v[i] = i + d->v[i-1];
    }
}

int main(){
  dx a;
  run(&a);
  printf("IDX%d V%f", a.idx[4], a.v[4]);
  return 0;
}