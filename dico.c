#include "dico.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#pragma region Dico_Afficher
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
#pragma endregion

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

#pragma region Inserer_mot
// On veut insérer un mot en respectant l'ordre alphabétique
// On cree une procedure qui insere un noeud dans l'arbre
void _inserer(char mot[], TArbre *pa)
{
}
// void dicoInsererMot(char mot[], TArbre *pa)
// {
//     if (*mot >= (*pa)->val)
//     {
//         if (*mot == (*pa)->val)
//         {
//             dicoInsererMot(mot++, (*pa)->fg);
//         }
//         else
//         {
//             dicoInsererMot(mot, (*pa)->fd);
//         }
//     }
//     else
//     {
//         /* code */
//     }
// }

// if *mot lesser than val we move the node to the fd of the new one
void dicoInsererMot(char mot[], TArbre *pa)
{
    TArbre *ptr = pa;

    if (*ptr == NULL)
    {
        // cas d'une arbre vide
        // on insere le mot
        *pa = arbreCons(*mot, 0, NULL, NULL);
        for (int i = 1; i < strlen(mot); i++)
        {
            (*pa)->fg = arbreCons(mot[i], 0, NULL, NULL);
            pa = &((*pa)->fg);
        }
        (*pa)->fg = arbreCons('\0', 1, NULL, NULL);
        return;
    }
    // '\0' is the smallest
    // tq le caractere est superieur on parcour l'arbre
    while ((*mot >= (*ptr)->val))
    {
        // on enregistre le parent
        // si meme caractere parcours fils gauche
        if (*mot == (*ptr)->val)
        {
            if (*mot == '\0')
            {
                (*ptr)->occur++;
                return;
            }
            mot++;
            pa = ptr;
            ptr = &((*ptr)->fg);
        }
        else // fils droit sinon
        {
            // next checks can be here
            pa = ptr;
            ptr = &((*ptr)->fd);
        }
        if (*ptr == NULL)
        {
            break;
        }
    }

    // caractere est inferieur donc on doit inserer le reste du mot à gauche
    // on test si on est dans le fils gauche ou droit du pere;
    // probleme si les 2 fils sont null: fils droit par default
    if ((*pa)->fd == *ptr)
    {
        TArbre temp = (*pa)->fd;
        (*pa)->fd = arbreCons(*mot, (*mot == '\0') ? 1 : 0, NULL, temp);
    }
    else
    {
        if (*pa != *ptr)
        {
            TArbre temp = (*pa)->fg;
            (*pa)->fg = arbreCons(*mot, (*mot == '\0') ? 1 : 0, NULL, temp);
        }
        else
        {
            // cas de l'insertion dans racine
            *pa = arbreCons(*mot, 0, NULL, *ptr);
            ptr = pa;
        }
    }

    // et on insere le reste du mot
    if (*mot != '\0')
    {
        for (int i = 1; i < strlen(mot); i++)
        {
            (*ptr)->fg = arbreCons(mot[i], 0, NULL, NULL);
            ptr = &((*ptr)->fg);
        }
        (*ptr)->fg = arbreCons('\0', 1, NULL, NULL);
    }
}
#pragma endregion

int dicoNbMotsTotal(TArbre a)
{
    if (a != NULL)
    {
        return a->occur + dicoNbMotsTotal(a->fd) + dicoNbMotsTotal(a->fg);
    }
    return 0;
}