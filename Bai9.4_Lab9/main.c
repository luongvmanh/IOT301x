#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Xu ly chuoi
//Viết chương trình loại bỏ các ký tự ngoại trừ bảng chữ cái.

int main()
{
    //Khai bao mang va bien
    char insertStr[20];
    char newStr[20];
    int count = 0;
    printf("Insert string: ");
    scanf("%s", insertStr);
    int length = strlen(insertStr);

    //Remove non-alphabet characters
    for(int i = 0; i < length; ++i){
        if(insertStr[i] != '\0')
        {
            if((insertStr[i] >= 'a' && insertStr[i] <= 'z') || (insertStr[i] >= 'A' && insertStr[i] <= 'Z'))
            {

                newStr[count] = insertStr[i];
                count++;
            }
        }
    }

    //Display new string
    printf("New string is %s\n", newStr);
    return 0;
}
