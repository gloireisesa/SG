#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

//Table tables[MAX_TABLES];
//int table_count = 0;

// fonction pour inserer une nouvelle ligne dans une table
void inserer_dans_table(char *name, char *values[]) {
    Table *table = NULL;
    for (int i = 0; i < table_count; i++) {
        if (strcmp(tables[i].name, name) == 0) {
            table = &tables[i]; // trouver la table par son nom
            break;
        }
    }

    if (table == NULL) {
        printf("Erreur : Table '%s' non trouvee.\n", name);
        return;
    }

    if (table->rows >= MAX_ROWS) {
        printf("Erreur : Nombre maximum de lignes atteint pour la table '%s'.\n", name);
        return;
    }

    // Verification de la cle primaire (si definie)
    if (table->primary_key_index != -1) {
        for (int r = 0; r < table->rows; r++) {
            if (strcmp(table->data[r][table->primary_key_index], values[table->primary_key_index]) == 0) {
                printf("Erreur : Valeur de cle primaire en double.\n");
                return;
            }
        }
    }

    // Insertion des valeurs dans la nouvelle ligne
    for (int j = 0; j < table->columns; j++) {
        table->data[table->rows][j] = strdup(values[j]);
    }
    table->rows++;
    printf("Ligne inseree dans la table '%s'.\n", name);
}