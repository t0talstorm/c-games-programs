#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*void encrypt(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = str[i] + 1;
    }
    printf("Encrypted password  : %s\n", str);
}*/

char* decrypt(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = str[i] - 1;
    }
    return str;
}

int authentication() {
    char username[][20] = {"aditya", "sanket", "anant", "Hemani", "akshit"};
    //char password[][20] = {"password123", "123password", "@password", "password@", "@123password"};
    char password[][20] = {"qbttxpse234", "234qbttxpse", "Aqbttxpse", "qbttxpseA", "A234qbttxpse"};

    int flag = 0;
    char name[20];

    do {
        printf("Enter your username: ");
        scanf("%s", name);
        for (int i = 0; i < strlen(name); i++) {
            name[i] = tolower(name[i]);
        }

        char pass[20];
        printf("Enter your password: ");
        scanf("%s", pass);

        int found = 0;
        for (int i = 0; i < sizeof(username) / sizeof(username[0]); i++) {
            if (strcmp(name, username[i]) == 0) {
                char* decrypted_pass = decrypt(password[i]);
                if (strcmp(pass, decrypted_pass) == 0) {
                    printf("Login successful!\n");
                    flag = 1;
                    found = 1;
                    break;
                }
            }
        }

        if (found == 0) {
            printf("NAWHHHH BRO ENTER THE CORRECT PASS / USER\n");
        }

    } while (flag == 0);

    return flag;
}

#endif