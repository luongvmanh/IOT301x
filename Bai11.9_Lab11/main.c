#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Thực hiện trích xuất và hiển thị thông tin từ một đối tượng JSON.
//{"hoten":"Le Thi My Duyen","gioitinh":"nu","sodienthoai":"0935777888","email":"duyen86@gmail.com"}

//Prototype
void extract_JSON(char jSON[], char hoten[], char gioitinh[], char sodienthoai[], char email[]);

int main()
{
    char jSON[] = "{\"hoten\":\"Le Thi My Duyen\",\"gioitinh\":\"nu\",\"sodienthoai\":\"0935777888\",\"email\":\"duyen86@gmail.com\"}";
    char hoten[30], gioitinh[30], sodienthoai[30], email[30];
    extract_JSON(jSON, hoten, gioitinh, sodienthoai, email);
    printf("Thong tin cua doi tuong JSON: \n");
    printf("Ho ten: %s", hoten);
    printf("\nGioi tinh: %s", gioitinh);
    printf("\nSo dien thoai: %s", sodienthoai);
    printf("\nEmail: %s", email);
    return 0;
}


//Create a function for tokenizing
void extract_JSON(char jSON[], char hoten[], char gioitinh[], char sodienthoai[], char email[])
{
    //Mang info luu thong tin hoten, gioitinh, sodienthoai, email
    //info[0] = "hoten":"Le Thi My Duyen"
    //info[1] = "gioitinh":"nu"
    //info[2] = "sodienthoai":"0935777888"
    //info[3] = "email":"duyen86@gmail.com"
    char info[4][100];
    int i;

    //Cat chuoi theo dau ','
    char *token = strtok(jSON, ",");

    i = 0;
    while(token != NULL)
    {
        strcpy(info[i], token);
        ++i;
        token = strtok(NULL, ",");
    }

    //Trich xuat hoten
    char delimiter[2] = ":";
    char *hoten_token = strtok(info[0], delimiter);
    //hoten_token[0] = {"hoten"
    //hoten_token[1] = "Le Thi My Duyen"
    strcpy(hoten, strtok(NULL, delimiter)); //Copy the second token

    //Trich xuat gioitinh
    char *gioitinh_token = strtok(info[1], delimiter);
    //gioitinh_token[0] = "gioitinh"
    //gioitinh_token[1] = "nu"
    strcpy(gioitinh, strtok(NULL, delimiter));

    //Trich xuat so dien thoai
    char *sodienthoai_token = strtok(info[2], delimiter);
    //sodienthoai_token[0] = "sodienthoai"
    //sodienthoai_token[1] = "0935777888"
    strcpy(sodienthoai, strtok(NULL, delimiter));

    //Trich xuat email
    char *email_token = strtok(info[3], delimiter);
    //email_token[0] = "email"
    //email_token[1] = "duyen86@gmail.com"}
    strcpy(email, strtok(NULL, delimiter));

    //Xoa dau '}' o cuoi email
    if (email[strlen(email) - 1] == '}')
    {
        email[strlen(email) - 1] = '\0';
    }
}
