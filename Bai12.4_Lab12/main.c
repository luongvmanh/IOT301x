#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Viết chương trình quản lý học sinh trong một lớp với cấu trúc bao gồm: họ và
tên, tuổi, địa chỉ, điểm trung bình tích lũy GPA.*/

struct hocsinh{
    char hoten[25];
    int tuoi;
    char diachi[128];
    float gpa;
};

int main()
{
    struct hocsinh thongtin[100];
    int num; //Number to choose
    int n; //So luong hoc sinh
    int i;
    char name[20]; //Ten hoc sinh can tim kiem
    while(1)
    {
        printf("\nHay lua chon:\n");
        printf("1. Nhap thong tin hoc sinh\n");
        printf("2. Tim kiem hoc sinh\n");
        printf("3. Thoat\n");
        scanf("%d", &num);
        printf("\n----------------------\n");

        //check number
        //If number = 1, add info into array thongtin[]
        if(num == 1){
            printf("Nhap so luong hoc sinh: ");
            scanf("%d", &n);
            for(i = 0; i < n; i++)
            {
                printf("Nhap ten hoc sinh so %d: ", i + 1);
                scanf("%s", thongtin[i].hoten);
                printf("\nNhap tuoi: ");
                scanf("%d", &thongtin[i].tuoi);
                printf("\nNhap dia chi: ");
                scanf("%s", thongtin[i].diachi);
                printf("\nNhap GPA: ");
                scanf("%f", &thongtin[i].gpa);
            }
        }
        else if(num == 2)
        {
            printf("Nhap ten hoc sinh can tim: ");
            scanf("%s", name);
            for(i = 0; i < n; i++)
            {
                if (strcmp(thongtin[i].hoten, name) == 0)
                {
                    printf("Thong tin hoc sinh la: \n");
                    printf("Ten: %s", thongtin[i].hoten);
                    printf("\nTuoi: %d", thongtin[i].tuoi);
                    printf("\nDia chi: %s", thongtin[i].diachi);
                    printf("\nGPA: %.2f", thongtin[i].gpa);
                    break;
                }

            }
            if(i == n)
            {
                printf("Khong tim thay hoc sinh");
            }
        }
        else if (num == 3)
        {
            break;
        }
        else {
            printf("Lua chon khong hop le");
        }


    }
//    for(i = 0; i < n; i++)
//    {
//        printf("Thong tin hoc sinh la: \n");
//        printf("%s\n", thongtin[i].hoten);
//        printf("%d\n", thongtin[i].tuoi);
//        printf("%s\n", thongtin[i].diachi);
//        printf("%.2f\n", thongtin[i].gpa);
//    }

    return 0;
}
