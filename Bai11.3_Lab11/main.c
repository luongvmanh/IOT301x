#include <stdio.h>
#include <stdlib.h>

/*Viết chương trình nhập vào n phần tử 1 mảng và tìm số lớn nhất
bằng cách sử dụng con trỏ.*/

int main()
{
    int arr[100];
    int max = 0;
    int *ptr = arr;
    int num = 0;
    printf("Insert number of items: ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        printf("Insert number: ");
        scanf("%d", (ptr + i));
    }
    max = *ptr;
    for (int i = 1; i < num; i++)
    {
        if(max < *(ptr + i))
        {
            max = *(ptr + i);
        }
    }
    printf("The biggest number is %d.", max);
    return 0;
}
