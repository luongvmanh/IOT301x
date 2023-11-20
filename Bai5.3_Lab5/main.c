//Hiển thị thông báo thời tiết

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int temp = 0;
    printf("Insert temperature: ");
    scanf("%d", &temp);
    if (temp < 0){
        printf("It's freezing");
    }
    else if (temp >= 0 && temp < 10){
        printf("It's cold");
    }
    else if (temp >= 10 && temp < 20){
        printf("It's chilly");
    }
    if (temp >= 20 && temp < 30){
        printf("It's nice");
    }
    if (temp >= 30 && temp < 40){
        printf("It's hot");
    }
    else if (temp >= 40){
        printf("It's scorching");
    }
    return 0;
}
