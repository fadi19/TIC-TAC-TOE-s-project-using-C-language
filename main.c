#include <stdio.h>
int player=1;
int choice;
int i;
char square[3][3] = {{'1', '2','3'} ,{'4', '5', '6'} ,{'7', '8', '9'}};


void board()
{
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
    printf("         |      |      \n");
    printf("      %c  |   %c  |   %c   \n", square[0][0], square[0][1], square[0][2]);
    printf("   ______|______|______\n");
    printf("         |      |      \n");
    printf("      %c  |   %c  |   %c   \n", square[1][0], square[1][1], square[1][2]);
    printf("   ______|______|______\n");
    printf("         |      |      \n");
    printf("      %c  |   %c  |   %c   \n", square[2][0], square[2][1], square[2][2]);
    printf("         |      |      \n");
}


int insert(int choice,char mark)
{     int k=0;
    if (choice == 1 && square[0][0] == '1')
            square[0][0] = mark;

        else if (choice == 2 && square[0][1] == '2')
            square[0][1] = mark;

        else if (choice == 3 && square[0][2] == '3')
            square[0][2] = mark;

        else if (choice == 4 && square[1][0] == '4')
            square[1][0] = mark;

        else if (choice == 5 && square[1][1] == '5')
            square[1][1] = mark;

        else if (choice == 6 && square[1][2] == '6')
            square[1][2] = mark;

        else if (choice == 7 && square[2][0] == '7')
            square[2][0] = mark;

        else if (choice == 8 && square[2][1] == '8')
            square[2][1] = mark;

        else if (choice == 9 && square[2][2] == '9')
            square[2][2] = mark;

        else
        {
            printf("Invalid move");
            player--;
            getch();
        }
}


int isWinning()
{
    if (square[0][0] == square[0][1] && square[0][1] == square[0][2])
        return 1;

    else if (square[1][0] == square[1][1] && square[1][1] == square[1][2])
        return 1;

    else if (square[2][0] == square[2][1] && square[2][1] == square[2][2])
        return 1;

    else if (square[0][0] == square[1][0] && square[1][0] == square[2][0])
        return 1;

    else if (square[0][1] == square[1][1] && square[1][1] == square[2][1])
        return 1;

    else if (square[0][2] == square[1][2] && square[1][2] == square[2][2])
        return 1;

    else if (square[0][0] == square[1][1] && square[1][1] == square[2][2])
        return 1;

    else if (square[0][2] == square[1][1] && square[1][1] == square[2][0])
        return 1;

    else if (square[0][0] != '1' && square[0][1] != '2' && square[0][2] != '3' &&
      square[1][0] != '4' && square[1][1] != '5' && square[1][2] != '6' && square[2][0]
       != '7' && square[2][1] != '8' && square[2][2] != '9')
        return 0;
    else
        return  -1;
}



int main(){
    i, choice;
    char mark;
      player=1;
    do{
        board();
       player = (player % 2) ? 1 : 2;
        /*
            if (player%2)
            {
                player=1;
            }
            else
            {
                player=2;
            }
        */
        printf("Player %d, enter a number from 0-->9 :  ", player);
        scanf("%d", &choice);
        mark = (player == 1) ? 'X' : 'O';
       /*
            if (player==1)
            {
                mark='X';
            }
            else
            {
                mark='O';
            }
        */
        insert(choice,mark);
        i = isWinning();
        player++;
   }
    while (i == -1);

    board();

    if (i == 1)
        printf("==>\aPlayer %d win",--player);
    else
        printf("==>\aGame draw");

}
