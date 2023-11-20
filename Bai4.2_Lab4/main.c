/*Nhập một số bất kỳ từ bàn phím và đặt bit thứ 5
của số đã nhập thành bit 1 và đưa kết quả ra màn hình */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int a = 0;
    unsigned int b = 0;
    int fifthBit = 0;
    printf("Nhap so thap phan bat ky: ");
    scanf("%d", &a);
    b = 1 << 4; //shift 1 to the left 4 bits
    thirdBit = a | b;
    printf("%d", fifthBit);
    return 0;
}
