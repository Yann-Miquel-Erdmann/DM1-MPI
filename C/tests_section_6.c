#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "knn.h"
#include "lecture_mnist.h"

#define TRAINING_SIZE 10000
#define TESTING_SIZE 1000

int nb_class_max = 10;
int main() {
    int** confusion_matrice = malloc(sizeof(int*)*nb_class_max);
    for (int i= 0; i<nb_class_max; i++){
        confusion_matrice[i] = malloc(sizeof(int)*nb_class_max);
        for(int j = 0 ; j<nb_class_max; j++){
            confusion_matrice[i][j] = 0;
        }
    }

    database train_db = NULL;
    database test_db = NULL;

    mnist_input(TRAINING_SIZE, &train_db, TESTING_SIZE, &test_db);

    for (int i = 0 ; i<TESTING_SIZE; i++){
        confusion_matrice[test_db->datas[i].class][classify(train_db, 3, test_db->datas[i].vector)] ++;
    }

    for (int i = 0; i<nb_class_max; i++){
        for (int j= 0; j<nb_class_max; j++){
            printf("%d  ", confusion_matrice[i][j]);
        }
        free(confusion_matrice[i]);        
        printf("\n");
    }
    free(confusion_matrice);

    delete_database(test_db);
    delete_database(train_db);

    
    return 0;
}
