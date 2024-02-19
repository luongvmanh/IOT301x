#include <stdio.h>
#include <stdlib.h>

#define max 10000
#define FILENAME "test.txt"
//Viết chương trình đọc và hiển thị thông tin trong file test.txt

int main()
{
    FILE *file = NULL;
    char str[max];
    file = fopen(FILENAME, "r"); //open to read mode
    if (file != NULL)
    {
        //Read file
        while(fgets(str, max, file) != NULL)
        {
            printf("%s", str);
        }
        fclose(file); //close
    }

    file = NULL; //set pointer to NULL
    return 0;
}
