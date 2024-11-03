#include <stdlib.h>
#include <stdio.h>

#include "database.h"

database create_empty_database(int n){
    database b = malloc(sizeof(struct database_s));
    b->size = n;
    b->datas = malloc(n*sizeof(struct classified_data_s));
    for (int i =0; i<n; i++){
        b->datas[i].class = 0;
        b->datas[i].vector = NULL;
    }
    return b;
}

void delete_database(database b){
    for (int i = 0; i<b->size; i++){
        if (b->datas[i].vector != NULL){
            delete_vector(b->datas[i].vector);
        }
    }
    free(b->datas);
    free(b);
}

void print_data_base(database b){
    printf("{\n");
    for (int i = 0; i<b->size; i++ ){
        printf("\t");
        print_vector(b->datas[i].vector);
        printf("~> %d\n", b->datas[i].class);
    }
    printf("}\n");
}

