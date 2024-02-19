#include <stdio.h>
#include <stdlib.h>

#define filename "test.txt"
#define max 10000

//Viết chương trình đếm số dòng trong file test.txt

int main()
{
    FILE *file = NULL;
    file = fopen(filename, "r");
    char ch;
    int count = 1;
    if(file == NULL)
    {
        printf("Couldn't open file");
        return -1;
    }

    while((ch = fgetc(file)) != EOF)
    {
        if(ch == '\n')
        {
            count++;
        }
    }
    fclose(file);
    file = NULL;
    printf("There are %d lines\n", count);
    return 0;
}
