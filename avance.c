#include "avance.h"

void mode_avance(int taille_ligne, int* plateau){ // permet d ajouter 4 forteresses et 2 pieges
    ajouter_case(taille_ligne, FORTERESSE, 4, plateau);
    ajouter_case(taille_ligne, PIEGE, 2, plateau);
}

void ajouter_case(int taille_ligne, int type, int fois, int* plateau){ // permet d ajouter un type d objet aleatoirement un nombre definis de fois
    int index, x, y;
    srand(time(0));
    for (index = 0; index < fois; index++){
        do{
            x = rand()%taille_ligne;
            y = rand()%taille_ligne;
        } while(type_case(x, y, taille_ligne, plateau) != CASE_VIDE);
        plateau[x * taille_ligne + y] = type;
    }
}