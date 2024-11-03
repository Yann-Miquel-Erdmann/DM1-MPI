#ifndef JEU_QUADRANT_H
#define JEU_QUADRANT_H


#include "vector.h"
#include "database.h"

// prend un vecteur appartenant à [0,255]x[0,255] et renvoie la classe qui lui est associée en coupant l'espace en 4 carrés
int quadrant(vector v);

// crée une base de données de db_size vecteurs uniformément répartis dans [0,255]x[0,255]
database fabrique_jeu_donnees(int db_size) ;



#endif
