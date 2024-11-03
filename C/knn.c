#include "knn.h"

#include <stdio.h>
#include <stdlib.h>

int classe_majoritaire(database db, candidats lc) {
    int* count = malloc(sizeof(int) * nb_class_max);
    for (int i = 0; i < nb_class_max; i++) {
        count[i] = 0;
    }

    while (lc != NULL) {
        count[db->datas[lc->indice].class]++;
        lc = lc->next;
    }

    int argmax = 0;
    int max = count[argmax];
    for (int i = 0; i < nb_class_max; i++) {
        if (count[i] > max) {
            argmax = i;
            max = count[i];
        }
    }
    
    free(count);

    return argmax;
}

int classify(database db, int k, vector input) {
    candidats lc = pproche(db, k, input);
    int cm = classe_majoritaire(db, lc);
    delete_liste(lc);
    return cm;
}
