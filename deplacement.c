#include "deplacement.h"

int deplacement(int taille_ligne, int x, int y, int x_depla, int y_depla, int* plateau){
    int diff, index, type, type_pion;
    type_pion = type_case(x, y, taille_ligne, plateau);
    if (x_depla < x){
        diff = x - x_depla;
        for (index = 0; index <= diff; index++){
            type = type_case(x - index, y, taille_ligne, plateau);
            if (type != CASE_VIDE){
                printf("Il y a un obstacle, vous ne pouvez pas vous déplacer jusqu'à ce point");
                return 0;
            }
        }
    }
    else if (x_depla > x){
        diff = x_depla - x;
        for (index = 0; index <= diff; index++){
            type = type_case(x + index, y, taille_ligne, plateau);
            if (type != CASE_VIDE){
                printf("Il y a un obstacle, vous ne pouvez pas vous déplacer jusqu'à ce point");
                return 0;
            }
        }
    }
    else if (y_depla < y){
        diff = y - y_depla;
        for (index = 0; index <= diff; index++){
            type = type_case(x, y - index, taille_ligne, plateau);
            if (type != CASE_VIDE){
                printf("Il y a un obstacle, vous ne pouvez pas vous déplacer jusqu'à ce point");
                return 0;
            }
        }
    }

    else if (y_depla > y){
        diff = y - y_depla;
        for (index = 0; index <= diff; index++){
            type = type_case(x, y + index, taille_ligne, plateau);
            if (type != CASE_VIDE){
                printf("Il y a un obstacle, vous ne pouvez pas vous déplacer jusqu'à ce point");
                return 0;
            }
        }
    }
    plateau[x * taille_ligne + y] = CASE_VIDE;
    plateau[x_depla * taille_ligne + y] = type_pion;
    return 1;
}


int condition(int taille_ligne, int x, int y, int x_depla, int y_depla, int type_pion){
    if (type_pion != NOIR || type_pion != BLANC) {
        printf("Il n'y a pas de pion sur cette case");
        return 0;
    }
    else if (x_depla != x && y_depla != y){
        printf("Vous ne pouver pas vous déplacer de cette manière");
        return 0;
    }
    else if (x_depla == x && y_depla == y){
        printf("Vous ne vous êtes pas déplacer");
        return 0;
    }
}