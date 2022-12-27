#ifndef TABLUT_MANGE_H
#define TABLUT_MANGE_H

#include <time.h>
#include "Fonction.h"

int type_case(int x, int y, int taille_ligne, int* plateau);
void autour(int x, int y, int taille_ligne, int* plateau, int* pion_autour);
int est_ennemi(int type_pion);
void pion_mange(int x, int y, int taille_ligne, int* plateau);
int peut_etre_manger(int x, int y, int taille_ligne, int* plateau, int index);
void mange(int x, int y, int taille_ligne, int* plateau, int index);

#endif //TABLUT_MANGE_H
