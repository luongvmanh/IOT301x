#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Thay đổi 1 giá trị của 1 biến(xerox) trong enum và đưa ra màn hình để thấy được sự khác nhau
    enum Company {GOOGLE, FACEBOOK, XEROX=5, YAHOO, EBAY, MICROSOFT};
    enum Company google = GOOGLE;
    enum Company facebook = FACEBOOK;
    enum Company xerox = XEROX;
    enum Company yahoo = YAHOO;
    enum Company ebay = EBAY;
    enum Company microsoft = MICROSOFT;

    printf("The value of google is %d\n", google);
    printf("The value of facebook is %d\n", facebook);
    printf("The value of xerox is %d\n", xerox);
    printf("The value of yahoo is %d\n", yahoo);
    printf("The value of ebay is %d\n", ebay);
    printf("The value of microsoft is %d\n", microsoft);
    return 0;
}
