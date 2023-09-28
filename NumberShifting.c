#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void rules(int[4][4]);
void startGame(char[20], int[4][4]);
int win(int[4][4]);
int validKey(char, int, int);

int winBoard[4][4] = {1, 2, 3, 4,
                      5, 6, 7, 8,
                      9, 10, 11, 12,
                      13, 14, 15};

int board[4][4] /* = {1, 2, 3, 4,
                    5, 6, 7, 8,
                    9, 10, 11, 12,
                    13, 14, 15}*/
    ;

int main()
{
    // srand(time(NULL));
    int random = rand() % 15;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            board[i][j] = ++random;
            if (random == 15)
                random = 0;
        }
    board[3][3] = 0;
    system("cls");
    char name[20];
    char key;
    printf("Player Name : ");
    fgets(name, sizeof(name), stdin);

    system("cls");
    rules(winBoard);
    printf("Enter any key to start....");
    key = getch();
    if (key == 'e' || key == 'E')
        return 0;

    fflush(stdin);

    startGame(name, board);

    return 0;
}

void startGame(char name[20], int board[4][4])
{

    int move = 100;
    while (1)
    {
        char key;
        int i0, j0;

        system("cls");
        fflush(stdin);
        if (win(board))
        {
            printf("Congratulations!!! You win the game...\n\n");
            printf("Press any key to exit the game...");
            getch();
            return;
        }
        printf("\n               Hello %s               Move remaining : %d\n", name, move);
        if (move == 1)
            printf("\n****************************************************************\n                         Warning!!! %s                               Only 1 Move left to win the game. \n****************************************************************\n", name);

        // Display board
        printf("---------------------\n");

        for (int i = 0; i < 4; i++)
        {
            printf("|");
            for (int j = 0; j < 4; j++)
            {
                if (board[i][j] == 0)
                {
                    i0 = i;
                    j0 = j;
                    printf("%3c |", ' ');
                    continue;
                }
                printf("%3d |", board[i][j]);
            }
            printf("\n");
        }
        printf("---------------------\n");

    valid:
        fflush(stdin);
        key = getch();
        printf("%c\n", key);
        if (key == 'e' || key == 'E')
        {
            printf("exit\n");
            return;
        }
        else if (validKey(key, i0, j0))
        {
            if (key == '8')
            {
                board[i0][j0] = board[i0 - 1][j0];
                board[i0 - 1][j0] = 0;
            }
            if (key == '2')
            {
                board[i0][j0] = board[i0 + 1][j0];
                board[i0 + 1][j0] = 0;
            }
            if (key == '4')
            {
                board[i0][j0] = board[i0][j0 - 1];
                board[i0][j0 - 1] = 0;
            }
            if (key == '6')
            {
                board[i0][j0] = board[i0][j0 + 1];
                board[i0][j0 + 1] = 0;
            }

            move--;
            if (move == 0)
            {
                system("cls");
                printf("You Lose!!! Try Again...");
                getch();
                return;
            }

            continue;
        }
        else
        {
            printf("Please, Enter a valid key : ");
            goto valid;
        }
        printf("end loop\n");
    }
}

int validKey(char key, int i, int j)
{
    if (key == '8')
    {
        if ((i - 1) >= 0)
            return 1;
        else
            return 0;
    }
    if (key == '2')
    {
        if ((i + 1) <= 3)
            return 1;
        else
            return 0;
    }
    if (key == '4')
    {
        if ((j - 1) >= 0)
            return 1;
        else
            return 0;
    }
    if (key == '6')
    {
        if ((j + 1) <= 3)
            return 1;
        else
            return 0;
    }

    return 0;
}

int win(int board[4][4])
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j] != winBoard[i][j])
                return 0;
    return 1;
}

void rules(int board[4][4])
{
    printf("1. You can move only one step at a time by arrow key.\n");
    printf("  Move Up    : by '8' character key\n");
    printf("  Move Down  : by '2' character key\n");
    printf("  Move Left  : by '4' character key\n");
    printf("  Move Right : by '6' character key\n");

    printf("\n2. You can move number at empty position only.\n");
    printf("\n3. For each valid move : your total number of move will decrease by 1.\n");
    printf("\n4. Winning situation : Number in 4*4 matrix should be in order from 1 to 15.\n");
    printf("\n                  Winning situation  \n");

    // Display Winning Board

    printf("---------------------\n");

    for (int i = 0; i < 4; i++)
    {
        printf("|");
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 0)
            {
                printf("%3c |", ' ');
                continue;
            }
            printf("%3d |", board[i][j]);
        }
        printf("\n");
    }
    printf("---------------------\n");

    printf("\n5. You can exit the game at any time by pressing 'E' or 'e'.\n");
    printf("So, Try to win in minimum number of move.\n");
    printf("\n             Happy Gamming, Good Luck\n");
}