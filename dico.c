#include "dico.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void affichageRec(TArbre a, char str[BUFFER_MAX], short bufidx)
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


// void dicoAfficher(TArbre a){
//     if (a == NULL)
//         return;
//     int isLeft;
//     char buffer[50] = "";
//     // Create an empty stack and push (a) to it
//     stackPtr nodeStack = NULL;
//     push(nodeStack, a, 1);

//     while (!checkEmpty(nodeStack)) {
//         // Pop the top item from stack and print it
//         isLeft = nodeStack->isLeft;
//         TArbre node = pop(nodeStack);
//         // if left child: concat, if right child: delete and concat
//         if (isLeft)
//         {
//             // override stack?
//             strcat(buffer,node->val);
//         }else
//         {
//             // treat first case buffer[0]
//             buffer[strlen(buffer)-1] = node->val;
//         }

//         // Push right and left children of the popped node to stack
//         if (!arbreEstVide(node->fd))
//             push(nodeStack, node->fd, 0);
//         if (!arbreEstVide(node->fg))
//             push(nodeStack, node->fg, 1);
//         if (arbreEstVide(node->fd) || arbreEstVide(node->fg))
//         {
//             /* code */
//         }

//     }
//}

void dicoAfficher(TArbre a)
{
    char str[BUFFER_MAX];
    affichageRec(a, str, 0);
}
