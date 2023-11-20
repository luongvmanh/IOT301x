//giá trị byte của các kiểu dữ liệu cơ bản: char, int, long, long long, float, double.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int typeChar = sizeof(char);
    int typeInt = sizeof(int);
    int typeLong = sizeof(long);
    int longlong = sizeof(long long);
    int typeFloat = sizeof(float);
    int typeDouble = sizeof(double);
    printf("char is %d byte\n", typeChar);
    printf("int is %d byte\n", typeInt);
    printf("long is %d byte\n", typeLong);
    printf("long long is %d byte\n", longlong);
    printf("float is %d byte\n", typeFloat);
    printf("double is %d byte\n", typeDouble);
    return 0;
}
