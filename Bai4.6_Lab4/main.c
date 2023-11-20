/*Nhập 2 số kiểu int từ bàn phím và thực hiện chia
số thứ nhất cho số thứ hai. Đưa kết quả ra màn hình.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 0;
    int b = 0;
    float c = 0;
    printf("Insert the 1st integer: ");
    scanf("%d", &a);
    printf("Insert the 2nd integer: ");
    scanf("%d", &b);
    c = (float)a / b;
    printf("%d devided by %d equals %.2f\n", a, b, c);
    return 0;
}
