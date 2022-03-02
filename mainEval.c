/* -------------------------------------------------------*/
/* Eval TP 1 ING 2021 (ISI) */
/* fichier "projet.c" */
/* -------------------------------------------------------*/
#include <stdio.h>
#include "dico.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
/* -------------------------------------------------------*/

#pragma region Piocher_mot
int nombreAleatoire(int nombreMax)
{
    // no srand here ya bro
    return (rand() % nombreMax);
}

int piocherMot(char *motPioche)
{
    FILE *dico = NULL; // Le pointeur de fichier qui va contenir notre fichier
    int nombreMots = 0, numMotChoisi = 0;
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
    } while (caractereLu != EOF);

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

#pragma endregion

int main(int argc, char **argv)
{
    srand(time(NULL));

    TArbre dico;
    char buffer[100];
    dico = arbreConsVide();
    strcpy(buffer, "gallon");
    dicoInsererMot(buffer, &dico);
    dicoAfficher(dico);
    printf("\n");

    strcpy(buffer, "munier");
    dicoInsererMot(buffer, &dico);
    dicoAfficher(dico);
    printf("\n");

    strcpy(buffer, "abenia");
    dicoInsererMot(buffer, &dico);
    dicoAfficher(dico);
    printf("\n");

    strcpy(buffer, "munier");
    dicoInsererMot(buffer, &dico);
    dicoAfficher(dico);
    printf("\n");

    strcpy(buffer, "mumu");
    dicoInsererMot(buffer, &dico);
    dicoAfficher(dico);
    printf("\n");

    strcpy(buffer, "alpha");
    dicoInsererMot(buffer, &dico);
    strcpy(buffer, "alphabeta");
    dicoInsererMot(buffer, &dico);
    strcpy(buffer, "al");
    dicoInsererMot(buffer, &dico);
    dicoAfficher(dico);
    printf("\n");
    printf("\"%s\" \t -> %d\n", "gallon", dicoNbOcc("gallon", dico));
    printf("\"%s\" \t\t -> %d\n", "mumu", dicoNbOcc("mumu", dico));
    printf("\"%s\" \t -> %d\n", "munier", dicoNbOcc("munier", dico));
    printf("\"%s\" \t -> %d\n", "gastro", dicoNbOcc("gastro", dico));
    printf("\"%s\" \t -> %d\n", "lespine", dicoNbOcc("lespine", dico));
    printf("\"%s\" \t\t -> %d\n", "aaa", dicoNbOcc("aaa", dico));
    printf("\n");

    char motpioche[100];

    for (int i = 0; i < 10; i++)
    {
        piocherMot(motpioche);
        dicoInsererMot(motpioche, &dico);
    }
    dicoAfficher(dico);
    arbreSuppr(dico);
}
/* -------------------------------------------------------*/
