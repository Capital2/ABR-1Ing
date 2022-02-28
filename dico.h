#ifndef DICO_H_
#define DICO_H_
#include "arbre.h"
#define BUFFER_MAX 101 // + '\0'
/* -------------------------------------------------------*/
/* Primitives de gestion d’un dictionnaire */
/* -------------------------------------------------------*/

void dicoAfficher(TArbre a);
void dicoInsererMotIter(char mot[], TArbre *pa); // TODO (changed *pa) add alphabetic
int dicoNbOcc(char mot[], TArbre a);
int dicoNbMotsDifferents(TArbre a); 
int dicoNbMotsTotal(TArbre a); // todo
/* -------------------------------------------------------*/
#endif