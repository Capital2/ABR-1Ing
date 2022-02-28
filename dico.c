#include "dico.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void affichageRec(TArbre a, char *str, short bufidx)
{
    if (!(arbreEstVide(a)))
    {
        if ((a->val != '\0'))
        {
            affichageRec(a->fd, str, bufidx);
            str[bufidx++] = a->val;
            affichageRec(a->fg, str, bufidx);
        }
        else
        {
            affichageRec(a->fd, str, bufidx);
            str[bufidx++] = a->val;
            printf("%s\n", str);
        }
    }
}

void dicoAfficher(TArbre a)
{
    char str[BUFFER_MAX];
    affichageRec(a, str, 0);
}

int dicoNbOcc(char mot[], TArbre a)
{
    TArbre ptr = a;
    for (int i = 0; i <= strlen(mot); i++)
    {
        if (ptr == NULL)
        {
            return 0;
        }

        if (ptr->val == mot[i])
        {
            if (ptr->val == '\0')
            {
                return ptr->occur;
            }
            ptr = ptr->fg;
        }
        else
        {
            ptr = ptr->fd;
            i--; // cycling
        }
    }
    return 0;
}

// Calculating the number of null characters.
int dicoNbMotsDifferents(TArbre a)
{
    if (a != NULL)
    {
        return ((a->val == '\0' ? 1 : 0) + dicoNbMotsDifferents(a->fd) + dicoNbMotsDifferents(a->fg));
    }
    else
    {
        return 0;
    }
}

// 1- reached a null child while mot isn't exhausted
// => insert rest into left children
// 2- mot's exhausted while still in arbre
// => browse right children till we can insert a '\0'
void dicoInsererMot(char mot[], TArbre *pa)
{
    // redundant code baddel brabbi
    if (*mot != '\0')
    {
        // while mot isn't exhauted
        if ((*pa) != NULL)
        {
            if ((*pa)->val == *mot)
            {
                dicoInsererMot(++mot, &((*pa)->fg));
            }
            else
            {
                dicoInsererMot(mot, &((*pa)->fd));
            }
        }else
        {
            // case 1
            do
            {
                *pa = arbreCons(*mot, 0, arbreConsVide(), arbreConsVide());
                pa = &((*pa)->fg);
                mot ++;
            } while (*mot != '\0');
            *pa = arbreCons(*mot, 1, arbreConsVide(), arbreConsVide());
        }
        
    }else
    { // *mot = '\0'

        if ((*pa) != NULL)
        {
            if ((*pa)->val == '\0')
            {
                ((*pa)->occur)++;
            }else
            {
                dicoInsererMot(mot, &((*pa)->fd));
            }
        }else
        {
            *pa = arbreCons(*mot, 1, arbreConsVide(), arbreConsVide());
        }    
    }

}