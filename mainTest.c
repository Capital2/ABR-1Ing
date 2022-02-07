#include "arbre.h"
#include "dico.h"
#include <stdio.h>

int main(){

    /* TArbre a = arbreCons('c', 0, arbreConsVide(), arbreConsVide());
    a->fg = arbreCons('a', 0, arbreConsVide(), arbreConsVide());
    a->fg->fd = arbreCons('e', 0, arbreConsVide(), arbreConsVide());
    a->fg->fd->fd = arbreCons('i', 0, arbreConsVide(), arbreConsVide());
    a->fg->fd->fd->fg = arbreCons('\0', 7, arbreConsVide(), arbreConsVide()); // ci

    a->fg->fd->fg = arbreCons('\0', 9, arbreConsVide(), arbreConsVide()); // ce

    a->fg->fd->fg->fd = arbreCons('s', 0, arbreConsVide(), arbreConsVide());
    a->fg->fd->fg->fd->fg = arbreCons('\0', 8, arbreConsVide(), arbreConsVide()); // ces

    a->fg->fg = arbreCons('s', 0, arbreConsVide(), arbreConsVide());
    a->fg->fg->fg = arbreCons('\0', 1, arbreConsVide(), arbreConsVide()); // cas

    a->fd = arbreCons('d', 0, arbreConsVide(), arbreConsVide());
    a->fd->fg = arbreCons('e', 0, arbreConsVide(), arbreConsVide());
    a->fd->fg->fg = arbreCons('\0', 2, arbreConsVide(), arbreConsVide()); // de

    a->fd->fg->fg->fd = arbreCons('s', 0, arbreConsVide(), arbreConsVide());
    a->fd->fg->fg->fd->fg = arbreCons('\0', 4, arbreConsVide(), arbreConsVide()); // des

    a->fd->fg->fd = arbreCons('o', 0, arbreConsVide(), arbreConsVide());
    a->fd->fg->fd->fg = arbreCons('\0', 5, arbreConsVide(), arbreConsVide()); // do */
    char motPioche[100];
    int x=piocherMot(motPioche);
    if(x==1){
    /* for(int i=0;i<30;i++){
        if(motPioche[i]=='\0')
        break;
        printf("\n %c",motPioche[i]);
    } */
    
     TArbre a = arbreCons(motPioche[0], 0, arbreConsVide(), arbreConsVide());
     TArbre ar=a;
    for(int i=1;i<30;i++){
        if(motPioche[i]=='\0')
        {
            ar->fg=arbreCons('\0', 0, arbreConsVide(), arbreConsVide());
            break;
        }

        
        ar->fg = arbreCons(motPioche[i], 0, arbreConsVide(), arbreConsVide());
        ar=ar->fg;
    }

    dicoAfficher(a);
}
    /* printf("%d\n", dicoNbMotsDifferents(a));
    arbreSuppr(a); */
    return 0;
}