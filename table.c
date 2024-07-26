#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

Table tables[MAX_TABLES];
int table_count = 0;

// Fonction pour libérer la mémoire allouée pour une table
void free_table(Table *table) {
    // ... (code identique à votre version)
}

// Fonction pour libérer la mémoire de toutes les tables
void free_all_tables(void) {
    // ... (code identique à votre version)
}

// Fonction pour créer une nouvelle table
void creer_table(char *name, int columns, char *column_defs[]) {
    // ... (code identique à votre version)
}

// Fonction pour insérer une nouvelle ligne dans une table
void inserer_dans_table(char *name, char *values[]) {
    // ... (code identique à votre version)
}

// Fonction pour mettre à jour des lignes dans une table selon une condition
void mettre_a_jour_table(char *name, char *condition, char *new_values[]) {
    // ... (code identique à votre version)
}

// Fonction pour supprimer des lignes d'une table selon une condition
void supprimer_de_table(char *name, char *condition) {
    // ... (code identique à votre version)
}

// Fonction pour sélectionner et afficher des données d'une table
void selectionner_de_table(char *name, char *condition) {
    // ... (code identique à votre version)
}

// Fonction pour sauvegarder les données des tables dans un fichier
void sauvegarder_donnees(const char *filename) {
    // ... (code identique à votre version)
}

// Fonction pour charger les données des tables depuis un fichier
void charger_donnees(const char *filename) {
    // ... (code identique à votre version)
}
