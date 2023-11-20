#include <stdio.h>
#include <stdlib.h>

/*
* Nhap ten va hien thi loi chao
*/
int main()
{
    char name[32];                  //Tao mang kieu char 32 phan tu de luu ten
    printf("What's your name: ");
    scanf("%s", name);              //Luu ten nhap tu ban phim vao name
    printf("\nHello %s. How are you?", name);
    return 0;
}
