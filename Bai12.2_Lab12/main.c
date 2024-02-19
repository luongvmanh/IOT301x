#include <stdio.h>
#include <stdlib.h>


struct ngaysinh{
        int ngay;
        int thang;
    };

struct nhanvien
{
    char ten[10];
    int id;
    float luong;
    struct ngaysinh date;
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

    printf("Nhap ngay sinh: ");
    scanf("%d", &nvien.date.ngay);
    printf("Nhap thang sinh: ");
    scanf("%d", &nvien.date.thang);

    printf("Ten: %s", nvien.ten);
    printf("\nID: %d", nvien.id);
    printf("\nLuong: %.2f", nvien.luong);
    printf("\nSinh ngay: %d/%d\n", nvien.date.ngay, nvien.date.thang);
    return 0;
}
