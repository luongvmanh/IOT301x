// Tính tiền phải trả hàng tuần
/* Lương net (netPay) = Lương gross - (BHXH + BHYT + BHTN) - Thuế TNCN (nếu có) */
#include <stdio.h>
#include <stdlib.h>
#define PAYRATE 12.00 // 12$/hour
#define TAXRATE_300 0.15 // 15%
#define TAXRATE_450 0.20 // 20%
#define TAXRATE_REST 0.25 // 25%
#define OVERTIME 40 //hour

int main()
{
    //declare varibles
    unsigned int hour = 0;
    double grossPay = 0.0;
    double netPay = 0.0;
    double overTimePay = 0.0;
    double tax = 0.0;

    //Insert hours
    printf("Insert hours: ");
    scanf("%d", &hour);

    //Count grossPay
    if (hour <= 40){
        grossPay = hour * PAYRATE;
    } else if(hour > 40){
        grossPay = hour * PAYRATE;
        overTimePay = (hour - 40) * 1.5 * PAYRATE;
        grossPay += overTimePay;
    }

    //Count Taxes
    if (grossPay <= 300){
        tax = grossPay * TAXRATE_300;
    } else if (grossPay > 300 && grossPay <= 450) {
        tax = 300 * TAXRATE_300;
        tax += (grossPay - 300) * TAXRATE_450;
    } else if (grossPay > 450){
        tax = 300 * TAXRATE_300 + 150 * TAXRATE_450;
        tax += (grossPay - 450) * TAXRATE_REST;
    }

    //Count netPay
    netPay = grossPay - tax;

    printf("Your gross pay this week is %.2lf\n", grossPay);
    printf("Your taxes this week is %.2lf\n", tax);
    printf("Your net pay this week is %.2lf\n", netPay);
    return 0;
}
