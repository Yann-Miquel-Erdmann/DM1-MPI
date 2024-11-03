#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "jeu_quadrant.h"
#include "knn.h"

#define TRAINING_SIZE 500
#define TESTING_SIZE 1000

int nb_class_max = 4;
int main() {
    database db = fabrique_jeu_donnees(TRAINING_SIZE);


    vector v = create_zero_vector(2);
    int vrai_positifs = 0;

    for (int i = 0; i < TESTING_SIZE; i++) {
        v->content[0] = rand() % 256;
        v->content[1] = rand() % 256;
        if (classify(db, 1, v) == quadrant(v)) {
            vrai_positifs++;
        }
    }

    printf("%f\n", ((double)vrai_positifs) / TESTING_SIZE);

    delete_database(db);
    delete_vector(v);

    return 0;
}
