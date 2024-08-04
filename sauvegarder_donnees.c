#include <stdio.h>
#include <string.h>
#include "table.h"

// Fonction pour sauvegarder les données des tables dans un fichier
void sauvegarder_donnees(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier en ecriture.\n");
        return;
    }

    // Écrire le nombre de tables
    fprintf(file, "%d\n", table_count);

    // Écrire les informations de chaque table
    for (int i = 0; i < table_count; i++) {
        Table *table = &tables[i];
        fprintf(file, "%s %d\n", table->name, table->columns);

        // Écrire les informations de chaque colonne
        for (int j = 0; j < table->columns; j++) {
            fprintf(file, "%s:%d %s\n",
                table->column_defs[j].name,
                table->column_defs[j].type,
                (j == table->primary_key_index) ? "PRIMARY" : "");
        }

        // Écrire le nombre de lignes
        fprintf(file, "%d\n", table->rows);

        // Écrire les données de chaque ligne
        for (int r = 0; r < table->rows; r++) {
            for (int c = 0; c < table->columns; c++) {
                fprintf(file, "%s\t", table->data[r][c]);
            }
            fprintf(file, "\n");
        }
    }

    fclose(file);
    printf("Donnees sauvegardees dans '%s'.\n", filename);
}