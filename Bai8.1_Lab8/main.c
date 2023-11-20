//Luyện tập tạo hàm.
#include <stdio.h>
#include <stdlib.h>
int gCD(int a, int b); //Great common divisor_ước chung lớn nhất của hai số không âm.
float absoluteValue(float num);  // Giá trị tuyệt đối
int factorial(int n); // Tính giai thừa.
float distance(float x1, float y1, float x2, float y2);  //Tính khoảng cách hai điểm A(Ax, Ay) và B(Bx, By) trong tọa độ Oxy.

/*UCLN: The Algorithm: the GCD of two numbers doesn’t change
if the smaller number is subtracted from the bigger number.
The Euclidean Algorithm for finding GCD(A,B) is as follows:
If A = 0 then GCD(A,B)=B, since the GCD(0,B)=B, and we can stop.
If B = 0 then GCD(A,B)=A, since the GCD(A,0)=A, and we can stop.
Write A in quotient remainder form (A = B*Q + R)
Find GCD(B,R) using the Euclidean Algorithm since GCD(A,B) = GCD(B,R);
*/

int gCD(int a, int b){
    if(a == 0){
        return b;
    }
    if(b == 0){
        return a;
    }

    int r;
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}


float absoluteValue(float num){
    if (num < 0){
        return -num;
    }
        return num;
}



int factorial(int n){
    if(n == 1){
        return 1;
    } else{
        return n*factorial(n - 1); //Recursion
    }

}


float distance(float x1, float y1, float x2, float y2){   //A(x1, y1), B(x2, y2) => ab = sqrt((x2-x1)^2 + (y2-y1)^2).
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}


int main()
{
    int ucln = gCD(98, 56);
    printf("The great number is %d\n", ucln);
    float abso = absoluteValue(-83);
    printf("The absolute value is %f\n", abso);
    int f = factorial(5);
    printf("Factorial is %d\n", f);
    float khoang_cach = distance(5, 7, 9, 23);
    printf("The distance is %f\n", khoang_cach);
    return 0;
}
