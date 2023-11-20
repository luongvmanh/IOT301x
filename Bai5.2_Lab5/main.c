//Kiểm tra số chẵn hay số lẻ
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0;
    printf("Insert a number: ");
    scanf("%d", &num);
    if (num % 2 == 0){
        printf("%d is even", num);
    } else {
        printf("%d is odd", num);55
    }
    return 0;
}
