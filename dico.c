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

int dicoNbMotsDifferents(TArbre a){
    if (a != NULL)
    {
        return ((a->val == '\0' ? 1 : 0) + dicoNbMotsDifferents(a->fd) + dicoNbMotsDifferents(a->fg));
    }else
    {
        return 0;
    }
    
}


int piocherMot(char *motPioche)
{
FILE* dico = NULL; // Le pointeur de fichier qui va contenir notre fichier
int nombreMots = 0, numMotChoisi = 0, i = 0;
int caractereLu = 0;
dico = fopen("dico.txt", "r"); // On ouvre le dictionnaire en lecture seule

// On vérifie si on a réussi à ouvrir le dictionnaire
if (dico == NULL) // Si on n'a PAS réussi à ouvrir le fichier
{
printf("\nImpossible de charger le dictionnaire de mots");
return 0; // On retourne 0 pour indiquer que la fonction a échoué
// À la lecture du return, la fonction s'arrête immédiatement.
}

// On compte le nombre de mots dans le fichier (il suffit de compter les
// entrées \n
do
{
caractereLu = fgetc(dico);
if (caractereLu == '\n')
nombreMots++;
} while(caractereLu != EOF);

numMotChoisi = nombreAleatoire(nombreMots); // On pioche un mot au hasard

// On recommence à lire le fichier depuis le début. On s'arrête lorsqu'on est arrivé au bon
//mot
rewind(dico);
while (numMotChoisi > 0)
{
caractereLu = fgetc(dico);
if (caractereLu == '\n')
numMotChoisi--;
}

/* Le curseur du fichier est positionné au bon endroit.
On n'a plus qu'à faire un fgets qui lira la ligne */
fgets(motPioche, 100, dico);

// On vire le \n à la fin
motPioche[strlen(motPioche) - 1] = '\0';
fclose(dico);

return 1; // Tout s'est bien passé, on retourne 1
}

int nombreAleatoire(int nombreMax)
{
srand(time(NULL));
return (rand() % nombreMax);
}

void dicoInsererMot(char mot[], TArbre pa) 

{   static int i=0;
 
 if(pa==NULL){
        pa=arbreCons(mot[i], 0, arbreConsVide(), arbreConsVide());
        if(mot[i]!='\0'){
            i++;
            dicoInsererMot(mot,pa->fg);
        }
    }

    
    if(mot[i] == pa->val){
        i++; 
       
        dicoInsererMot(mot,pa->fg);
    }
    
    if(mot[i]!=pa->val){
        dicoInsererMot(mot,pa->fd);
    }
    
    if(mot[i]=='\0' && pa->val!='\0'){
        pa->occur++;
    }

   

    

    }
