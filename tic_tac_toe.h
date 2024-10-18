#ifndef tic_tac_toe_H
#define tic_tac_toe_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

char tic_tac_toe_board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard(char tic_tac_toe_board[3][3]);
void printBoard(char tic_tac_toe_board[3][3]);
int checkFreeSpaces(char tic_tac_toe_board[3][3]);
void playermove(char tic_tac_toe_board[3][3]);
void computermove(char tic_tac_toe_board[3][3]);
char tic_tac_toe_checkWinner(char tic_tac_toe_board[3][3]);
char printwinner(char);
void Tic_tac_toe_increment_run_count();

int tic_tac_toe(){

char winner = ' ';

    resetBoard(tic_tac_toe_board);

    while(winner == ' ' && checkFreeSpaces(tic_tac_toe_board) != 0)
      {
         printBoard(tic_tac_toe_board);

         playermove(tic_tac_toe_board);
         winner = tic_tac_toe_checkWinner(tic_tac_toe_board);
         if(winner != ' ' || checkFreeSpaces(tic_tac_toe_board) == 0)
         {
            break;
         }

         computermove(tic_tac_toe_board);
         winner = tic_tac_toe_checkWinner(tic_tac_toe_board);
         if(winner != ' ' || checkFreeSpaces(tic_tac_toe_board) == 0)
         {
            break;
         }
      }

    printBoard(tic_tac_toe_board);
    printwinner(winner);
    Tic_tac_toe_increment_run_count();

    char temp;
        printf("\n\n\n\n Press enter to exit.");
        getchar(); 
        scanf("%c", &temp);


    

    return 0;
}



void resetBoard(char tic_tac_toe_board[3][3]){
    for(int i = 0 ; i < 3 ; i++)
    {for(int j = 0 ; j <3 ; j++){

        tic_tac_toe_board[i][j] = ' ' ;
        }
    }

}
void printBoard(char tic_tac_toe_board[3][3]){
    printf(" %c | %c | %c ", tic_tac_toe_board[0][0] , tic_tac_toe_board[0][1] , tic_tac_toe_board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", tic_tac_toe_board[1][0] , tic_tac_toe_board[1][1] , tic_tac_toe_board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", tic_tac_toe_board[2][0] , tic_tac_toe_board[2][1] , tic_tac_toe_board[2][2]);
    printf("\n");

}
int checkFreeSpaces(char tic_tac_toe_board[3][3]){

int freespaces = 9;

    for(int i = 0 ; i < 3 ; i++)
    {

        for(int j = 0 ; j < 3 ;j++)
        {

            if (tic_tac_toe_board[i][j] != ' ')
            {

                freespaces--;
            }
        }
    }
    return freespaces;
}
void playermove(char tic_tac_toe_board[3][3])
{

    int x;
    int y;

    do{
        printf("Enter row number (1-3): ");
            scanf("%d",&x);
            x--;

        printf("Enter coloumn number (1-3): ");
            scanf("%d",&y);
            y--;

        if(tic_tac_toe_board[x][y] != ' ')
        {
            printf("Invalid move !!!!! ");
        }
        else
        {            
            tic_tac_toe_board[x][y] = PLAYER;
            break;
        }

    }while(tic_tac_toe_board[x][y] != ' ');
}
void computermove(char tic_tac_toe_board[3][3]){

    //creats a seed based on current time

 srand(time(0));
 int x ;
 int y ;

 if (checkFreeSpaces(tic_tac_toe_board) > 0)
    {
        do
        {
            x = rand()%3;
            y = rand()%3;

        }while (tic_tac_toe_board[x][y] != ' ');

        tic_tac_toe_board[x][y] = COMPUTER;

    }
    else
    {
        printwinner(' ');
    }

}
char tic_tac_toe_checkWinner(char tic_tac_toe_board[3][3]){

    //check rows 
    for(int i = 0 ; i <3 ; i++){

        if(tic_tac_toe_board[i][0] == tic_tac_toe_board[i][1] && tic_tac_toe_board[i][1]== tic_tac_toe_board[i][2] && tic_tac_toe_board[i][0] != ' '){
            return tic_tac_toe_board[i][0];

        }
    }

  //check coloumns 
    for(int i = 0 ; i <3 ; i++){

        if(tic_tac_toe_board[0][i] == tic_tac_toe_board[1][i] && tic_tac_toe_board[1][i] == tic_tac_toe_board[2][i] && tic_tac_toe_board[i][0] != ' '){
            return tic_tac_toe_board[0][i];

        }
    }

     //check diagonals 

        if(tic_tac_toe_board[0][0] == tic_tac_toe_board[1][1] && tic_tac_toe_board[1][1]== tic_tac_toe_board[2][2] && tic_tac_toe_board[0][0] != ' '){
            return tic_tac_toe_board[0][0];

        }else if(tic_tac_toe_board[0][2] == tic_tac_toe_board[1][1] && tic_tac_toe_board[1][1] == tic_tac_toe_board[0][0] && tic_tac_toe_board[0][0] != ' '){
            return tic_tac_toe_board[1][1];

        }
        return ' ';
    }

// Removed duplicate and incorrect definition of tic_tac_toe_checkWinner


char printwinner(char winner){

    if(winner == PLAYER)
    {
        printf("yeppieeee !!! you win");

    }else if (winner == COMPUTER)
    {
        printf("NOOOBBB u lost ahhahahha");
    }else{
        printf("IT's A TIEEE");
    }
    


}

void Tic_tac_toe_increment_run_count() 
{
    FILE *Pfile;
    int count;

    Pfile = fopen("tic-tac-toe_r.txt", "r+");
    if (Pfile == NULL) {
 
        Pfile = fopen("tic-tac-toe_r.txt", "w+");
        if (Pfile == NULL) {
            printf("Error opening file");
        }
        count = 0;

    } else {

        if (fscanf(Pfile, "%d", &count) != 1) {
            printf("Error reading count");
            fclose(Pfile);
        }
    }
    count++;
    rewind(Pfile);

    fprintf(Pfile, "%d\n", count);

    fclose(Pfile);
}

#endif // tic_tac_toe_H