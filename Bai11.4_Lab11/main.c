#include <stdio.h>
#include <stdlib.h>

//Tìm kiếm phần tử của mảng bằng cách sử dụng con trỏ.
//Prototype
void search_num(int *ptr, int *search);

int main()
{
    int arr[5] = {5, 3, 6, 0, 9};
    int num = 0;
    int *ptr = arr; //Pointer points to array
    int *search = &num; //Poiter points to the item is looking for.
    search_num(ptr, search);
    return 0;
}

//Create a function to search
void search_num(int *ptr, int *search)
{
    int i, j = 0;
    for (i = 0; i < 5; i++)
    {
        if(*(ptr + i) == *search)
        {
            j = 1;
            break;
        }
    }
    if(j == 1)
    {
        printf("The item found");
    }
    else
    {
        printf("Not found");
    }

}
