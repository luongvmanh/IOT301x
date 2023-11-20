//Sắp xếp dãy số.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    int arr[101];

    //Insert number > 0.
    do{
        printf("Insert quantity: ");
        scanf("%d", &n);
    } while(n <= 0);

    //Insert elements to array arr.
    for (int i = 0; i < n; i++){
        printf("Please insert number: ");
        scanf("%d", &arr[i]);
    }

    //put number in descending order.
    for(int k = 0; k < n; k++){
        for(int h = k + 1; h < n; h++){
            if(arr[k] < arr[h]){
                int temp = arr[k];
                arr[k] = arr[h];
                arr[h] = temp;
            }
        }
    }

    //Display the new array.
    for (int i = 0; i < n; i++){
        printf("%2d", arr[i]);
    }
    printf("\n");
    //put number in ascending order.
    for(int k = 0; k < n; k++){
        for(int h = k + 1; h < n; h++){
            if(arr[k] > arr[h]){
                int temp = arr[k];
                arr[k] = arr[h];
                arr[h] = temp;
            }
        }
    }

    //Display the new array.
    for (int i = 0; i < n; i++){
        printf("%2d", arr[i]);
    }
    return 0;
}
