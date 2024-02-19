#include <stdio.h>
#include <stdlib.h>

#define FILENAME "test.txt"
//Viết chương trình tạo và lưu trữ thông tin trong file test.txt.
int main()
{
    FILE *fp = NULL;
    char str[50];

    fp = fopen(FILENAME, "w");
    if(fp == NULL)
    {
        printf("File doesn't exist");
        return -1;
    }

    //Insert data and write to file
    printf("Nhap du lieu: ");
    scanf("%s", str);
    fprintf(fp, str);

    fclose(fp);
    fp = NULL;
    return 0;
}
