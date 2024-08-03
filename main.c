#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "table.h"
//#include "table.c"

// Fonction pour gérer les commandes utilisateur
/*void gerer_commande(char *input) {
    // ... (code identique à votre version)
}*/

int main()
{

    atexit(free_all_tables);

    char input[MAX_INPUT_SIZE];
    while (1) {
        printf("mini-sgbdr> ");
        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
            break;
        }
        input[strcspn(input, "\n")] = '\0';
        //int gerer_commande(char *input);
        gerer_commande(input);
        //free_all_tables;
    }
    return 0;
}