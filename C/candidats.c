#include "candidats.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

candidats create_list(int ind, double dist) {
    candidats c = malloc(sizeof(struct s_cellule));
    c->indice = ind;
    c->distance = dist;
    c->next = NULL;
    return c;
}

void delete_liste(candidats lc) {
    if (lc != NULL) {
        delete_liste(lc->next);
    }
    free(lc);
}

void print_list_candidats(candidats l) {
    printf("[");
    if (l != NULL) {
        printf("{i : %d, d : %f}", l->indice, l->distance);
        l = l->next;
    }
    while (l != NULL) {
        printf("; {i : %d, d : %f}", l->indice, l->distance);
        l = l->next;
    }
    printf("]\n");
}

int insertion_list(candidats* pl, int r, int k, database db, int i, vector input) {
    if (k==0){
        return r;  // renvoie 0
    }
    
    double d = distance(input, db->datas[i].vector);
    if (r < k) {  // la len(pl) < k donc on ajoute l'élément d'indice i
        candidats prec = NULL;
        candidats suiv = *pl;
        while (suiv != NULL && suiv->distance > d) {
            prec = suiv;
            suiv = suiv->next;
        }
        
        candidats m = create_list(i, d);
        m->next = suiv;
        
        if (prec == NULL) {
            *pl = m;
        }else{
            prec->next = m; 
        }

        return r + 1;
    } else {  // len(pl) = k donc on ajoute l'élément d'indice i seulement s'il est plus proche de input que le premier maillon de pl
        if ((*pl)->distance > d) {
            candidats prec = NULL;
            candidats suiv = *pl;
            while (suiv != NULL && suiv->distance > d) {
                prec = suiv;
                suiv = suiv->next;
            }

            candidats m = create_list(i, d);
            m->next = suiv;
            prec->next = m;

            candidats start = (*pl)->next; 
            (*pl)->next = NULL;
            free(*pl);
            *pl = start;
        }

        return r;
    }
}

candidats pproche(database data, int k, vector input){
    candidats l = NULL;
    
    int r = 0;
    for (int i = 0; i<data->size; i++){
        r = insertion_list(&l, r, k, data, i, input);
    }
    return l;
}


