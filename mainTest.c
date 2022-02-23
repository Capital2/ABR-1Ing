#include "arbre.h"
#include "dico.h"
#include <stdio.h>

int main(){

     /*TArbre a = arbreCons('c', 0, arbreConsVide(), arbreConsVide());
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
*/

char motPioche[]={'c','a','s','\0'};
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
   char mott[]="ce";
   
    dicoInsererMot(mott,&a);
    dicoInsererMot(mott,&a);
    dicoInsererMot("ces",&a);
     dicoInsererMot("kls",&a);
    dicoAfficher(a);
    /* printf("%d\n", dicoNbMotsDifferents(a));
    arbreSuppr(a); */
    return 0;
}