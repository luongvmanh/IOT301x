#include <stdio.h>
#include <stdlib.h>

//Viết hàm cộng 2 số bằng con trỏ và gọi ra sử dụng ở int main.
//Prototype
int add2Num (int *pnum1, int *pnum2);
int main()
{
    int num1 = 6;
    int num2 = 18;
    int *pnum1 = &num1;
    int *pnum2 = &num2;
    int sum = add2Num(pnum1, pnum2);
    printf("%d plus %d is %d.", num1, num2, sum);
    return 0;
}


//Create a function for addition two numbers
int add2Num (int *pnum1, int *pnum2)
{
    return(*pnum1 + *pnum2);
}
