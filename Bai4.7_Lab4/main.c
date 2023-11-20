
//Tìm trung bình cộng của 4 số thực.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a = 0, b = 0, c = 0, d = 0, average = 0;
    printf("Insert number 1: ");
    scanf("%f", &a);
    printf("Insert number 2: ");
    scanf("%f", &b);
    printf("Insert number 3: ");
    scanf("%f", &c);
    printf("Insert number 4: ");
    scanf("%f", &d);
    average = (a + b + c + d)/4;
    printf("The average is %.2f", average);
    return 0;
}
