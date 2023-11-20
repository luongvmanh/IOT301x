#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Khoi tao bien
    float a = 2.5, b = 5.0;
    float chuVi = 0, dienTich = 0;

    //Tinh chu vi
    chuVi = 2*(a + b);
    printf("Chu vi cua hinh chu nhat co chieu dai %.1f va chieu rong %.1f la %.1f\n", a, b, chuVi);

    //Tinh dien tich
    dienTich = a * b;
    printf("Dien tich cua hinh chu nhat co chieu dai %.1f va chieu rong %.1f la %.1f\n", a, b, dienTich);
    return 0;
}
