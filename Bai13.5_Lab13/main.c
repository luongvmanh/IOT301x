#include <stdio.h>
#include <stdlib.h>

//Viết chương trình đổi tên và xóa file từ ổ đĩa.

int main()
{
    char oldName[20];
    char newName[20];
    char temp[20];
    printf("Insert filename to change: ");
    scanf("%s", oldName);
    printf("Insert new filename: ");
    scanf("%s", newName);
    int returnValue = rename(oldName, newName);
    if(!returnValue) //0 means succeed. if(returnValue == 0)
    {
        printf("Change successful\n");
    }
    else
    {
        perror("Error\n");
    }
    //Remove file
    printf("Insert filename to delete: ");
    scanf("%s", temp);
    int rem = remove(temp);
    if(rem == 0)
    {
        printf("File deleted successfully");
    }
    else{
        perror("Error");
    }

    return 0;
}
