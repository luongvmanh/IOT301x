#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


//Viết chương trình nhập vào 2 chuỗi: chuỗi và chuỗi con.
//Kiểm tra chuỗi con có xuất hiện trong chuỗi hay không.

int main()
{
    //Tao va nhap vao 2 chuoi
    char mainStr[100]; //Chuỗi chính
    char subStr[20];   //Chuỗi con
    printf("Nhap chuoi thu nhat: ");
    scanf("%s", mainStr);
    printf("Nhap chuoi thu hai: ");
    scanf("%s", subStr);

    //Dem ky tu cac chuoi
    int count1 = strlen(mainStr); //Ky tu mainStr
    int count2 = strlen(subStr); //Ky tu subStr

    //Tien hanh kiem tra
    int i, j, check;
    for(i = 0; i <= count1 - count2; i++) //Khi phan chuoi to con lai < chuoi nho thi ngung kiem tra(count 1 - count2)
    {
        for (j = i; j < i + count2; j++)
        {
            check = 1;c
            if(mainStr[j] != subStr[j - i]) //So sanh ky tu trong chuoi chinh voi ky tu dau tien cua chuoi con,neu dung thi so sanh tiep
            {
                check = 0;
                break;
            }
        }
        if(check == 1){ //After compare all the character in the substring
            break;
        }
    }

    if(check == 1)
    {
        printf("Chuoi con xuat hien trong chuoi.\n");
    }
    else
    {
       printf("Chuoi con khong xuat hien trong chuoi\n");
    }
    return 0;
}
