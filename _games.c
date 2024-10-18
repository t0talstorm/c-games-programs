#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Include the header file for games
#include "hangman.h"
#include "battleship.h"
#include "rock_paper_sissor.h"
#include "tic_tac_toe.h"
#include "number_guessing.h"
#include "authentication.h"


// Function to get the run count from a file
int get_run_count(char filename[]) {
    FILE *file;
    int count;

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1; // Return -1 if the file cannot be opened
    }

    // Read the current count from the file
    if (fscanf(file, "%d", &count) != 1) {
        perror("Error reading count");
        fclose(file);
        return -1; // Return -1 if there is an error reading the count
    }

    // Close the file
    fclose(file);

    return count;
}



// Function to handle game choices
int choice(int i) {
    int z = 0;
    int count;

    switch (i) {
        case 1:
            rock_paper_sissor();
            printf("started successfully");

            count = get_run_count("rock_paper_sissor_r.txt");
            printf("\nThe number of times rock paper sissor has been run is: %d", count);
            break;

        case 2:
            printf("started successfully");
            hangman();
            

            count = get_run_count("hangman_r.txt");
            printf("The number of times hangman has been run is: %d", count);
            break;

        case 3:
            printf("started successfully");
            tic_tac_toe();
            

            count = get_run_count("tic-tac-toe_r.txt");
            printf("The number of times tic-tac-toe has been run is: %d", count);
            break;

        case 4:
            printf("started successfully");
            number_guessing();
            

            count = get_run_count("number_guessing_r.txt");
            printf("The number of times number guessing has been run is: %d", count);
            break;

        case 5:
        
            battleship();
            printf("started successfully");

            count = get_run_count("battleship_r.txt");
            printf("The number of times battleship has been run is: %d", count);
            break;

        case 0:
            z = 1;
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return z;
}

int main() {
    int z = authentication();

    if (z == 1) {
        do {
            int i;
            printf("\nWhat game do you wanna play:");
            printf("\n1. Rock paper scissors \n2. Hangman \n3. Tic-tac-toe \n4. Number guessing \n5. Battleship\n\n0. to exit\n: ");
            scanf("%d", &i);

            z = choice(i);

        } while (z != 1);
    }
    return 0;
}
