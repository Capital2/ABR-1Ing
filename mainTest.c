#include "arbre.h"

int main(){

    TArbre a = arbreCons('c', 0, arbreConsVide(), arbreConsVide());
    a->fg = arbreCons('a', 0, arbreConsVide(), arbreConsVide());
    a->fg->fg = arbreCons('s', 0, arbreConsVide(), arbreConsVide());
    a->fg->fg->fg = arbreCons('\0', 1, arbreConsVide(), arbreConsVide());

    a->fd = arbreCons('d', 0, arbreConsVide(), arbreConsVide());
    a->fd->fg = arbreCons('e', 0, arbreConsVide(), arbreConsVide());
    a->fd->fg->fg = arbreCons('\0', 0, arbreConsVide(), arbreConsVide());
    
    arbreSuppr(a);
    return 0;
}