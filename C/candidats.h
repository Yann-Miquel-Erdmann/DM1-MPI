#ifndef CANDIDATS_H
#define CANDIDATS_H

#include "database.h"

typedef struct s_cellule* candidats;
struct s_cellule {
  int     indice ;              /* indice du point dans le jeu de donnée */
  double  distance ;            /* distance au point de recherche */
  candidats next;
};

// crée un maillon de liste chaînée avec ind comme indice dans la DB et dist comme distance au vecteur
candidats create_list(int ind, double dist);

// supprime un maillon et les maillons qui le suivent
void delete_liste(candidats lc);

// affiche la liste chaînée des candidats
void print_list_candidats(candidats l);

// insère le candidat à l'indice i dans db dans la liste chaînée pointée par pl de longueur r si sa distance à input le justifie et revoie la nouvelle longueur de pl 
int insertion_list(candidats* pl, int r, int k, database db, int i, vector input);

// renvoie une liste chaînée des k vecteurs les plus proches de input dans data
candidats pproche(database data, int k, vector input);

#endif
