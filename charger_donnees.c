#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "table.h"

// Fonction pour charger les donn�es des tables depuis un fichier
void charger_donnees(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier en lecture.\n");
        return;
    }

    // Lire le nombre de tables
    fscanf(file, "%d\n", &table_count);

    // Lire les informations de chaque table
    for (int i = 0; i < table_count; i++) {
        Table *table = &tables[i];
        table->name = malloc(MAX_INPUT_SIZE);
        fscanf(file, "%s %d\n", table->name, &table->columns);

        // Lire les informations de chaque colonne
        for (int j = 0; j < table->columns; j++) {
            char col_name[MAX_INPUT_SIZE];
            int col_type;
            char primary[MAX_INPUT_SIZE];
            fscanf(file, "%[^:]:%d %s\n", col_name, &col_type, primary);

            table->column_defs[j].name = strdup(col_name);
            table->column_defs[j].type = col_type;

            if (strcmp(primary, "PRIMARY") == 0) {
                table->primary_key_index = j;
            }
        }

        // Lire le nombre de lignes
        fscanf(file, "%d\n", &table->rows);

        // Lire les donn�es de chaque ligne
        //for (int r = 0; r < table->rows; r++) {
            //for (int c = 0; c < table->columns; c++) {
                //table->data[r][c] = malloc(

        // Lire les donn�es de chaque ligne
        for (int r = 0; r < table->rows; r++) {
            for (int c = 0; c < table->columns; c++) {
                table->data[r][c] = malloc(MAX_INPUT_SIZE);
                fscanf(file, "%s", table->data[r][c]);
            }
        }
    }

    fclose(file);
    printf("Donn�es charg�es depuis '%s'.\n", filename);
}
