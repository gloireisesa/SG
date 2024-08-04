#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "table.h"
// Fonction pour cr�er une nouvelle table
void creer_table(char *name, int columns, char *column_defs[]) {
     
    if (table_count >= MAX_TABLES) {
        printf("Erreur : Nombre maximum de tables atteint.\n");
        return;
    }

    Table *table = &tables[table_count];
    table->name = strdup(name);
    table->columns = columns;
    table->rows = 0;
    table->primary_key_index = -1;

    for (int i = 0; i < columns; i++) {
        char *col_def = strdup(column_defs[i]);
        char *col_name = strtok(col_def, ":");
        char *col_type = strtok(NULL, ":");
        table->column_defs[i].name = strdup(col_name);

        if (strcmp(col_type, "ENTIER") == 0) {
            table->column_defs[i].type = ENTIER;
        } else if (strcmp(col_type, "CHAINE") == 0) {
            table->column_defs[i].type = CHAINE;
        } else if (strcmp(col_type, "DECIMAL") == 0) {
            table->column_defs[i].type = DECIMAL;
        } else if (strcmp(col_type, "BINAIRE") == 0) {
            table->column_defs[i].type = BINAIRE;
        } else if (strcmp(col_type, "DATE") == 0) {
            table->column_defs[i].type = DATE;
        } else {
            printf("Erreur : Type de colonne '%s' non valide.\n", col_type);
            free(col_def);
            return;
        }

        if (strstr(column_defs[i], "PRIMARY") != NULL) {
            table->primary_key_index = i;
        }
        free(col_def);
    }

    table_count++;
    printf("Table '%s' creee avec %d colonnes.\n", name, columns);
}
