#ifndef HANGMAN_H
#define HANGMAN_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void hangman_increment_run_count() 
{
    FILE *Pfile;
    int count;

    Pfile = fopen("hangman_r.txt", "r+");
    if (Pfile == NULL) {
 
        Pfile = fopen("hangman_r.txt", "w+");
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


int hangman()
{
    srand(time(0));
    char chosen[10];
    char guessed[10];

    char words[][10]= {"mercury","venus","earth","mars","jupiter","saturn","uranus"};
    
    
    int n_elements = sizeof(words) / sizeof(words[0]);
    int c = rand()%n_elements;
    strcpy(chosen, words[c]);

    printf("no. of characters : ");
    for (int i = 0; i < strlen(chosen); i++){
         printf("_ ");
    }
    int max_tries = 5;
    int no_of_guesses = 0;

    printf("\nHINT : Planets in the solar system \n\n");


    
 while (strcmp(guessed, words[c]) != 0 && no_of_guesses <= max_tries) {
        

        printf("\nEnter your guess: ");
        scanf("%s", guessed); 
        strlwr(guessed);

        if(strcmp(guessed, words[c])==0){

        printf("\n\n************************************\n");     
        printf("YAYYYY YOU WONNNNN!!! yeppieeee\n");
        printf("************************************\n"); 

     }else if (no_of_guesses >= max_tries){

        printf("\n\n************************************");
        printf("\nYou lost too many guesses");
        printf("\nThe correct answer was %s\n",chosen);
        printf("************************************\n"); 
     }
     else{

        for (int i = 0; i < strlen(chosen); i++) {
            if (guessed[i] == chosen[i]) {

                printf("%c", guessed[i]);
            } else {
                printf("_ ");
            }
        }
        no_of_guesses++; 
        

        printf("\nNumber of guesses: %d/%d\n", no_of_guesses,max_tries);
    }
 }
 hangman_increment_run_count();

 char temp;
        printf("\n\n\n\n Press enter to exit.");
        getchar(); 
        scanf("%c", &temp);

 
     
    return 0;
}

    #endif 
