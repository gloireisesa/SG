#include<stdio.h>
#include<stdlib.h>
#include "table.h"

// Fonction pour gérer les commandes utilisateur
void gerer_commande(char *input) {
    // ... (code identique à votre version)
}

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
        gerer_commande(input);
    }
    return 0;
}