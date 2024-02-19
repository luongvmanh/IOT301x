#include <stdio.h>
#include <stdlib.h>

#define max 10000

//Concatenate data from two files

int main()
{
    FILE *fp1 = NULL, *fp2 = NULL, *newfp = NULL;
    char str1[max];
    char str2[max];
    char newstr[max];
    //Open text1.txt and text2.txt in read mode
    fp1 = fopen("text1.txt", "r");
    if(fp1 == NULL)
    {
        printf("Couldn't open text1");
        return -1;
    }

    fp2 = fopen("text2.txt", "r");
    if(fp2 == NULL)
    {
        printf("Couldn't open text2");
        return -1;
    }
    //Opent newText.txt in write mode
    newfp = fopen("newText.txt", "w+");
    if(newfp == NULL)
    {
        printf("Couldn't open newText");
        return -1;
    }

    //Copy text1 to newText
    while(fgets(str1, max, fp1) != NULL)
    {
        fputs(str1, newfp);

    }
    fclose(fp1);
    fp1 = NULL;

    //Copy text2 to newText
    while(fgets(str2, max, fp2) != NULL)
    {
        fputs(str2, newfp);

    }
    fclose(fp2);
    fp2 = NULL;

    //Print newText.txt
    rewind(newfp);
    while(fgets(newstr, max, newfp) != NULL)
    {
        printf("%s", newstr);
    }
    fclose(newfp);
    newfp = NULL;

    return 0;
}
