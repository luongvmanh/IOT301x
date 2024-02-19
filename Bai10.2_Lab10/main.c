#include <stdio.h>
#include <stdlib.h>


//Sử dụng con trỏ để thay đổi giá trị của biến
int main()
{
    int a = 88;
    int *ptr = &a;
    printf("Gia tri ban dau: %d\n", a);
    *ptr = 103;
    printf("Gia tri sau khi thay doi: %d\n", a);
    return 0;
}
