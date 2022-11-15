//tic_tac_toe

#include <stdio.h>
#include <conio.h>

char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void printBoard();

int main() {
    printBoard();
    int player = 1, input;

    char mark = (player == 1) ? 'X' : 'O';

    scanf("%d", &input);
    if(input < 1 || input > 9) {
        printf("Invalid Input");
    }   

    board[input] = mark;

    printBoard();

    return 0;
}

void printBoard() {
    printf("\n\n");
    printf("===TIC TAC TOE===\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1], board[2], board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[4], board[5], board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[7], board[8], board[9]);
    printf("     |     |     \n");
    printf("\n\n");
}