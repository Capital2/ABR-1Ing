#ifndef DICO_H_
#define DICO_H_
#include "arbre.h"
#define BUFFER_MAX 101 // + '\0'
/* -------------------------------------------------------*/
/* Primitives de gestion d’un dictionnaire */
/* -------------------------------------------------------*/

void dicoAfficher(TArbre a);
void dicoInsererMot(char mot[], TArbre *pa);
int dicoNbOcc(char mot[], TArbre a);
int dicoNbMotsDifferents(TArbre a); 
int dicoNbMotsTotal(TArbre a);
int piocherMot(char *motPioche);
int nombreAleatoire(int nombreMax);

/* -------------------------------------------------------*/
#endif