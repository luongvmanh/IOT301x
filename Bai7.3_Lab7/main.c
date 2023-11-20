//Tìm số nguyên tố.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[30] = {2, 3};
    int count = 2;

    //check from 4 - 100.
    for (int i = 4; i <= 100; i++){
        if(i % 2 != 0){                 //If number is odd.
            int notDivisible = 0;
            for(int j = 0; j < count; j++){   //devide by all previous prime numbers.
                if(i % arr[j] == 0){          //if divisible by any number, check next odd number
                    break;
                }
                else{
                    notDivisible ++;          //count how many times it is not divisible
                    continue;
                }
            }
            if(notDivisible == count){        //if it's not divisible, so it's a prime, add to array.
                arr[count] = i;
                count++;
            }
        }
    }

    //Print prime number
    for (int i = 0; i < count; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
