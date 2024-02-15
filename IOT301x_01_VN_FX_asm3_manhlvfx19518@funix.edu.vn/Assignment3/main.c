#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
#define MAX_ROW 9
#define MAX_COLUMN 9

//Make struct POINT for the matrix
typedef struct POINT {
    int row;        //tọa độ x của nút
    int column;     //tọa độ y của nút
    int value;      //giá trị 0 hoặc 1 của nút
    bool visited;   //đánh dấu nút đã được đi qua
    struct POINT* prev;    //Use to form a linked list- con trỏ trỏ đến nút liền trước đó trước khi đi đến nút này.
} point_t;

point_t matrix[MAX_ROW][MAX_COLUMN];

//Setup Queue to save all the points on the path
typedef struct {
    point_t data[MAX];  //lưu trữ các nút
    int front;          //chỉ số đầu của hàng đợi
    int rear;           //chỉ số cuối của hàng đợi
} Queue;



//Prototype
bool checkCoordinate(int dong, int cot);
void initQueue(Queue *q);
int isEmpty(Queue q);
int isFull(Queue q);
void enQueue(Queue *q, point_t x);
point_t deQueue(Queue *q);
void findSurroundingPoint(int dong, int cot, point_t surroundingPnt[4], int* count);
void findShortestPath(int dong, int cot);

int main()
{
    //Create global variable for matrix
    int x; //so dong
    int y; //so cot
    //Array with point's value
    int data[9][9] = {
        {1,0,0,0,1,0,1,1,0},
        {1,1,0,1,1,1,0,0,1},
        {0,1,0,1,1,0,1,0,1},
        {0,1,1,0,0,1,0,1,1},
        {0,0,1,0,1,0,1,0,0},
        {1,1,1,0,0,0,0,1,1},
        {1,0,1,1,1,1,1,0,0},
        {1,1,1,0,0,0,1,0,1},
        {0,0,0,1,1,1,1,1,0}
    };
    printf("CHUONG TRINH TIM DUONG DI NGAN NHAT TU O(0, 0) DEN A(dong, cot): \n");
    printf("\n");
    printf("Ma tran %d x %d bieu dien cho mat phang 2 chieu \n", MAX_ROW, MAX_COLUMN);
    for (int i = 0; i < MAX_ROW; i++)
    {
        for(int j = 0; j < MAX_COLUMN; j++)
        {
            matrix[i][j].row = i;
            matrix[i][j].column = j;
            matrix[i][j].visited = false;
            matrix[i][j].value = data[i][j];
            printf("%d ", matrix[i][j].value);
        }
        printf("\n");
    }
    printf("\n");
    printf("Toa do cua o xuat phat la O(0, 0)\n");
    printf("\n");

    do {
        printf("Hay nhap toa do cua o dich den A: \n");
        printf("Nhap dong: ");
        scanf("%d", &x);
        printf("Nhap cot: ");
        scanf("%d", &y);
        if(x < 0 || x > 8)
        {
            printf("Gia tri cua dong phai tu 0 den 8!\n");
        }
        if(y < 0 || y > 8)
        {
            printf("Gia tri cua cot phai  tu 0 den 8!\n");
        }
        printf("\n");
    } while(x < 0 || x > 8 || y < 0 || y > 8);

    findShortestPath(x, y);
    return 0;
}


//Initialize Queue
void initQueue(Queue *q){
   q -> front = 0;
   q -> rear = -1;
}

//Check whether Queue is empty: front index > rear index
int isEmpty(Queue q){
    return (q.rear < q.front); //0 = false; 1 = true;
}

//Check whether Queue is full: rear value > MAX elements
int isFull(Queue q){
    if((q.rear - q.front) == MAX - 1){
        return 1;
    }
    else
    {
        return 0;
    }
}

//Add element to rear
void enQueue(Queue *q, point_t x){
    if(!isFull(*q)){
        if(q -> rear == MAX -1){
            for(int i = q ->front; i <= q -> rear; i++){
                q -> data[i - q -> front] = q -> data[i];
            }
            q -> rear = MAX - q -> front - 1;
            q -> front = 0;
        }
        q -> rear = q -> rear + 1;
        q -> data[q -> rear] = x;
    }
}

//Take the front element out of Queue
point_t deQueue(Queue *q){

    point_t d;

    if (!isEmpty(*q)) {

       d = q->data[q->front];

       q->front = q->front +1;

    }

    if (q->front > q->rear) {

        initQueue(q);

    };
    return d;
}


//Function to check whether a point is in the matrix or not
bool checkCoordinate(int x, int y) {

    bool ret = false;

    if (x >= 0 && x < MAX_ROW && y >= 0 && y < MAX_COLUMN)
    {
        ret = true;
    }
    return ret;
}

//Check points around on the path from O(0,0) to the destination with value of 1
void findSurroundingPoint(int x, int y, point_t surroundingPnt[4], int* count){

    // khởi tạo số biến đếm số lượng các nút có thể đi được quanh 1 vị trí

    int tempCnt = 0;

    // kiểm tra xem vị trí điểm bên phải có đến được không?

    if ((checkCoordinate(x, y+1) == true) && (matrix[x][y+1].value == 1)){

        surroundingPnt[tempCnt] = matrix[x][y+1]; //Put all value: row, col, value... to surroundingPnt.

        tempCnt++;

    }

    // kiểm tra xem vị trí điểm bên dưới có đến được không?

    if ((checkCoordinate(x+1, y) == true) && (matrix[x+1][y].value == 1)) {

        surroundingPnt[tempCnt] = matrix[x+1][y];

        tempCnt++;

    }

    // kiểm tra xem vị trí điểm bên trái có đến được không?

    if ((checkCoordinate(x, y-1) == true) && (matrix[x][y-1].value == 1)) {

        surroundingPnt[tempCnt] = matrix[x][y-1];

        tempCnt++;

    }

    // kiểm tra xem vị trí điểm bên trên có đến được không?

    if ((checkCoordinate(x-1, y) == true) && (matrix[x-1][y].value == 1)) {

        surroundingPnt[tempCnt ] = matrix[x-1][y];

        tempCnt++;

    }

 *count = tempCnt; //use this number in for...loop

}


//Find the shortest path from O(0, 0) to A(dong, cot)
void findShortestPath (int x, int y) {

    Queue queue; //There are maximum 4 points to check, only one is checking at a time so we put others in queue to wait

    initQueue(&queue); //Initialize queue

    matrix[0][0].visited = true; //Set matrix[0][0] as visited

    enQueue(&queue, matrix[0][0]); //Put matrix[0][0] in queue to check surroundings

    bool found = false;
    int countPoints = 0;
    while (isEmpty(queue) == false && found == false) { //Stop when queue is empty and found A(6, 6)

        point_t p = deQueue(&queue); //take out matrix[dong][cot] to check.
        point_t pp[4];  //array to save surroundings to

        findSurroundingPoint(p.row, p.column, pp, &countPoints);
        for (int i = 0; i < countPoints; i++){

            if(pp[i].visited == false) { //only checking for not visited points.

                matrix[pp[i].row][pp[i].column].visited = true; //mark this point as visited in matrix[] so findSurroundingPoint() won't take it again.
                matrix[pp[i].row][pp[i].column].prev = &matrix[p.row][p.column]; //set p is the previous point of pp[i] in matrix[]
                if(pp[i].row == x && pp[i].column == y){ //Check if this point is A(6, 6)
                    found = true;
                    break;
                }

                else {

                    enQueue(&queue, pp[i]); //Put into the queue to check consecutively

                }

            }

        }

    }

    if(found == true) {

        //Sử dụng con trỏ prev trong mỗi nút để in lần lượt tọa độ các nút đã đi qua từ A(dong, cot) đến O(0, 0);
        int count_point = 0;
        point_t path[20]; //array to save right points
        point_t *temp = NULL;
        temp = &matrix[x][y];
        while(temp != NULL){
            //printf("(%d, %d) -> ", temp -> row, temp -> column);
            path[count_point].row = temp -> row;
            path[count_point].column = temp -> column;
            temp = temp -> prev;
            count_point++;
        }
        //print from O(0,0) to A(dong, cot)
        printf("Duong di ngan nhat tu O(0, 0) den A(%d, %d) co do dai la %d o: \n", x, y, count_point);
        for(int i = count_point - 1; i > 0; i--)
        {
            printf("(%d,%d) -> ", path[i].row, path[i].column);
        }
        printf("(%d,%d)", path[0].row, path[0].column);
    }

    else {

        printf("There is no path from O(0, 0) to A(%d, %d)", x, y);

    }

}
