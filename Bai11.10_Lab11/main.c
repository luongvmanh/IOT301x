#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Thực hiện trích xuất và thống kê số lượng khách hàng là nam giới dựa vào dữ liệu JSON.


//Prototype
void extract_JSON(char jSON[], char hoten[], char gioitinh[], char sodienthoai[], char email[]);
char *multi_tok(char *input, char *delimiter);

int main()
{
    char jSON[] = "[{\"hoten\":\"Le Thi My Duyen\",\"gioitinh\":\"nu\",\"sodienthoai\":\"0935777888\",\"email\":\"duyen86@gmail.com\"},{\"hoten\":\"Tran Trung Thanh\",\"gioitinh\":\"nam\",\"sodienthoai\":\"976333444\",\"email\":\"thanhtt95@gmail.com\"},{\"hoten\":\"Huynh Anh Hoang\",\"gioitinh\":\"nu\",\"sodienthoai\":\"0939745220\",\"email\":\"hahoang88@gmail.com\"},{\"hoten\":\"Nguyen Minh Khoi\",\"gioitinh\":\"nam\",\"sodienthoai\":\"0703666777\",\"email\":\"khoimaster@gmail.com\"}]";
    char hoten[100], gioitinh[100], sodienthoai[100], email[100];
    char khachhang[500];
    char hoten_nam[10][100];
    int s1_nam = 0;
    int s1_khachhang = 0;
    int i = 0;
    char *token = multi_tok(jSON, "},{");
    while (token != NULL)
    {
        strcpy(khachhang, token);
        extract_JSON(khachhang, hoten, gioitinh, sodienthoai, email);
        if(strcmp(gioitinh, "\"nam\"")== 0)
        {
            strcpy(hoten_nam[i], hoten);
            s1_nam++;
            i++;
        }
        s1_khachhang++;
        token = multi_tok(NULL, "},{");
    }
    printf("Co tong cong %d khach hang Nam/tong so %d khach hang\n", s1_nam, s1_khachhang);
    if(s1_nam > 0)
    {
        printf("Ho ten cac khach hang Nam: \n");
        for(i = 0; i < s1_nam; ++i)
        {
            printf("%d. %s\n", i + 1, hoten_nam[i]);
        }
    }
    return 0;
}


//Create a function for tokenizing
void extract_JSON(char jSON[], char hoten[], char gioitinh[], char sodienthoai[], char email[])
{
    //Mang info luu thong tin khach hang gom hoten, gioitinh, sodienthoai, email
    //info[0] = khachhang[0]
    //info[1] = khachhang[1]
    //info[2] = khachhang[2]
    //info[3] = khachhang[3]
    char info[10][100];
    int i;

    //Cat chuoi khachhang[i] theo dau ','
    char *token = strtok(jSON, ",");

    i = 0;
    while(token != NULL)
    {
        strcpy(info[i], token);
        ++i;
        token = strtok(NULL, ",");
    }

    //Trich xuat hoten tu array khachhang[].
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


//Create function to extract string with 3 delimiters
char *multi_tok(char *input, char *delimiter)
{
    static char *string;
    if (input != NULL)
    {
        string = input; //set string = current position of input string
    }
    if(string == NULL)  //reach the end of string.
    {
        return string;
    }
    char *end = strstr(string, delimiter); //end point to the first delimiter in string
    if (end == NULL){  //There isn't any delimiter.
        char *temp = string; //a temperary point to string before setting string = NULL, if not we don't know where the string is in memmory.
        string = NULL;
        return temp;
    }

    char *temp = string;

    *end = '\0'; //Treat token as a C string
    string = end + strlen(delimiter); //Start splitting up the input string from the point after the current token. get over 3 characters '},{'
    return temp; //Return pointer to current token.
}
