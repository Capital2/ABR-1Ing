#include "arbre.h"
#include "dico.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

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

int main()
{

    // TArbre a = arbreCons('c', 0, arbreConsVide(), arbreConsVide());
    // a->fg = arbreCons('a', 0, arbreConsVide(), arbreConsVide());
    // a->fg->fd = arbreCons('e', 0, arbreConsVide(), arbreConsVide());
    // a->fg->fd->fd = arbreCons('i', 0, arbreConsVide(), arbreConsVide());
    // a->fg->fd->fd->fg = arbreCons('\0', 7, arbreConsVide(), arbreConsVide()); // ci

    // a->fg->fd->fg = arbreCons('\0', 9, arbreConsVide(), arbreConsVide()); // ce

    // a->fg->fd->fg->fd = arbreCons('s', 0, arbreConsVide(), arbreConsVide());
    // a->fg->fd->fg->fd->fg = arbreCons('\0', 8, arbreConsVide(), arbreConsVide()); // ces

    // a->fg->fg = arbreCons('s', 0, arbreConsVide(), arbreConsVide());
    // a->fg->fg->fg = arbreCons('\0', 1, arbreConsVide(), arbreConsVide()); // cas

    // a->fd = arbreCons('d', 0, arbreConsVide(), arbreConsVide());
    // a->fd->fg = arbreCons('e', 0, arbreConsVide(), arbreConsVide());
    // a->fd->fg->fg = arbreCons('\0', 2, arbreConsVide(), arbreConsVide()); // de

    // a->fd->fg->fg->fd = arbreCons('s', 0, arbreConsVide(), arbreConsVide());
    // a->fd->fg->fg->fd->fg = arbreCons('\0', 4, arbreConsVide(), arbreConsVide()); // des

    // char motPioche[] = {'c', 'a', 's', '\0'};
    // TArbre a = arbreCons(motPioche[0], 0, arbreConsVide(), arbreConsVide());
    // TArbre ar = a;

    // for (int i = 1; i < 30; i++)
    // {
    //     if (motPioche[i] == '\0')
    //     {
    //         ar->fg = arbreCons('\0', 0, arbreConsVide(), arbreConsVide());
    //         break;
    //     }

    //     ar->fg = arbreCons(motPioche[i], 0, arbreConsVide(), arbreConsVide());
    //     ar = ar->fg;
    // }
    // char mott[] = "ce";

    // dicoInsererMot(mott, &a);
    // dicoInsererMot(mott, &a);
    // dicoInsererMot("ces", &a);
    // dicoInsererMot("kls", &a);

    srand(time(NULL));
    TArbre a;
    char motpioche[100];

    for (int i = 0; i < 100; i++)
    {
        piocherMot(motpioche);

        dicoInsererMot(motpioche, &a);
    }

    // dicoInsererMot("Oie", &a);
    // dicoInsererMot("Tortue", &a);
    // dicoInsererMot("Ours", &a);
    // dicoInsererMot("Oursin", &a);
    printf("%d\n", dicoNbMotsTotal(a));
    dicoAfficher(a);
    arbreSuppr(a);
    return 0;
}