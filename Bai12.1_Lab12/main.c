#include <stdio.h>
#include <stdlib.h>

struct nhanvien
{
    char ten[10];
    int id;
    float luong;
};


int main()
{
    struct nhanvien nvien;
    printf("Nhap ten: ");
    scanf("%s", nvien.ten);

    printf("Nhap ID: ");
    scanf("%d", &nvien.id);

    printf("Nhap luong: ");
    scanf("%f", &nvien.luong);

    printf("Ten: %s", nvien.ten);
    printf("\nID: %d", nvien.id);
    printf("\nLuong: %.2f", nvien.luong);
    return 0;
}
