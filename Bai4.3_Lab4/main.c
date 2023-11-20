/* Chuyển đổi số ngày được nhập từ bàn phím
tương ứng với a-năm, b-tuần, c-ngày*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int days = 0;
    int a = 0, b = 0, c = 0;
    printf("Insert days: ");
    scanf("%d", &days);
    a = days/365;
    b = (days - 365 * a)/7; //week remaining
    c = days - 365 * a - 7 * b;
    printf("year is %d\n", a);
    printf("week is %d\n", b);
    printf("day is %d\n", c);
    return 0;
}
