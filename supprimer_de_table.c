#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "table.h"

// Fonction pour supprimer des lignes d'une table selon une condition
void supprimer_de_table(char *name, char *condition) {
    Table *table = NULL;
    for (int i = 0; i < table_count; i++) {
        if (strcmp(tables[i].name, name) == 0) {
            table = &tables[i];
            break;
        }
    }

    if (table == NULL) {
        printf("Erreur : Table '%s' non trouv�e.\n", name);
        return;
    }

    char *col_name = strtok(condition, "=");
    char *col_value = strtok(NULL, "=");
    int col_index = -1;

    // Recherche de l'index de la colonne sp�cifi�e dans la condition
    for (int j = 0; j < table->columns; j++) {
        if (strcmp(table->column_defs[j].name, col_name) == 0) {
            col_index = j;
            break;
        }
    }

    if (col_index == -1) {
        printf("Erreur : Colonne '%s' non trouv�e.\n", col_name);
        return;
    }

    // Suppression des lignes qui correspondent � la condition
    int new_row_count = 0;
    for (int r = 0; r < table->rows; r++) {
        if (strcmp(table->data[r][col_index], col_value) != 0) {
            // D�placer la ligne courante vers le nouvel emplacement
            for (int c = 0; c < table->columns; c++) {
                table->data[new_row_count][c] = table->data[r][c];
            }
            new_row_count++;
        } else {
            // Lib�rer la m�moire de la ligne � supprimer
            for (int c = 0; c < table->columns; c++) {
                free(table->data[r][c]);
            }
        }
    }
    table->rows = new_row_count;
    printf("Lignes supprim�es de la table '%s'.\n", name);
}
