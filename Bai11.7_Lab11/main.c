#include <stdio.h>
#include <stdlib.h>

//Viết hàm hoán đổi 2 số sử dụng con trỏ và gọi ở int main.
//Prototype
int swap2Num (int *pnum1, int *pnum2);
int main()
{
    int num1 = 6;
    int num2 = 18;
    int *pnum1 = &num1;
    int *pnum2 = &num2;
    printf("Before: num1 is %d, num2 is %d\n", num1, num2);
    swap2Num(pnum1, pnum2);
    printf("After: num1 is %d, num2 is %d\n", num1, num2);
    return 0;
}


//Create a function for addition two numbers
int swap2Num (int *pnum1, int *pnum2)
{
    int temp = *pnum1;
    *pnum1 = *pnum2;
    *pnum2 = temp;
    return 0;
}
