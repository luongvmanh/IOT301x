#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Viết chương trình đối chiếu 2 chuỗi bằng cách sử dụng con trỏ.
//Prototype
bool compare_string(const char s1[], const char s2[]);
int main()
{
    char string1[] = "think_different";
    char string2[] = "think_different";

    if(compare_string(string1, string2))
    {
        printf("The two strings are the same\n");
    }
    else
    {
        printf("The two strings are different\n");
    }

    return 0;
}

//Creat a function to compare two strings.
bool compare_string(const char s1[], const char s2[])
{
    int i = 0;
    char *ptr1 = s1;
    char *ptr2 = s2;
    bool isEqual = false;

    //Check if the characters are the same
    while(*(ptr1 + i) == *(ptr2 + i) && *(ptr1 + i) != '\0' && *(ptr2 + i) != '\0')
    {
        i++;
    }

    if(*(ptr1 + i) == '\0' && *(ptr2 + i) == '\0') //The characters are the same to the end.
    {
        isEqual = true;
    }
    return isEqual;
}
