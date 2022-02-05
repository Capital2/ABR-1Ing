#include "dico.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void affichageRec(TArbre a, char* str, short bufidx)
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

int dicoNbOcc(char mot[], TArbre a){
    TArbre ptr = a;
    for (int i = 0; i <= strlen(mot); i++)
    {
        if (ptr == NULL)
        {
            return 0;
        }
        
        if (ptr->val == mot[i])
        {
            if (ptr -> val == '\0')
            {
                return ptr->occur;
            }
            ptr = ptr->fg;
            
        }else
        {
            ptr = ptr ->fd;
            i--; // cycling
        }
        
    }
    return 0;
    
}