#include "arbre.h"
#include <stdlib.h>

TArbre arbreConsVide(void){
    TArbre ptr = NULL;
    return ptr;
}

TArbre arbreCons(char c, int n, TArbre fg, TArbre fd){

    TArbre ptr = malloc(sizeof(Noeds));
    if (!ptr) {
        perror("malloc failed");
        exit(1);
    }
    ptr->occur = n;
    ptr->val = c;
    ptr->fg = fg;
    ptr->fd = fd;

    return ptr;
}

int arbreEstVide(TArbre a){
    return (a == NULL);
}

char arbreRacineLettre(TArbre a){
    if (a != NULL)
    {
        return a->val;   
    }
    perror("Empty tree");
    exit(1);
}

int arbreRacineNbOcc(TArbre a){
    if (a != NULL)
    {
        return a->occur;   
    }
    perror("Empty tree");
    exit(1);
}

TArbre arbreFilsGauche(TArbre a){
    if (a != NULL)
    {
        return a->fg;   
    }
    perror("Empty tree");
    exit(1);
}

TArbre arbreFilsDroit(TArbre a){
    if (a != NULL)
    {
        return a->fd;   
    }
    perror("Empty tree");
    exit(1);
}

void arbreSuppr(TArbre a){
    // Postfixe
    if (a != NULL)
    {
        arbreSuppr(a->fg);
        arbreSuppr(a->fd);
        free(a);
    }    
}

