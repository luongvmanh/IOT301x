//Đoán số.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int answerNum = 64;
    int insertNum = 0;
    printf("It's a 2 digits number\n");
    while(insertNum != answerNum){
        printf("Insert number: ");
        scanf("%d", &insertNum);
    }
    printf("Congratulation! You are correct!");
    return 0;
}
