#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>
#include "table.h"
//#include "table.c"

// Fonction pour gérer les commandes utilisateur
void gerer_commande(char *input) {
     char command[MAX_INPUT_SIZE];
    sscanf(input, "%s", command);

    if (strcmp(command, "CREER") == 0) {
        char table_name[MAX_INPUT_SIZE];
        int columns;
        char column_defs_str[MAX_INPUT_SIZE];
        sscanf(input, "CREER TABLE %s %d %[^\n]", table_name, &columns, column_defs_str);
        char *column_defs[MAX_COLUMNS];
        char *token = strtok(column_defs_str, ",");
        int count = 0;
        while (token && count < columns) {
            column_defs[count++] = (char *) strdup(token);
            //column_defs[count++] = strdup(token);
            token = strtok(NULL, ",");
        }
        creer_table(table_name, columns, column_defs);
        for (int i = 0; i < count; i++) {
            free(column_defs[i]);
        }
    } else if (strcmp(command, "INSERER") == 0) {
        char table_name[MAX_INPUT_SIZE];
        char values_str[MAX_INPUT_SIZE];
        sscanf(input, "INSERER DANS %s VALEURS %[^\n]", table_name, values_str);
        char *values[MAX_COLUMNS];
        int count = 0;
        char *token = strtok(values_str, ",");
        while (token && count < MAX_COLUMNS) {
            values[count++] = token;
            token = strtok(NULL, ",");
        }
        inserer_dans_table(table_name, values);
    } else if (strcmp(command, "METTREAJOUR") == 0) {
        char table_name[MAX_INPUT_SIZE];
        char condition[MAX_INPUT_SIZE];
        char values_str[MAX_INPUT_SIZE];
        sscanf(input, "METTREAJOUR %s SET %[^\n] WHERE %[^\n]", table_name, values_str, condition);
        char *values[MAX_COLUMNS];
        int count = 0;
        char *token = strtok(values_str, ",");
        while (token && count < MAX_COLUMNS) {
            values[count++] = token;
            token = strtok(NULL, ",");
        }
        mettre_a_jour_table(table_name, condition, values);
    } else if (strcmp(command, "SUPPRIMER") == 0) {
        char table_name[MAX_INPUT_SIZE];
        char condition[MAX_INPUT_SIZE];
        sscanf(input, "SUPPRIMER DE %s WHERE %[^\n]", table_name, condition);
        supprimer_de_table(table_name, condition);
    } else if (strcmp(command, "SELECTIONNER") == 0) {
        char table_name[MAX_INPUT_SIZE];
        char condition[MAX_INPUT_SIZE];
        char *condition_ptr = NULL;
        if (sscanf(input, "SELECTIONNER * DE %s WHERE %[^\n]", table_name, condition) == 2) {
            condition_ptr = condition;
        } else {
            sscanf(input, "SELECTIONNER * DE %s", table_name);
        }
        selectionner_de_table(table_name, condition_ptr);
    } else if (strcmp(command, "SAUVEGARDER") == 0) {
        char filename[MAX_INPUT_SIZE];
        sscanf(input, "SAUVEGARDER %s", filename);
        sauvegarder_donnees(filename);
    } else if (strcmp(command, "CHARGER") == 0) {
        char filename[MAX_INPUT_SIZE];
        sscanf(input, "CHARGER %s", filename);
        charger_donnees(filename);
    } else {
        printf("Erreur : Commande inconnue '%s'.\n", command);
    }
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
        //int gerer_commande(char *input);
        gerer_commande(input);
        //free_all_tables;
    }
    return 0;
}