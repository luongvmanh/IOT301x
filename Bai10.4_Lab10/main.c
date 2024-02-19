#include <stdio.h>
#include <stdlib.h>


//Tính tổng hai số bằng con trỏ
int main()
{
    int num1, num2;
    int *ptr1 = &num1, *ptr2 = &num2;
    printf("Nhap so thu nhat: ");
    scanf("%d", &num1);
    printf("Nhap so thu hai: ");
    scanf("%d", &num2);
    printf("Tong cua hai so %d va %d la: %d", num1, num2, *ptr1 + *ptr2);

    return 0;
}
