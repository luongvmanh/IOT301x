#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    printf("Nhap so thu nhat: ");
    scanf("%d", &a);
    printf("Nhap so thu hai: ");
    scanf("%d", &b);

    int *pnum1 = &a, *pnum2 = &b;
    if(*pnum1 < *pnum2){
        printf("So lon nhat la: %d\n", *pnum2);
    }
    else if(*pnum1 > *pnum2){
        printf("So lon nhat la: %d\n", *pnum1);
    }
    else{
        printf("Hai so bang nhau\n");
    }

    return 0;
}
