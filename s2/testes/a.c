#include <stdio.h>
#include <string.h>
int main()
{
    char a[20]="Program";
    char b[20]={'P','r','o','\0','r','a','m','\0'};

    printf("a = %ld \n",strlen(a));
    printf("b = %ld \n",strlen(b));

    return 0;
}