#ifndef TABLUT_MANGE_H
#define TABLUT_MANGE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PION_BLANC 10
#define ROI 11
#define NOIR 12
#define BLANC 13
#define FORTERESSE 14
#define CASE_VIDE 15
#define PIEGE 16

int type_case(int x, int y, int taille_ligne, int* plateau);
void autour(int x, int y, int taille_ligne, int* plateau, int* pion_autour);
int est_ennemi(int type_pion);
void pion_mange(int x, int y, int taille_ligne, int* plateau);
int peut_etre_manger(int x, int y, int taille_ligne, int* plateau, int index);
void mange(int x, int y, int taille_ligne, int* plateau, int index);

#endif //TABLUT_MANGE_H
