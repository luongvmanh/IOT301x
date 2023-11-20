//Tiền lương của nhân viên.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int id = 0, hour = 0, money = 0, salary = 0;
    printf("ID: ");
    scanf("%u", &id);
    printf("Hours per month: ");
    scanf("%u", &hour);
    printf("Hourly wage: ");
    scanf("%u", &money);
    salary = money * hour;
    printf("ID %u, salary: %u\n", id, salary);
    return 0;
}
