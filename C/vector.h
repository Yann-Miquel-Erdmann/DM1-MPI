#ifndef VECTOR_H
#define VECTOR_H

struct vector_s {
    int taille;
    /* taille du tableau content */
    unsigned char* content;
    /* tableau d'éléments de 0, 255
     */
};
typedef struct vector_s* vector;

// crée un vecteur de taille n avec un zéro sur chaque coordonnée
vector create_zero_vector(int n);

// supprime le vecteur v
void delete_vector(vector v);

// affiche le vecteur v
void print_vector(vector v);

// revoie la distance euclidienne entre les vecteurs u et v de même taille
double distance(vector u, vector v);


#endif // VECTOR_H
