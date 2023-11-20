#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Viết chương trình sắp xếp các chuỗi nhập vào theo thứ tự abc sử dụng thuật toán nổi bọt.
//Chuỗi nhập vào phải có dấu cách.
int main()
{
    int row = 0; //number of strings.
    int col = 20; //string length.
    printf("Nhap so luong chuoi can sap xep: ");
    scanf("%d", &row);
    fflush(stdin); //Xóa bộ nhớ đệm do scanf tạo ra sau khi bấm enter
    char insertStr[row][col];
    //Nhap vao cac chuoi ky tu
    for (int i = 0; i < row; i++){
        printf("Nhap chuoi ky tu: ");
        //scanf("%s", insertStr[i]);
        fgets(insertStr[i], sizeof(insertStr), stdin); //Taking string input with space
        printf("%s\n", insertStr[i]);
    }

    //Sap xep cac chuoi theo bubble sort
    char temp[20]; //Mảng tạm thời dùng làm trung gian để đổi chỗ hai chuỗi
    for(int i = 1; i <= row; i++){
        for(int j = 0; j < row - i; j++){
            if(strcmp(insertStr[j], insertStr[j + 1]) > 0){ //So sánh các chuỗi và đổi thứ tự theo bubble sort.
            strcpy(temp, insertStr[j]);
            strcpy(insertStr[j], insertStr[j + 1]);
            strcpy(insertStr[j + 1], temp);
            }
        }
    }

    //Hien thi chuoi moi
    printf("Chuoi sau sap xep: \n");
    for (int i = 0; i < row; i++){
        printf("%s\n", insertStr[i]);
    }

    return 0;
}
