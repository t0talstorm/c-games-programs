#ifndef ROCK_PAPER_SISSOR_H
#define ROCK_PAPER_SISSOR_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rock_paper_sissor_increment_run_count();

typedef enum { ROCK, PAPER, SCISSORS } Choice;

void rock_paper_sissor_increment_run_count() 
{
    FILE *Pfile;
    int count;

    Pfile = fopen("rock_paper_sissor_r.txt", "r+");
    if (Pfile == NULL) {
        Pfile = fopen("rock_paper_sissor_r.txt", "w+");
        if (Pfile == NULL) {
            printf("Error opening file");
            return;
        }
        count = 0;
    } else {
        if (fscanf(Pfile, "%d", &count) != 1) {
            printf("Error reading count");
            fclose(Pfile);
            return;
        }
    }
    count++;
    rewind(Pfile);
    fprintf(Pfile, "%d\n", count);
    fclose(Pfile);
}

int rock_paper_sissor() {
    srand(time(0));

    int choice;
    printf("************Welcome************\n");
    printf("Enter your choice \n1. ROCK \n2. PAPER \n3. SCISSORS \n :  ");
    scanf("%d", &choice);
    choice = choice - 1;

    Choice playerChoice = choice;
    Choice computerChoice = rand() % 3;

    printf("************************\n");

    printf("You chose: ");
    switch (playerChoice) {
        case ROCK:
            printf("ROCK");
            break;
        case PAPER:
            printf("PAPER");
            break;
        case SCISSORS:
            printf("SCISSORS");
            break;
    }
    printf("\n");

    printf("Computer chose: ");
    switch (computerChoice) {
        case ROCK:
            printf("ROCK");
            break;
        case PAPER:
            printf("PAPER");
            break;
        case SCISSORS:
            printf("SCISSORS");
            break;
    }
    printf("\n");
    printf("************************\n");

    if (playerChoice == computerChoice) {
        printf("It's a draw!\n");
    } else if ((playerChoice == ROCK && computerChoice == SCISSORS) ||
               (playerChoice == PAPER && computerChoice == ROCK) ||
               (playerChoice == SCISSORS && computerChoice == PAPER)) {
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }
    printf("************************\n");

    rock_paper_sissor_increment_run_count();

    char temp;
    printf("\n\n\n\n Press enter to exit.");
    getchar();
    scanf("%c", &temp);

    return 0;
}
#endif