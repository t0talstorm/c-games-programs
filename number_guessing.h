#ifndef NUMBER_GUESSING_H
#define NUMBER_GUESSING_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void number_guessing_increment_run_count() 
{
    FILE *Pfile;
    int count;

    Pfile = fopen("number_guessing_r.txt", "r+");
    if (Pfile == NULL) {
 
        Pfile = fopen("number_guessing_r.txt", "w+");
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


int number_guessing()
{
    const int MAX = 100;
    const int MIN = 1;
    int guess = 0, guesses = 0, answer;

    srand(time(0));

    answer = (rand() % MAX )+ MIN;

    do{

        printf("\n Enter a guess : ");
        scanf("%d",&guess);

        if (guess > answer)
        {
            printf("\nNOOOOO its too high !!!");

        }else if(guess < answer){
            printf("NOOOOO its too low !!!");
        
        }else if (guess == answer){

        printf("correct !!");
        
        }
        guesses++;
    }while(guess != answer);
    
    printf("\n***************************************************");
    printf("\n yeppieee!! the answer was : %d",answer);
    printf("\n The number of guesses you took were: %d",guesses);
    printf("\n***************************************************\n");
    
    number_guessing_increment_run_count();

    char temp;
        printf("\n\n\n\n Press enter to exit.");
        getchar(); 
        scanf("%c", &temp);



   
}
#endif 