#include <stdio.h>
#include <stdlib.h>

//Viết hàm tìm giai thừa của 1 số cho trước bằng con trỏ.
//Prototype
int factorial(int n, int *f);

int main()
{
    int n = 0;
    int *f = &n;
    printf("Insert a number: ");
    scanf("%d", &n);
    int result = factorial(n, f);
    printf("Factorial is %d.");
    return 0;
}

//Create a function to find factorial
int factorial(int n, int *f)
{
    int i = 1;
    *f = 1;
    for(; i <= n; i++)
    {
        *f = *f * i;
    }
    return *f;
}
