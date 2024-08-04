#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "table.h"

// Fonction pour charger les données des tables depuis un fichier
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
            char col_type_str[MAX_INPUT_SIZE]; // Lire le type comme une chaîne
            char primary[MAX_INPUT_SIZE];
            fscanf(file, "%[^:]:%s %s\n", col_name, col_type_str, primary);

            // Convertir la chaîne de type en entier
            int col_type;
            if (strcmp(col_type_str, "ENTIER") == 0) {
                col_type = ENTIER; // Assurez-vous que ENTIER est défini dans table.h
            } else if (strcmp(col_type_str, "CHAINE") == 0) {
                col_type = CHAINE; // Assurez-vous que CHAINE est défini dans table.h
            } else {
                // Gérer les autres types...
                col_type = -1; // Valeur par défaut en cas d'erreur
            }

            table->column_defs[j].name = strdup(col_name);
            table->column_defs[j].type = col_type; // Assigner le type entier

            if (strcmp(primary, "PRIMARY") == 0) {
                table->primary_key_index = j;
            }
        }

        // Lire le nombre de lignes
        fscanf(file, "%d\n", &table->rows);

        // Lire les données de chaque ligne
        for (int r = 0; r < table->rows; r++) {
            for (int c = 0; c < table->columns; c++) {
                table->data[r][c] = malloc(MAX_INPUT_SIZE);
                fscanf(file, "%s", table->data[r][c]);
            }
        }
    }

    fclose(file);
    printf("Donnees chargees depuis '%s'.\n", filename);
}