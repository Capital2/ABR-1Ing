
typedef Noeds *TArbre;
typedef struct Noeds Noeds;
struct Noeds
{
    int occur;
    char val;
    TArbre fg;
    TArbre fd;
};

/* -------------------------------------------------------*/
/* Primitives de gestion des arbres */
/* -------------------------------------------------------*/
TArbre arbreConsVide(void); int arbreEstVide(TArbre a);
TArbre arbreCons(char c, int n, TArbre fg, TArbre fd);
char arbreRacineLettre(TArbre a);
int arbreRacineNbOcc(TArbre a);
TArbre arbreFilsGauche(TArbre a);
TArbre arbreFilsDroit(TArbre a);
void arbreSuppr(TArbre a);
