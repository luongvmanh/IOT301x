//Tìm số chẵn.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0;
    printf("Insert number: ");
    scanf("%d", &num);
    for(int i = 1; i <= num; i++){
        if(i % 2 == 0){
            printf("%d ", i);
        }
    }

    return 0;
}
