#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159
//prototype
bool kiemtra_tamgiac(
    float Ax, float Ay,
    float Bx, float By,
    float Cx, float Cy);

float goccanh_tamgiac(
    float Ax, float Ay,
    float Bx, float By,
    float Cx, float Cy);

float xet_tamgiac(
    float Ax, float Ay,
    float Bx, float By,
    float Cx, float Cy);

float dientich_tamgiac(
    float Ax, float Ay,
    float Bx, float By,
    float Cx, float Cy);

float duongcao_tamgiac(
    float Ax, float Ay,
    float Bx, float By,
    float Cx, float Cy);

float trungtuyen_tamgiac(
    float Ax, float Ay,
    float Bx, float By,
    float Cx, float Cy);

float tam_tamgiac(
    float Ax, float Ay,
    float Bx, float By,
    float Cx, float Cy);

float giaima_tamgiac(
    float Ax, float Ay,
    float Bx, float By,
    float Cx, float Cy);


//Khai bao mang
float Ax, Ay, Bx, By, Cx, Cy; //Toa độ 3 diem A, B, C
float toa_do[6]; //Tọa độ của 3 điểm A, B, C ở hệ trục tọa độ Oxy dạng {Ax, Ay, Bx, By, Cx, Cy}
float a = 0, b = 0, c = 0; //Do dai cac canh
float A = 0, B = 0, C = 0; //Cac goc tam giac
float goc_canh[6];
float dienTich = 0, p = 0; //Dien tich, chu vi tam giac
float dcA = 0, dcB = 0, dcC = 0; //duong cao tu dinh A, B, C.
float duong_cao[3];
float mA = 0, mB = 0, mC = 0; //duong trung tuyen tu dinh A, B, C.
float trung_tuyen[3];
float trongtam_x = 0, trongtam_y = 0;
float trong_tam[2];


int main()
{
    giaima_tamgiac(Ax, Ay, Bx, By, Cx, Cy);

    return 1;
}


//1. ABC có phải tam giác không?
bool kiemtra_tamgiac(
    float Ax, float Ay,
    float Bx, float By,
    float Cx, float Cy)
{

    //Tinh chieu dai cac canh
    a = sqrt((Cx - Bx)*(Cx - Bx) + (Cy - By)*(Cy - By)); //canh BC
    b = sqrt((Ax - Cx)*(Ax - Cx) + (Ay - Cy)*(Ay - Cy)); //canh CA
    c = sqrt((Bx - Ax)*(Bx - Ax) + (By - Ay)*(By - Ay)); //cạnh AB
    goc_canh[0] = a;
    goc_canh[1] = b;
    goc_canh[2] = c;

    //so sánh tổng hai cạnh với cạnh còn lại
    if(a + b > c && b + c > a && a + c > b){
        return true;
    }
    return false;
}

//2. Tính góc, cạnh tam giác
float goccanh_tamgiac(
    float Ax, float Ay,
    float Bx, float By,
    float Cx, float Cy)
{

    //Chieu dai cac canh duoc tinh trong ham kiemtra_tamgiac va luu vao a, b, c
    printf("\tChieu dai canh AB: %.2f\n", c);
    printf("\tChieu dai canh BC: %.2f\n", a);
    printf("\tChieu dai canh CA: %.2f\n", b);

    //Tinh cac goc

    A = (180/PI)* acos((b*b + c*c - a*a)/(2*b*c));
    B = (180/PI)* acos((a*a + c*c - b*b)/(2*a*c));//Tìm cosin góc sau đó dùng hàm acos() để lấy giá trị góc ở dạng radian, đổi sang độ
    C = 180 - (A + B);
    goc_canh[3] = A;
    goc_canh[4] = B;
    goc_canh[5] = C;
    printf("\tGoc A: %.2f\n", A);
    printf("\tGoc B: %.2f\n", B);
    printf("\tGoc C: %.2f\n", C);
    return 1;
}

//3. Tam giác ABC là tam giác nhọn, tam giác vuông hay tam giác tù, tại đỉnh nào.
//Tam giác bình thường, tam giác cân hay tam giác đều, tại đỉnh nào.
float xet_tamgiac(
    float Ax, float Ay,
    float Bx, float By,
    float Cx, float Cy)
{

    //Tam giac deu
    if(abs(a - b) < 1e-9 && abs(b - c) < 1e-9){ //Check if 2 floats value are equal or not. Can use == to compare float values.
        printf("Tam giac ABC la tam giac deu.\n");
    }
    else if(abs(a - b) < 1e-9 && (int)C == 90){ //Tam giac vuong can
        printf("Tam giac ABC la tam giac vuong can tai C.\n");
    }
    else if(abs(a - c) < 1e-9 && (int)B == 90){ //a == c and B == 90
        printf("Tam giac ABC la tam giac vuong can tai B.\n");
    }
    else if(abs(b - c) < 1e-9 && (int)A == 90){
        printf("Tam giac ABC la tam giac vuong can tai A.\n");
    }
    else if(abs(b - c) < 1e-9 && A > 90){//Tam giac can va tu
        printf("Tam giac ABC la tam giac can va tu tai A.\n");
    }
    else if(abs(a - c) < 1e-9 && B > 90){
        printf("Tam giac ABC la tam giac can va tu tai B.\n");
    }
    else if(abs(a - b) < 1e-9 && C > 90){
        printf("Tam giac ABC la tam giac can va tu tai C.\n");
    }
    else if (abs(a - b) < 1e-9){ //Tam giac can
        printf("Tam giac ABC la tam giac can tai C.\n");
    }
    else if (abs(b - c) < 1e-9){
        printf("Tam giac ABC la tam giac can tai A.\n");
    }
    else if (abs(a - c) < 1e-9){
        printf("Tam giac ABC la tam giac can tai B.\n");
    }
    else if ((int)A == 90){ //Tam giac vuong
        printf("Tam giac ABC la tam giac vuong tai A.\n");
    }
    else if((int)B == 90){
        printf("Tam giac ABC la tam giac vuong tai B.\n");
    }
    else if((int)C == 90){
        printf("Tam giac ABC la tam giac vuong tai C.\n");
    }
    else if(A > 90){ //Tam giac tu
        printf("Tam giac ABC la tam giac tu tai A.\n");
    }
    else if(B > 90){
        printf("Tam giac ABC la tam giac tu tai B.\n");
    }
    else if(C > 90){
        printf("Tam giac ABC la tam giac tu tai C.\n");
    }
    else if(A < 90 && B < 90 && C < 90){ //Tam giac nhon
        printf("Tam giac ABC la tam giac nhon.\n");
    }
    else{ //Tam giac thuong
        printf("Tam giac ABC la tam giac binh thuong.\n");
    }

    return 1;
}

//4. Dien tich tam giac
float dientich_tamgiac(
    float Ax, float Ay,
    float Bx, float By,
    float Cx, float Cy)
{
    p = (a + b + c)/2;
    dienTich = sqrt(p*(p - a)*(p - b)*(p - c));
    printf("%.2f\n", dienTich);

    return 1;
}

//5.Duong cao tam giac
float duongcao_tamgiac(
    float Ax, float Ay,
    float Bx, float By,
    float Cx, float Cy)
{

    dcA = (2*dienTich)/a;
    duong_cao[0] = dcA;
    dcB = (2*dienTich)/b;
    duong_cao[1] = dcB;
    dcC = (2*dienTich)/c;
    duong_cao[2] = dcC;
    printf("Do dai duong cao tu dinh A: %.2f\n", dcA);
    printf("Do dai duong cao tu dinh B: %.2f\n", dcB);
    printf("Do dai duong cao tu dinh C: %.2f\n", dcC);

    return 1;
}

//6. Trung tuyen tam giac
float trungtuyen_tamgiac(
    float Ax, float Ay,
    float Bx, float By,
    float Cx, float Cy)
{
    mA = sqrt((b*b + c*c)/2 - a*a/4);
    trung_tuyen[0] = mA;
    mB = sqrt((a*a + c*c)/2 - b*b/4);
    trung_tuyen[1] = mB;
    mC = sqrt((b*b + a*a)/2 - c*c/4);
    trung_tuyen[2] = mC;
    printf("Do dai trung tuyen tu dinh A: %.2f\n", mA);
    printf("Do dai trung tuyen tu dinh B: %.2f\n", mB);
    printf("Do dai trung tuyen tu dinh C: %.2f\n", mC);

    return 1;
}

//7. Trọng tâm tam giác
float tam_tamgiac(
    float Ax, float Ay,
    float Bx, float By,
    float Cx, float Cy)
{
    trongtam_x = (Ax + Bx + Cx)/3;
    trong_tam[0] = trongtam_x;
    trongtam_y = (Ay + By + Cy)/3;
    trong_tam[1] = trongtam_y;
    printf("Toa do trong tam: [%.2f, %.2f]\n", trongtam_x, trongtam_y);

    return 1;
}

//8. Giải mã tam giác
float giaima_tamgiac(
    float Ax, float Ay,
    float Bx, float By,
    float Cx, float Cy)
{
    //Nhập tọa độ các điểm
    do{
        printf("Nhap toa do diem A: \n");
        printf("Ax: ");
        scanf("%f", &Ax);
        printf("\n");
        toa_do[0] = Ax; //nhap toa do vao mang toa_do[]
        printf("Ay: ");
        scanf("%f", &Ay);
        printf("\n");
        toa_do[1] = Ay;

        printf("Nhap toa do diem B: \n");
        printf("Bx: ");
        scanf("%f", &Bx);
        printf("\n");
        toa_do[2] = Bx;
        printf("By: ");
        scanf("%f", &By);
        printf("\n");
        toa_do[3] = By;

        printf("Nhap toa do diem C: \n");
        printf("Cx: ");
        scanf("%f", &Cx);
        printf("\n");
        toa_do[4] = Cx;
        printf("Cy: ");
        scanf("%f", &Cy);
        printf("\n");
        toa_do[5] = Cy;

        printf("Toa do diem A da nhap: A(%.2f, %.2f)\n", Ax, Ay);
        printf("Toa do diem B da nhap: B(%.2f, %.2f)\n", Bx, By);
        printf("Toa do diem C da nhap: C(%.2f, %.2f)\n", Cx, Cy);
        printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    }
    while(kiemtra_tamgiac(Ax, Ay, Bx, By, Cx, Cy) != true); //Neu khong phai tam giac thi nhap lai toa do
    //Kiem tra tam giac
    if (kiemtra_tamgiac(Ax, Ay, Bx, By, Cx, Cy) == true){
        printf("Toa do 3 diem nhap vao tao thanh mot tam giac\n");

        // Tinh goc, canh tam giac
        printf("\n");
        printf("1. So do co ban cua tam giac: \n");
        goccanh_tamgiac(Ax, Ay, Bx, By, Cx, Cy);

        //Xet tam giac
        printf("\n");
        xet_tamgiac(Ax, Ay, Bx, By, Cx, Cy);

        //Dien tich tam giac
        printf("\n");
        printf("2. Dien tich tam giac ABC la: ");
        dientich_tamgiac(Ax, Ay, Bx, By, Cx, Cy);

        //Duong cao tam giac
        printf("\n");
        printf("3. So do nang cao tam giac ABC: \n");
        duongcao_tamgiac(Ax, Ay, Bx, By, Cx, Cy);

        //Trung tuyen tam giac
        trungtuyen_tamgiac(Ax, Ay, Bx, By, Cx, Cy);

        //Trong tam tam giac
        printf("\n");
        printf("4. Toa do diem dac biet cua tam giac ABC: \n");
        tam_tamgiac(Ax, Ay, Bx, By, Cx, Cy);
    }

    return 1;
}

