#include "arbre.h"
#include "dico.h"
#include <stdio.h>

int main(){

    TArbre a = arbreCons('c', 0, arbreConsVide(), arbreConsVide());
    a->fg = arbreCons('a', 0, arbreConsVide(), arbreConsVide());
    a->fg->fd = arbreCons('e', 0, arbreConsVide(), arbreConsVide());
    a->fg->fd->fd = arbreCons('i', 0, arbreConsVide(), arbreConsVide());
    a->fg->fd->fd->fg = arbreCons('\0', 1, arbreConsVide(), arbreConsVide());

    a->fg->fd->fg = arbreCons('\0', 0, arbreConsVide(), arbreConsVide());
    a->fg->fd->fg->fd = arbreCons('s', 0, arbreConsVide(), arbreConsVide());
    a->fg->fd->fg->fd->fg = arbreCons('\0', 1, arbreConsVide(), arbreConsVide());

    a->fg->fg = arbreCons('s', 0, arbreConsVide(), arbreConsVide());
    a->fg->fg->fg = arbreCons('\0', 1, arbreConsVide(), arbreConsVide());

    a->fd = arbreCons('d', 0, arbreConsVide(), arbreConsVide());
    a->fd->fg = arbreCons('e', 0, arbreConsVide(), arbreConsVide());
    a->fd->fg->fg = arbreCons('\0', 1, arbreConsVide(), arbreConsVide());

    a->fd->fg->fg->fd = arbreCons('s', 0, arbreConsVide(), arbreConsVide());
    a->fd->fg->fg->fd->fg = arbreCons('\0', 1, arbreConsVide(), arbreConsVide());

    a->fd->fg->fd = arbreCons('o', 0, arbreConsVide(), arbreConsVide());
    a->fd->fg->fd->fg = arbreCons('\0', 1, arbreConsVide(), arbreConsVide());

    dicoAfficher(a);
    arbreSuppr(a);
    return 0;
}