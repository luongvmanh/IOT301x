//Kiểm tra hai số bằng nhau
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num1 = 0, num2 = 0;
    printf("Insert number1 and number 2: ");
    scanf("%f %f", &num1, &num2);
    if(num1 != (int)num1 || num2 != (int)num2){
        printf("numbers inserted are not integers");

    } else {
        if(num1 > num2){
            printf("number 1 is greater than number 2");
        } else if (num1 == num2){
            printf("number 1 is equal to number 2");
        } else {
            printf("number 1 is less than number 2");
        }
    }
    return 0;
}
