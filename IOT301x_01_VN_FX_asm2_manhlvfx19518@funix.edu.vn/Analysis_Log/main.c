#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILENAME "log.txt"
#define MAXLENGTHFILE 5000

// Xử lý bản tin dữ liệu cảm biến lưu trữ tại bộ điều khiển trung tâm.

//Prototype
int fileToStr (char *str);
int soBanTinGuiDi(char str[]); //Count numbers of "cmd":"set"
int soBanTinGuiDenThietBi(char str[]); //Count numbers of "cmd":"set" was sent to a device
int soCongTac(char str[]); //Count switches
int soBanTinGuiLoi(char str[]); //Count error messages
int thoiGianTreLonNhat(char str[]); //Find max delay time
int thoiGianTreTrungBinh(char str[]); //Find the everage delay time

int main()
{
    char fileStr[MAXLENGTHFILE];
    fileToStr(fileStr);
    printf("So ban tin: %d\n", soBanTinGuiDi(fileStr));
    printf("-------------------------------\n");
    printf("So ban tin gui di la: %d\n", soBanTinGuiDenThietBi(fileStr));
    printf("-------------------------------\n");
    soCongTac(fileStr);
    printf("-------------------------------\n");
    soBanTinGuiLoi(fileStr);
    printf("-------------------------------\n");
    thoiGianTreLonNhat(fileStr);
    printf("-------------------------------\n");
    thoiGianTreTrungBinh(fileStr);
    printf("-------------------------------\n");

}

//Function to copy content of 'log.txt' to fileStr[]
int fileToStr (char *str)
{
    int status;
    FILE *fp = NULL;

    fp = fopen(FILENAME, "r");
    if(fp == NULL)
    {
        printf("File does not exist\n");
        return -1;
    }
    status = fread(str, MAXLENGTHFILE, 1, fp);

    //printf("Noi dung cua file log.txt: \n%s", str);
    fclose(fp);
    fp = NULL;
    return status;
}


//Câu 1: Tính số bản tin gửi đi trong thời gian log.
//Function to count "cmd":"set"
int soBanTinGuiDi(char str[])
{
    char strCopy[MAXLENGTHFILE];
    strcpy(strCopy, str); //Copy str to a new string before manipulating by strtok()
    //Split fileStr using "\n" new line delimiter.
    char newStr[20][500];
    char *token; //use token for tokenizing
    const char *delimiter = "\n";

    token = strtok(strCopy, delimiter);
    int i = 0;
    while (token != 0)
    {
        strcpy(newStr[i], token); //Save each token to newStr array.
        ++i;
        token = strtok(0, delimiter);
    }

    //Use strstr() to find \"cmd\":\"set\" save in numSet
    char searchStr[] = "\"cmd\":\"set\"";
    int numSet = 0;
    for (int j = 0; j < i; j++)
    {
        char *p = (strstr(newStr[j], searchStr));
        if(p) //if p isn't NULL
        {
            printf("%s\n", newStr[j]);
            numSet++;
        }
    }

    return numSet;
}

//Câu 2:  Tính số bản tin được gửi đến thiết bị cho trước, nhập vào các mã network
//"cmd":"status" and network code
//Function to count numbers of info was sent to device.
int soBanTinGuiDenThietBi(char str[])
{
    char searchStr1[10];
    int num = 0;
    printf("Nhap dia chi cua thiet bi: ");
    scanf("%s", searchStr1);
    //Convert to lowercase
    for (int i = 0; i < strlen(searchStr1); i++){
        searchStr1[i] = tolower(searchStr1[i]);
    }

    char strCopy[MAXLENGTHFILE];
    strcpy(strCopy, str);
    //Split fileStr using "\n" new line delimiter.
    char newStr[20][500];
    char *token = malloc(sizeof(char) * 50); //use token for tokenizing
    const char *delimiter = "\n";

    token = strtok(strCopy, delimiter);
    int i = 0;
    while (token != 0)
    {
        strcpy(newStr[i], token); //Save each token to newStr array.
        ++i;
        token = strtok(0, delimiter);
    }

    //Use strstr() to find \"cmd\":\"set\"
    char searchStr2[] = "\"cmd\":\"set\"";
    for (int j = 0; j < i; j++)
    {
        char *p = strstr(newStr[j], searchStr1);
        char *q = strstr(newStr[j], searchStr2);
        if(p && q) //if p & q isn't NULL
        {
            printf("%s\n", newStr[j]);
            num++;
        }
    }

    return num;
}

//Câu 3: Tính số công tắc có trao đổi thông tin với bộ điều khiển trung tâm trong thời gian Log.
//Function to count numbers of switch.
int soCongTac(char str[])
{
    char data[20][100]; //To save network and endpoint like "data":["zwave-dc53:4-1"]
    char data1[20][100]; //To separate raw and take ["zwave-dc53
    char data2[20][100]; // To take 4-1"]
    char network[4][100]; //To save network
    char endpoint[4][100];//To save endpoint
    char searchStr1[] = "\"type\":\"switch\"";
    char searchStr2[] = "\"cmd\":\"set\"";

    char strCopy[MAXLENGTHFILE];
    strcpy(strCopy, str);
    //Split fileStr using "\n" new line delimiter.
    char newStr[20][500];
    char *token; //use token for tokenizing
    const char *delimiter = "\n";

    token = strtok(strCopy, delimiter);
    int i = 0;
    while (token != 0)
    {
        strcpy(newStr[i], token); //Save each token to newStr array.
        ++i;
        token = strtok(0, delimiter);
    }

    //Use strstr() to find \"cmd\":\"set\" and "\"type\":\"switch\""
    int k = 0;
    for (int j = 0; j < i; j++) //i = 18
    {
        char *p = (strstr(newStr[j], searchStr1));
        char *q = (strstr(newStr[j], searchStr2));
        char *token_data; //Use to tokenize
        if(p && q) //if p & q isn't NULL
        {
            //Using strtok to extract "data":["zwave-dc53:4-1"] and save to data[]
            char *r = strstr(newStr[j], "\"data\""); //Move pointer to "data" then use strok to tokenize
            token_data = strtok(r, ",");
            strcpy(data[k], token_data);
            //printf("%s\n", data[j]);
            k++;
        }

    }

    //Extract network, enpoint from data[].
    int network_length = 0; //Count length of network array
    int endpoint_length = 0; //Count length of endpoint array
    char data3[200];//save network before adding to network[]
    char data4[200];//save endpoint before adding to endpoint[]
    for (int i = 0; i < 9; i++)
    {
        char *token_data1 = strtok(data[i], "-"); //Tokenize using delimiter "-"
                                           //data1[0] = "data":["zwave
        strcpy(data1[i], strtok(NULL, "-"));//data[1] = dc53:4
        strcpy(data2[i], strtok(NULL, "-")); //data[2] = 1"] for example

        strcpy(data3, strtok(data1[i], ":")); //copy network "dc53" to data3
        strcpy(data4, strtok(data2[i], "\""));//copy endpoint "1" to data4

        //Check if it is exist then add to network array.
        int num1 = 0;
        for (int h = 0; h < network_length; h++)
        {

            if(strcmp(network[h], data3) == 0)
            {
                num1++;
                break;
            }
        }

        if (num1 == 0)
        {
            strcpy(network[network_length], data3);
            network_length++;

        }

        //Check if it is exist and add to endpoint array
        int num2 = 0;
        for(int h = 0; h < endpoint_length; h++)
        {
            if(strcmp(endpoint[h], data4) == 0)
            {
                num2++;
                break;
            }
        }
        if(num2 == 0)
        {
            strcpy(endpoint[endpoint_length], data4);
            endpoint_length++;
        }
    }

    //Display results
    for (int i = 0; i < network_length; i++)
    {
        printf("thiet bi %d co dia chi la : NWK - %s, ENDPOINT - %s\n", i + 1, network[i], endpoint);
    }
    return 0;
}


//Câu 4: Tính số bản tin gửi đi bị lỗi, không nhận phản hồi lại.
//Function to count error messages
int soBanTinGuiLoi(char str[])
{
    char strCopy[MAXLENGTHFILE];
    strcpy(strCopy, str);
    //Split fileStr using "\n" new line delimiter.
    char newStr[20][500];
    char *token; //use token for tokenizing
    const char *delimiter = "\n";

    token = strtok(strCopy, delimiter);
    int i = 0;
    while (token != 0)
    {
        strcpy(newStr[i], token); //Save each token to newStr array.
        ++i;
        token = strtok(0, delimiter);
    }

    char reqid1[10][100];
    char reqid2[10][100];
    //Use strstr to move pointer to "reqid" from "reqid": "0001"
    int errNum = 0;
    for (int i = 0; i < 18; i += 2)
    {
        char *p = strstr(newStr[i], "\"reqid\"");
        char *token_reqid1 = strtok(p, ":"); //Split value of requid
        strcpy(reqid1[i], strtok(NULL, ":")); //Take the value like | "0001"|

        char *q = strstr(newStr[i + 1], "\"reqid\"");
        char *token_reqid2 = strtok(q, ":");
        strcpy(reqid2[i + 1], strtok(NULL, ":")); //Take the value like | "0001"|

        //Compare two requids.
        if(strcmp(reqid1[i], reqid2[i + 1]) != 0)
        {
            errNum++;
        }
    }
    printf("So ban tin loi: %d\n", errNum);
    return errNum;
}

//Câu 5: Tính độ trễ lớn nhất giữa bản tin gửi đi và bản tin phản hồi, tính bằng mili giây (ms).
//Function to find maximum delay time
int thoiGianTreLonNhat(char str[])
{
    float delay = 0;
    float maxDelay = 0;
    char strCopy[MAXLENGTHFILE];
    strcpy(strCopy, str);
    //Split fileStr using "\n" new line delimiter.
    char newStr[20][500];
    char *token; //use token for tokenizing
    const char *delimiter = "\n";

    token = strtok(strCopy, delimiter);
    int i = 0;
    while (token != 0)
    {
        strcpy(newStr[i], token); //Save each token to newStr array.
        ++i;
        token = strtok(0, delimiter);
    }

    //Take reqid, if it's not error, count time delay.
    char reqid1[10][100];
    char reqid2[10][100];
    char minute1[10][100];
    char minute2[10][100];
    char second1[10][100];
    char second2[10][100];
    //Use strstr to move pointer to "reqid" from "reqid": "0001"
    for (int i = 0; i < 18; i += 2)
    {
        char *p = strstr(newStr[i], "\"reqid\"");
        char *token_reqid1 = strtok(p, ":"); //Split value of requid
        strcpy(reqid1[i], strtok(NULL, ":")); //Take the value like | "0001"|

        char *q = strstr(newStr[i + 1], "\"reqid\"");
        char *token_reqid2 = strtok(q, ":");
        strcpy(reqid2[i + 1], strtok(NULL, ":")); //Take the value like | "0001"|

        //Compare two requids. If they're the same, count delay
        if(strcmp(reqid1[i], reqid2[i + 1]) == 0)
        {
            //Split time in second
            char *r = strstr(newStr[i], ":"); //The 1st delay time
            strcpy(minute1[i], strtok(r, ":")); //take minutes
            strcpy(second1[i], strtok(NULL, "]")); //take seconds

            char *s = strstr(newStr[i + 1], ":"); //The 2nd delay time
            strcpy(minute2[i + 1], strtok(s, ":"));
            strcpy(second2[i + 1], strtok(NULL, "]"));

            //Cast to integer and take the difference. Convert to float then millisecond
            delay = 60000 * (atof(minute2[i + 1]) - atof(minute1[i])) + 1000 * atof(second2[i + 1]) - 1000* atof(second1[i]);
            if(maxDelay < delay) //Set maxDelay
            {
                maxDelay = delay;
            }
        }
    }
    printf("Do tre lon nhat la : %.f Millisecond\n", maxDelay);
    return maxDelay;
}

//Câu 6: Tính thời gian trễ trung bình trong khoảng thời gian log
//
int thoiGianTreTrungBinh(char str[])
{
    float delay = 0;
    int sum = 0; //sum of delay time
    int num = 0; //numbers of delay time
    int average = 0; //thoi gian tre trung binh

    char strCopy[MAXLENGTHFILE];
    strcpy(strCopy, str);
    //Split fileStr using "\n" new line delimiter.
    char newStr[20][500];
    char *token; //use token for tokenizing
    const char *delimiter = "\n";

    token = strtok(strCopy, delimiter);
    int i = 0;
    while (token != 0)
    {
        strcpy(newStr[i], token); //Save each token to newStr array.
        ++i;
        token = strtok(0, delimiter);
    }

    //Take reqid, if it's not error, count time delay.
    char reqid1[10][100];
    char reqid2[10][100];
    char minute1[10][100];
    char minute2[10][100];
    char second1[10][100];
    char second2[10][100];
    //Use strstr to move pointer to "reqid" from "reqid": "0001"
    for (int i = 0; i < 18; i += 2)
    {
        char *p = strstr(newStr[i], "\"reqid\"");
        char *token_reqid1 = strtok(p, ":"); //Split value of requid
        strcpy(reqid1[i], strtok(NULL, ":")); //Take the value like | "0001"|

        char *q = strstr(newStr[i + 1], "\"reqid\"");
        char *token_reqid2 = strtok(q, ":");
        strcpy(reqid2[i + 1], strtok(NULL, ":")); //Take the value like | "0001"|

        //Compare two requids. If they're the same, count delay
        if(strcmp(reqid1[i], reqid2[i + 1]) == 0)
        {
            //Split time in second
            char *r = strstr(newStr[i], ":"); //The 1st delay time
            strcpy(minute1[i], strtok(r, ":")); //take minutes
            strcpy(second1[i], strtok(NULL, "]")); //take seconds

            char *s = strstr(newStr[i + 1], ":"); //The 2nd delay time
            strcpy(minute2[i + 1], strtok(s, ":"));
            strcpy(second2[i + 1], strtok(NULL, "]"));

            //Cast to integer and take the difference. Convert to float then millisecond
            delay = 60000 * (atof(minute2[i + 1]) - atof(minute1[i])) + 1000 * atof(second2[i + 1]) - 1000* atof(second1[i]);
            sum += delay;
            num ++;
        }
    }
    average = sum/num;
    printf("Do tre trung binh la : %d Millisecond\n", average);
    return average;
}
