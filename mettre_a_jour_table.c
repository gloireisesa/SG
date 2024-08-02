#include <stdio.h>
#include <string.h>
#include "table.h"
// Fonction pour mettre � jour des lignes dans une table selon une condition
void mettre_a_jour_table(char *name, char *condition, char *new_values[]) {
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

    // Mise � jour des lignes qui correspondent � la condition
    for (int r = 0; r < table->rows; r++) {
        if (strcmp(table->data[r][col_index], col_value) == 0) {
            for (int c = 0; c < table->columns; c++) {
                free(table->data[r][c]);
                table->data[r][c] = strdup(new_values[c]);
            }
        }
    }
    printf("Table '%s' mise � jour.\n", name);
}
