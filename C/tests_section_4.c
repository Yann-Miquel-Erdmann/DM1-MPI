#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "candidats.h"
#include "database.h"
#include "knn.h"

int nb_class_max = 3;
int main() {

    database b = create_empty_database(4);
    for (int i = 0; i < 4; i++) {
        b->datas[i].vector = create_zero_vector(2);
    }

    b->datas[0].vector->content[0] = 0;
    b->datas[0].vector->content[1] = 1;
    b->datas[0].class = 1;

    b->datas[1].vector->content[0] = 1;
    b->datas[1].vector->content[1] = 0;
    b->datas[1].class = 0;

    b->datas[2].vector->content[0] = 2;
    b->datas[2].vector->content[1] = 2;
    b->datas[2].class = 2;

    b->datas[3].vector->content[0] = -3;
    b->datas[3].vector->content[1] = -5;
    b->datas[3].class = 2;

    vector v = create_zero_vector(2);
    v->content[0] = 0;
    v->content[1] = 0;

    for (int k = 0; k < 5; k++) {
        int cm = classify(b, k, v);
        printf("%d\n", cm);
    }

    delete_database(b);
    delete_vector(v);

    return 0;
}
