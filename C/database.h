#ifndef DATABASE_H
#define DATABASE_H

#include "vector.h"

struct classified_data_s {
  vector vector ;                   /* le vecteur */
  int    class  ;                   /* sa classe */
};

struct database_s {
  int size ;                        /* taille du jeu de données */
  struct classified_data_s* datas ; /* tableau contenant les données classifiées */
};

typedef struct database_s * database;

// crée une base de données vide
database create_empty_database(int n);

// supprime la base de données b
void delete_database(database b);

// affiche la base de données b
void print_data_base(database b);

#endif


