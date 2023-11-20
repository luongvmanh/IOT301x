//Hiển thị các phần tử trong mảng theo thứ tự ngược.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[10] = {3, 5, 1, 12, 6, 2, 34, 23, 9, 18};
    for(int i = 9; i >= 0; i--){
        printf("%d ", arr[i]);
    }
    return 0;
}
