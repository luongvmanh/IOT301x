//Tìm bình phương của số nguyên.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 0, b = 0, c = 0, d = 0;
    int sqrt_a = 0, sqrt_b = 0, sqrt_c = 0, sqrt_d = 0;
    printf("Insert integer 1: ");
    scanf("%d", &a);
    printf("Insert integer 2: ");
    scanf("%d", &b);
    printf("Insert integer 3: ");
    scanf("%d", &c);
    printf("Insert integer 4: ");
    scanf("%d", &d);
    sqrt_a = a * a;
    sqrt_b = b * b;
    sqrt_c = c * c;
    sqrt_d = d * d;
    printf("%d square is %d\n", a, sqrt_a);
    printf("%d square is %d\n", b, sqrt_b);
    printf("%d square is %d\n", c, sqrt_c);
    printf("%d square is %d\n", d, sqrt_d);
    return 0;
}
