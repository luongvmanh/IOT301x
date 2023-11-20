//Nhập số phút và chuyển đổi số phút thành đơn vị năm và ngày.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int minutes = 0;
    printf("Insert minutes: ");
    scanf("%d", &minutes);
    int days = 0, years = 0;
    days = minutes/(60 * 24);
    years = days / 365;
    printf("days is %d\n", days);
    printf("years is %d\n", years);
    return 0;
}
