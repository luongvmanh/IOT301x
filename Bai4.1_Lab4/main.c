#include <stdio.h>
#include <stdlib.h>
/*Nhập một số bất kì từ bàn phím và kiểm tra bit
thứ 3 của số đã nhập là bit 0 hay bit 1.
*/

int main()
{
    int a = 0;
    int thirdBit = 0;
    printf("Nhap so thap phan bat ky: ");
    scanf("%d", &a);
    a >> 2; //shift right 2 bits
    thirdBit = a & 1;
    printf("%d", thirdBit);
    return 0;
}
