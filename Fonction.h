#ifndef FONCTION_H
#define FONCTION_H

#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#define PION_BLANC 35
#define ROI 38
#define NOIR 88
#define FORTERESSE 36
#define CASE_VIDE 39
#define BLANC 0
#define PIEGE 16

#define TRUE 1

void Plateau (int N, int *carte);
void AfficherPlateau (int N, int *carte);

void Color(int couleurDuTexte,int couleurDeFond);

#endif