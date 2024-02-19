#include <stdio.h>
#include <stdlib.h>


/*Sử dụng kiểu cấu trúc để viết chương trình tính tổng hai khoảng cách biểu thị
bằng đơn vị feet và đơn vị inch.*/

typedef struct
{
    int feet;
    int inch;
} distance;

//prototype
void addDistance(distance dst1, distance dst2);

int main()
{
    distance distance_1 = {12, 27};
    distance distance_2 = {3, 8};
    addDistance(distance_1, distance_2);
    return 0;
}


void addDistance(distance dst1, distance dst2)
{
    distance sum = {dst1.feet + dst2.feet, dst1.inch + dst2.inch};
    printf("Tong cua hai khoang cach lan luot la %d, %d\n", sum.feet, sum.inch);
}
