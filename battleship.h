

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Function prototypes
void printbattleship_board(char battleship_board[2][5][5]);
void printcompbattleship_board(char battleship_board[2][5][5]);
void clearbattleship_board(char battleship_board[2][5][5]);
void battleship_playermove(char battleship_board[2][5][5]);
void battleship_computermove(char battleship_board[2][5][5]);
void playerAttack(char battleship_board[2][5][5]);
void computerAttack(char battleship_board[2][5][5]);
int battleship_checkWinner(char battleship_board[2][5][5]);
void battleship_increment_run_count();


char battleship_board[2][5][5];
char player = 'X';
char computer = 'O';
char found = '$';
char plfound = '#';
char marked ='^';
void battleship_increment_run_count()
{
    FILE *Pfile;
    int count;

    Pfile = fopen("battleship_r.txt", "r+");
    if (Pfile == NULL) {
        Pfile = fopen("battleship_r.txt", "w+");
        if (Pfile == NULL) {
            printf("Error opening file for writing\n");
            return;
        }
        count = 0;
    } else {
        if (fscanf(Pfile, "%d", &count) != 1) {
            printf("Error reading count\n");
            fclose(Pfile);
            return;
        }
    }
    count++;
    rewind(Pfile);
    freopen("battleship_r.txt", "w+", Pfile); // Truncate the file
    fprintf(Pfile, "%d\n", count);
    fclose(Pfile);
}


void printbattleship_board(char battleship_board[2][5][5]) 
    {
        printf("     1.  2.  3.  4.  5. \n");
        printf("   _____________________\n");
        for (int i = 0; i < 5; i++) {
            printf("%d. | %c | %c | %c | %c | %c |\n", i + 1, battleship_board[0][i][0], battleship_board[0][i][1], battleship_board[0][i][2], battleship_board[0][i][3], battleship_board[0][i][4]);
            if (i < 4) {
                printf("   |---|---|---|---|---|\n");
            }
        }
        printf("   |---|---|---|---|---|\n");
    }

void printcompbattleship_board(char battleship_board[2][5][5]) 
    {
        printf("     1.  2.  3.  4.  5. \n");
        printf("   _____________________\n");
        for (int i = 0; i < 5; i++) 
        {
            printf("%d. | %c | %c | %c | %c | %c |\n", i + 1, battleship_board[1][i][0], battleship_board[1][i][1], battleship_board[1][i][2], battleship_board[1][i][3], battleship_board[1][i][4]);
            if (i < 4) 
            {
                printf("   |---|---|---|---|---|\n");
            }
        }
        printf("   |---|---|---|---|---|\n");
    }

void clearbattleship_board(char battleship_board[2][5][5]) 
    {
        for (int i = 0; i < 5; i++) 
        {
            for (int j = 0; j < 5; j++) 
            {
                battleship_board[0][i][j] = ' ';
                battleship_board[1][i][j] = ' ';
            }
        }
    }

void battleship_playermove(char battleship_board[2][5][5]) 
    {
        int row, col;
        int i = 0; 
        while (i < 5) {
            printf("Enter row for move %d: ", i + 1);
            scanf("%d", &row);
            printf("Enter column for move %d: ", i + 1);
            scanf("%d", &col);

            if (battleship_board[0][row - 1][col - 1] == ' ') 
            {
                battleship_board[0][row - 1][col - 1] = player;
                printf("Successfully assigned\n");
                i++;
            } else 
            {
                printf("The space is full\n");
            }
            printbattleship_board(battleship_board);
        }
    }

void battleship_computermove(char battleship_board[2][5][5]) 
    {
        int row, col;
        int computer_moves = 0;
        srand(time(0));

        while (computer_moves < 5) {
            do {
                row = rand() % 5;
                col = rand() % 5;
            } while (battleship_board[1][row][col] != ' ');

            battleship_board[1][row][col] = computer;
            (computer_moves)++;
            printbattleship_board(battleship_board);
        }
    }

void playerAttack(char battleship_board[2][5][5]) 
    {
        int row, col;
        printf("Enter row to attack: ");
        scanf("%d", &row);
        printf("Enter column to attack: ");
        scanf("%d", &col);

        if (battleship_board[1][row - 1][col - 1] == computer) 
        {
            printf("Hit! You found the computer's piece.\n");
            battleship_board[0][row - 1][col - 1] = found; 

            battleship_board[1][row - 1][col - 1] = ' '; 
        } else
        {
            printf("Miss! No computer piece at this position.\n");
            battleship_board[0][row - 1][col - 1] = marked; 
        }
        printbattleship_board(battleship_board);
    }

void computerAttack(char battleship_board[2][5][5]) 
    {
        int row, col;
        srand(time(0)); 

        do {
            row = rand() % 5;
            col = rand() % 5;
        } while (battleship_board[0][row][col] == found || battleship_board[0][row][col] == plfound || battleship_board[0][row][col] == marked); 

        if (battleship_board[0][row][col] == player) {
            printf("Computer hit your piece at (%d, %d)!\n", row + 1, col + 1);
            battleship_board[0][row][col] = plfound; 
        } else {
            printf("Computer missed at (%d, %d).\n", row + 1, col + 1);
        }
        printbattleship_board(battleship_board);
    }

int battleship_checkWinner(char battleship_board[2][5][5]) 
    {
        int player_pieces = 0, computer_pieces = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (battleship_board[0][i][j] == player) 
                {
                    player_pieces++;
                }
                if (battleship_board[1][i][j] == computer)
                {
                    computer_pieces++;
                }
            }
        }
        if (player_pieces == 0) return 1;
        if (computer_pieces == 0) return 2; 
        return 0; 
    }

int battleship() 
{

    clearbattleship_board(battleship_board);
    printbattleship_board(battleship_board);
    battleship_playermove(battleship_board);
    battleship_computermove(battleship_board);
    printcompbattleship_board(battleship_board);

    int winner = 0;
    while (winner == 0) 
    {
        playerAttack(battleship_board);
        winner = battleship_checkWinner(battleship_board);

        if (winner != 0) break;

        computerAttack(battleship_board);
        winner = battleship_checkWinner(battleship_board);
    }

    if (winner == 1) 
    {
        printf("Computer wins!\n");
    } 
    else if (winner == 2) 
    {
        printf("Player wins!\n");
    }

    battleship_increment_run_count();

    char temp;
        printf("\n\n\n\n Press enter to exit.");
        getchar(); 
        scanf("%c", &temp);


    return 0;
}
