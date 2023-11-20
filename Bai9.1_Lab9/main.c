#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Prototypes
int lengthStr(char str[]);
void concatStr(char arr[], char dest[], char src[]);
bool analyzeStr(char name1[], char name2[]);

//Tạo hàm tính độ dài chuỗi, hàm nối 2 chuỗi và hàm kiểm tra 2 chuỗi.
int main()
{
    char str[] = "How have you been up to?";
    printf("The length of this array is: ");
    lengthStr(str);
    char dest[] = "\nThis is ";
    char src[] = "a good movie.";
    char array[100];
    concatStr(array, dest, src);

    char name_1[] = "xin chao";
    char name_2[] = "xin chao.";
    if(analyzeStr(name_1, name_2) == true){
        printf("Two strings are the same.\n");
    }else{
        printf("Two strings are different.\n");
    }

    return 0;
}


//Ham tinh do dai chuoi
int lengthStr(char str[])
{
    int i = 0;
    int count = 0; //To count characters
    while(str[i] != '\0'){
        count++;
        i++;
    }
    printf("%d\n", count);
    return 0;
}

//Ham noi chuoi
void concatStr(char arr[], char dest[], char src[])
{
    int leng_1 = strlen(dest);
    for (int i = 0; i < leng_1; i++){ //Nhap chuoi thu nhat vao mang
        arr[i] = dest[i];
    }
    int leng_2 = strlen(dest) + strlen(src); //length of both strings in combination
    int j = 0;
    for (int i = leng_1; i < leng_2; i++){   //Nhap chuoi thu hai vao mang
        arr[i] = src[j];
        j++;
    }
    printf("%s\n", arr);
    return;
}

//Kiem tra chuoi
bool analyzeStr(char name_1[], char name_2[]){
    int i = 0;
    while(name_1[i] != '\0' || name_2[i] != '\0'){
        if(name_1[i] == name_2[i]){
            i++;
        } else{
            break;
        }


    }
    if(name_1[i] == '\0' && name_2[i] == '\0'){
        return true;
    }
    return false;
}
