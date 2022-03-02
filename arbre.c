#include "arbre.h"
#include <stdio.h>
#include <stdlib.h>

// creer une arbre vide
TArbre arbreConsVide(void){
    TArbre ptr = NULL;
    return ptr;
}

// creer un noeud d'arbre
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

// tester si l'arbre est vide
int arbreEstVide(TArbre a){
    return (a == NULL);
}

// retourne la valeur stocké dans un noead s'il existe
char arbreRacineLettre(TArbre a){
    if (a != NULL)
    {
        return a->val;   
    }
    perror("Empty tree");
    exit(1);
}

// retourne le nbr d'occurrence stocké dans un noead
int arbreRacineNbOcc(TArbre a){
    if (a != NULL)
    {
        return a->occur;   
    }
    perror("Empty tree");
    exit(1);
}

// retourne le fils gauche d'un noeud
TArbre arbreFilsGauche(TArbre a){
    if (a != NULL)
    {
        return a->fg;   
    }
    perror("Empty tree");
    exit(1);
}

// retourne le fils droit d'un noeud
TArbre arbreFilsDroit(TArbre a){
    if (a != NULL)
    {
        return a->fd;   
    }
    perror("Empty tree");
    exit(1);
}

// libère l'espace mémoire alloué à l'arbre
void arbreSuppr(TArbre a){
    // parcours postfixe est necessaire
    if (a != NULL)
    {
        arbreSuppr(a->fg);
        arbreSuppr(a->fd);
        free(a);
    }    
}

