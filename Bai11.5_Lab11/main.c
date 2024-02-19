#include <stdio.h>
#include <stdlib.h>

//Viết chương trình hoán đổi 2 mảng bằng cách sử dụng con trỏ.
//Prototype
void swap(int arr1[], int arr2[]);

int main()
{
    int arr1[10] = {5, 3, 6, 0, 9, 4};
    int arr2[10] = {1, 5, 8};
    swap(arr1, arr2);
    return 0;
}

//Create a function to swap
void swap(int arr1[], int arr2[])
{
    int *ptr1 = arr1;
    int *ptr2 = arr2;
    int i, j, k;
    int temp[10];

    //Swap three items.
    for (i = 0; i < 3; i++)
    {
        temp[i] = *(ptr1 + i);
        *(ptr1 + i) = *(ptr2 + i);
        *(ptr2 + i) = temp[i];
    }
    //Display two new arrays
    printf("New array 1 is: ");
    for(j = 0; j < 6; j++)
    {
        printf("%d", *(ptr1 + j));
    }

    printf("\nNew array 2 is: ");
    for(k = 0; k < 3; k++)
    {
        printf("%d", *(ptr2 + k));
    }
}
