#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "jeu_quadrant.h"

int quadrant(vector v){
    assert(v->taille == 2);

    int d1 = v->content[0] >= 128;     
    int d2 = v->content[1] >= 128;     

    return d1 + 2*d2;
}

database fabrique_jeu_donnees(int db_size){
    database b = create_empty_database(db_size);

    for (int i = 0; i<db_size; i++){
        vector v = create_zero_vector(2);
        v->content[0] = rand()%256;
        v->content[1] = rand()%256;
        b->datas[i].vector = v;
        b->datas[i].class = quadrant(v);
    }

    return b;
}
