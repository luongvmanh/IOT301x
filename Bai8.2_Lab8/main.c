#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //to use getch()

int checkForWin();
void displayBoard();
void markBoard(char mark);

char arr[10] = {'0','1','2','3','4','5','6','7','8','9'};
int choice, player;

int main()
{
    int gameStatus;
    char mark;
    player = 1;
    do
    {
        //int choice, mark;
        displayBoard();
        //change turns
        player = (player % 2)? 1 : 2; //The condition here is 1 (true) or 0 (false)

        //get input
        printf("Player %d, enter a number: ", player);
        scanf("%d", &choice);

        //set the correct character based on player turn
        mark = (player == 1)? 'X' : 'O';
        //set board based on user choice or invalid choice
        markBoard(mark);
        displayBoard();
        gameStatus = checkForWin();
        player++;
    } while (gameStatus == -1);

    //Display result.
    if (gameStatus == 1)
    {
        printf("==>\aPlayer %d win ", --player);
    }
    else
    {
        printf("==>\aGame draw");
    }
    return 0;
}


int checkForWin(){
    int returnValue = 0;
    if (arr[1] == arr[2] && arr[2] == arr[3]){
        returnValue = 1;//gameover with result
    }
    else if (arr[4] == arr[5] && arr[5] == arr[6]){
        returnValue = 1;
    }
    else if (arr[7] == arr[8] && arr[8] == arr[9]){
        returnValue = 1;
    }
    else if (arr[1] == arr[4] && arr[4] == arr[7]){
        returnValue = 1;
    }
    else if (arr[2] == arr[5] && arr[5] == arr[8]){
        returnValue = 1;
    }
    else if (arr[3] == arr[6] && arr[6] == arr[9]){
        returnValue = 1;
    }
    else if (arr[1] == arr[5] && arr[5] == arr[9]){
        returnValue = 1;
    }
    else if (arr[3] == arr[5] && arr[5] == arr[7]){
        returnValue = 1;
    }
    else if (arr[1] != '1' && arr[2] != '2' && arr[3] != '3' && arr[4] != '4'
             && arr[5] != '5' && arr[6] != '6' && arr[7] != '7' && arr[8] != '8' && arr[9] != '9')
    {
        returnValue = 0; //gameover with no result (draw)
    }
    else {
        returnValue = -1; //game is in progress
    }
    return returnValue;
}

void displayBoard(){
    system("cls"); //a non-standard function to clear the console screen

    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X) - Player 2 (O)\n\n\n");

    printf("     |    |    \n");
    printf("  %c  | %c  | %c\n", arr[1], arr[2], arr[3]);

    printf("_____|____|____\n");
    printf("     |    |    \n");

    printf("  %c  | %c  | %c\n", arr[4], arr[5], arr[6]);

    printf("_____|____|____\n");
    printf("     |    |    \n");

    printf("  %c  | %c  | %c\n", arr[7], arr[8], arr[9]);

    printf("     |    |    \n");
}


void markBoard(char mark){  //set the board with X or O

    if (choice == 1 && arr[1] == '1'){
        arr[1] = mark;
    }
    else if (choice == 2 && arr[2] == '2'){
        arr[2] = mark;
    }
    else if (choice == 3 && arr[3] == '3'){
        arr[3] = mark;
    }
    else if (choice == 4 && arr[4] == '4'){
        arr[4] = mark;
    }
    else if (choice == 5 && arr[5] == '5'){
        arr[5] = mark;
    }
    else if (choice == 6 && arr[6] == '6'){
        arr[6] = mark;
    }
    else if (choice == 7 && arr[7] == '7'){
        arr[7] = mark;
    }
    else if (choice == 8 && arr[8] == '8'){
        arr[8] = mark;
    }
    else if (choice == 9 && arr[9] == '9'){
        arr[9] = mark;
    }
    else{
        printf("Invalid move ");
        player--;
        getch(); //Reads a single character from the keyboard without echoing it to the console.
    }
}
