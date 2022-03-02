#include "dico.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#pragma region Dico_Afficher

// Affichage postfixe de l'arbre
void affichageRec(TArbre a, char *str, short bufidx)
{
    // Postfix
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
//Affichage Infixe de l'arbre
void affichageRecInf(TArbre a, char *str, short bufidx)
{
    // Infixe
    if (!(arbreEstVide(a)))
    {
        if ((a->val != '\0'))
        {
            char temp[100];
            for (int i = 0; i < bufidx; i++)
            {
                temp[i] = str[i];
            }     
            temp[bufidx] = a->val;
            affichageRecInf(a->fg, temp, bufidx+1);
            affichageRecInf(a->fd, str, bufidx);
        }
        else
        {
            for (int i = 0; i < bufidx; i++)
            {
                printf("%c", str[i]);
            }
            printf("\n");
            affichageRecInf(a->fd, str, bufidx);
        }
    }
}

// Affichage de l'arbre
void dicoAfficher(TArbre a)
{
    char str[BUFFER_MAX];
    affichageRec(a, str, 0);
}
#pragma endregion

// retourne le nbr d'occurrence d'un mot dans l'arbre a
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
            // le caractère est retenue donc on passe au fils gauche
            ptr = ptr->fg;
        }
        else
        {
            // le caractère est rejeté, on passe au fils droit
            ptr = ptr->fd;
            i--;
        }
    }
    return 0;
}

// retoune le nbr de mots differents
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
void dicoInsererMot(char mot[], TArbre *pa)
{
    //ptr est le noeud courant, et pa son parent
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

    // tant que le caractere du mot (*mot) est superieur on parcour l'arbre
    while ((*mot >= (*ptr)->val))
    {
        // on enregistre le parent
        // si meme caractere : parcours fils gauche
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
            pa = ptr;
            ptr = &((*ptr)->fd);
        }
        if (*ptr == NULL)
        {
            break;
        }
    }

    // caractere est inferieur donc on doit inserer le reste du mot à gauche
    // on teste si on est dans le fils gauche ou droit du pere;
    // fils droit par default
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

// retourne le nbr de mots total inséré dans l'arbre
int dicoNbMotsTotal(TArbre a)
{
    if (a != NULL)
    {
        return a->occur + dicoNbMotsTotal(a->fd) + dicoNbMotsTotal(a->fg);
    }
    return 0;
}