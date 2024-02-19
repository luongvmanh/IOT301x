#include <stdio.h>
#include <stdlib.h>

//Hoán đổi hai số bằng con trỏ
int main()
{
    int num1 = 33;
    int num2 = 13;
    int *pNum1 = &num1, *pNum2 = &num2, temp;
    printf("Hai so truoc khi doi cho la %d va %d\n", num1, num2);
    temp = *pNum1;
    *pNum1 = *pNum2;
    *pNum2 = temp;
    printf("Hai so sau khi doi cho la %d va %d\n", num1, num2);
    int a = 12;
    void *ptr = (int*)&a;
    printf("%d", *ptr);
    getchar();
    return 0;
}
