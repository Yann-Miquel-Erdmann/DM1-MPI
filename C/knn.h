#ifndef KNN_H
#define KNN_H

#include "candidats.h"
#include "database.h"

extern int nb_class_max;  // penser à lui donner une valeur dans les mains selon l'application

// renvoie la classe majoritaire parmi les candidats dans lc
int classe_majoritaire(database db, candidats lc);

// renvoie la classe majoritaire parmi les k plus proches vecteurs de input dans db
int classify(database db, int k, vector input);

#endif
