#include "mange.h"


int type_case(int x, int y, int taille_ligne, int* plateau){ // renvoie le type d objet qui se situe sur la case, si il n y a rien, renvoie CASE_VIDE
    if (plateau[x * taille_ligne + y] == PION_BLANC || plateau[x * taille_ligne + y] == ROI) {
        return BLANC;
    }
    else if (plateau[x * taille_ligne + y] == NOIR){
        return NOIR;
    }
    else if (plateau[x * taille_ligne + y] == FORTERESSE){
        return FORTERESSE;
    }
    return CASE_VIDE;
}


void autour(int x, int y, int taille_ligne, int* plateau, int* pion_autour){ // determine le type des cases qui se trouve autour du pion en (x, y)
    if (y - 1 != -1){
        pion_autour[0] = type_case(x, y - 1, taille_ligne, plateau);
    }
    if (x - 1 != -1){
        pion_autour[1] = type_case(x - 1, y, taille_ligne, plateau);
    }
    if (y + 1 < taille_ligne){
        pion_autour[2] = type_case(x, y + 1, taille_ligne, plateau);
    }
    if (x + 1 < taille_ligne){
        pion_autour[3] = type_case(x + 1, y, taille_ligne, plateau);
    }
}


int est_ennemi(int type_pion){ // renvoie la couleur oppose a type_pion
    if (type_pion == NOIR){
        return BLANC;
    }
    return NOIR;
}


void pion_mange(int x, int y, int taille_ligne, int* plateau){
    int pion_autour[4] = {0, 0, 0, 0};
    int index, type_pion = type_case(x, y, taille_ligne, plateau), couleur_ennemi = est_ennemi(type_pion);
    int pion_deux_cases;
    autour(x, y, taille_ligne, plateau, pion_autour);
    for (index = 0; index < 4; index++){
        if (pion_autour[index] == couleur_ennemi){
            pion_deux_cases = peut_etre_manger(x, y, taille_ligne, plateau, index);
            if (pion_deux_cases == type_pion || pion_deux_cases == FORTERESSE){
                mange(x, y, taille_ligne, plateau, index);
            }
            else if (pion_autour[index] == BLANC && pion_deux_cases == PIEGE){
                mange(x, y, taille_ligne, plateau, index);
            }
        }
    }
}


int peut_etre_manger(int x, int y, int taille_ligne, int* plateau, int index){ // renvoie le type du pion qui se situe a deux cases du pion en (x, y)
    if (index == 0){
        if (y - 2 > -1){
            return type_case(x, y - 2, taille_ligne, plateau);
        }
    }
    else if (index == 1){
        if (x - 2 > -1){
            return type_case(x - 2, y, taille_ligne, plateau);
        }
    }
    else if (index == 2){
        if (y + 2 < taille_ligne){
            return type_case(x, y + 2, taille_ligne, plateau);
        }
    }
    else{
        if (x + 2 < taille_ligne){
            return type_case(x + 2, y, taille_ligne, plateau);
        }
    }
    return 0;
}


void mange(int x, int y, int taille_ligne, int* plateau, int index){ // mange le pion situé a coté du pion en (x, y), le remplace par une case vide
    if (index == 0){
        plateau[x * taille_ligne + y - 1] = CASE_VIDE;
    }
    else if (index == 1){
        plateau[(x - 1) * taille_ligne + y] = CASE_VIDE;
    }
    else if (index == 2){
        plateau[x * taille_ligne + y + 1] = CASE_VIDE;
    }
    else{
        plateau[(x + 1) * taille_ligne + y] = CASE_VIDE;
    }
}
