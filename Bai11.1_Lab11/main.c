#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Hiển thị chuỗi theo thứ tự ngược bằng con trỏ
int main()
{
    char string[] = "?gniod uoy era tahW";
    char *c = string;

    //Count the string length
    int i = 0;
    while(*(c + i) != '\0')
    {
        ++i;

    }
    i--; //Do not display '\0' character.

    //Display the string in reverse.
    for(i; i>=0; i--)
    {

        printf("%c", *(c + i));

    }

    return 0;
}
