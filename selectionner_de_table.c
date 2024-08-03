#include <stdio.h>
#include <string.h>
#include "table.h"

// Fonction pour sélectionner et afficher des données d'une table
void selectionner_de_table(char *name, char *condition) {
    Table *table = NULL;
    for (int i = 0; i < table_count; i++) {
        if (strcmp(tables[i].name, name) == 0) {
            table = &tables[i];
            break;
        }
    }

    if (table == NULL) {
        printf("Erreur : Table '%s' non trouvée.\n", name);
        return;
    }

    printf("Table '%s':\n", name);

    int col_index = -1;
    char *col_name = NULL;
    char *col_value = NULL;
    char *operator = NULL;

    if (condition != NULL) {
        // Supprimer les guillemets simples autour du nom de la colonne
        col_name = strtok(condition, " ");
        if (col_name[0] == '\'' && col_name[strlen(col_name) - 1] == '\'') {
            col_name = strdup(col_name + 1);
            col_name[strlen(col_name) - 1] = '\0';
        }

        operator = strtok(NULL, " ");
        col_value = strtok(NULL, " ");

        // Trouver l'index de la colonne pour la condition
        for (int j = 0; j < table->columns; j++) {
            if (strcmp(table->column_defs[j].name, col_name) == 0) {
                col_index = j;
                break;
            }
        }

        if (col_index == -1) {
            printf("Erreur : Colonne '%s' non trouvée.\n", col_name);
            return;
        }
    }

    // Afficher les en-têtes de colonne
    for (int c = 0; c < table->columns; c++) {
        printf("%s\t", table->column_defs[c].name);
    }
    printf("\n");

    // Afficher les lignes de la table
    for (int r = 0; r < table->rows; r++) {
        // Vérifier la condition (si elle est spécifiée)
        if (condition != NULL) {
            // Vérifier le type de données de la colonne
            if (table->column_defs[col_index].type == ENTIER) {
                int value1 = atoi(table->data[r][col_index]);
                int value2 = atoi(col_value);

                // Vérifier l'opérateur
                if (
                    (strcmp(operator, "<=") == 0 && value1 <= value2) ||
                    (strcmp(operator, ">=") == 0 && value1 >= value2) ||
                    (strcmp(operator, "<") == 0 && value1 < value2) ||
                    (strcmp(operator, ">") == 0 && value1 > value2) ||
                    (strcmp(operator, "=") == 0 && value1 == value2)
                ) {
                    // Afficher la ligne si la condition est vraie
                    for (int c = 0; c < table->columns; c++) {
                        printf("%s\t", table->data[r][c]);
                    }
                    printf("\n");
                }
            } else if (table->column_defs[col_index].type == CHAINE) {
                // Vérifier l'opérateur
                if (
                    (strcmp(operator, "=") == 0 && strcmp(table->data[r][col_index], col_value) == 0) ||
                    (strcmp(operator, "LIKE") == 0 && strstr(table->data[r][col_index], col_value) != NULL)
                ) {
                    // Afficher la ligne si la condition est vraie
                    for (int c = 0; c < table->columns; c++) {
                        printf("%s\t", table->data[r][c]);
                    }
                    printf("\n");
                }
            } else if (table->column_defs[col_index].type == DATE) {
                // Vérifier l'opérateur
                if (strcmp(operator, "=") == 0 && strcmp(table->data[r][col_index], col_value) == 0) {
                    // Afficher la ligne si la condition est vraie
                    for (int c = 0; c < table->columns; c++) {
                        printf("%s\t", table->data[r][c]);
                    }
                    printf("\n");
                }
            }
        } else {
            // Afficher toutes les lignes si aucune condition n'est spécifiée
            for (int c = 0; c < table->columns; c++) {
                printf("%s\t", table->data[r][c]);
            }
            printf("\n");
        }
    }
}