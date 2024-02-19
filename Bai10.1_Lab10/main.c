#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 32;
    float b = 3.21;
    int *pInt = &a;
    float *pFloat = &b;
    char *c = "Pointers is hard!";
    printf("Address of integer: %p\n", pInt);
    printf("Value of integer variable: %d\n", *pInt);
    printf("Address of float: %p\n", pFloat);
    printf("Value of float variable: %f\n", *pFloat);
    printf("Address of char: %p\n", c);
    printf("Value of char variable: %s\n", c);
    return 0;
}
