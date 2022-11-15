//tic_tac_toe

#include <stdio.h>
#include <conio.h>

char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void printBoard();
int check_win();
void system();

void main() {
    printBoard();
    int player = 1, input, status, result;

    while(status = -1) {
        player = (player % 2 == 0) ? 2 : 1;
        char mark = (player == 1) ? 'X' : 'O';

        up:
        printf("Enter number for player1 %d: \n", player);
        scanf("%d", &input);
        if(input < 1 || input > 9) {
            printf("Invalid Input\n");
            goto up;
        }

        board[input] = mark;
        printBoard();

        result = check_win();
        // printf("%d", result);

        if(result == 1) {
            printf("player %d !!!WINNER!!!\n", player);
            return;
        }
        else if(result == 0) {
            printf("!!!DRAW!!!\n");
            return;
        }

        player++;
    }
}

void printBoard() {
    system("cls");
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

int check_win() {
    if(board[1] == board[2] && board[2] == board[3]) {
        return 1;
    }
    if(board[4] == board[5] && board[5] == board[6]) {
        return 1;
    }
    if(board[7] == board[8] && board[8] == board[9]) {
        return 1;
    }
    if(board[1] == board[4] && board[4] == board[7]) {
        return 1;
    }
    if(board[2] == board[5] && board[5] == board[8]) {
        return 1;
    }
    if(board[3] == board[6] && board[5] == board[9]) {
        return 1;
    }
    if(board[3] == board[5] && board[5] == board[7]) {
        return 1;
    }
    if(board[1] == board[5] && board[5] == board[9]) {
        return 1;
    }

    int count = 0;
    for(int i = 1; i <= 9; i++) {
        if(board[i] == 'X' || board[i] == 'O') {
            count++;
        }
    }

    if(count == 9) {
        return 0;
    }
    
    return -1;
}