#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

#define MAX_INPUT_SIZE 256
#define MAX_TABLES 10
#define MAX_ROWS 100
#define MAX_COLUMNS 10

typedef enum { ENTIER, CHAINE, DECIMAL, BINAIRE, DATE } DataType;

typedef struct {
    char *name;
    DataType type;
} Column;

typedef struct {
    char *name;
    int rows;
    int columns;
    Column column_defs[MAX_COLUMNS];
    char *data[MAX_ROWS][MAX_COLUMNS];
    int primary_key_index;
} Table;
Table tables[MAX_TABLES];
int table_count = 0;

// Déclarations des fonctions
void creer_table(char *name, int columns, char *column_defs[]);
void inserer_dans_table(char *name, char *values[]);
void mettre_a_jour_table(char *name, char *condition, char *new_values[]);
void supprimer_de_table(char *name, char *condition);
void selectionner_de_table(char *name, char *condition);
void sauvegarder_donnees(const char *filename);
void charger_donnees(const char *filename);
void free_all_tables(void);
void free_table(Table *table);


#endif // TABLE_H_INCLUDED
