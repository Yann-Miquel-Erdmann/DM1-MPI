#include "vector.h"

#include <math.h>  // Attention à compiler avec l'option -lm
#include <stdio.h>
#include <stdlib.h>

vector create_zero_vector(int n) {
    vector v = malloc(sizeof(struct vector_s));
    v->taille = n;
    v->content = malloc(sizeof(unsigned char)*n);
    for (int i = 0; i<n; i++){
        v->content[i] = 0;
    }
    return v;
}

void delete_vector(vector v){
    free(v->content);
    free(v);
}

void print_vector(vector v){
    printf("(");
    for (int i = 0; i<v->taille; i++){
        printf("%d", v->content[i]);
        if (i<v->taille-1){
            printf(", ");
        }
    }
    printf(")");
}

double distance(vector u, vector v){
    double sum = 0;
    for (int i =0; i<u->taille; i++){
        sum += pow((u->content[i]-v->content[i]), 2);
    }
    return sqrt(sum);
}


