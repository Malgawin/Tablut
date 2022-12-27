#include "Fonction.h"


void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}


void Afficher_Plateau (int N, int *carte) {
    for (int i=0; i<(N*N); i=i+N) {
        printf("\n");
        for (int j=0; j<N; j++) {
            if (carte[i+j] == PION_BLANC) {
                Color(12,0);
                printf("%3c", carte[i+j]);
                Color(15, 0);
            }
            else if (carte[i+j] == PION_NOIR)
            {
                Color(10,0);
                printf("%3c", carte[i+j]);
                Color(15, 0);
            }

            else if (carte[i+j] == ROI)
            {
                Color(9,0);
                printf("%3c", carte[i+j]);
                Color(15, 0);
            }
            
            else {
                printf("%3c", carte[i+j]);
            }
        }
    }
}


void Plateau (int N, int *carte) {
    printf("\n' pour les cases vides \n");
    Color(12,0);
    printf("# pour les points blanc\n");
    Color(9,0);
    printf("& pour le roi \n");
    Color(10,0);
    printf("= pour les points noir \n");
    Color(15, 0);

    for (int i=0; i<(N*N); i++) {
        carte[i] = CASE_VIDE;
    }

    carte[0] = FORTERESSE;
    carte[N-1] = FORTERESSE;
    carte[N*(N-1)] = FORTERESSE;
    carte[(N*N)-1] = FORTERESSE;

    carte[N/2 + N/2 * N] = ROI;

    /* AFFICHAGE DES POINTS BLANCS */
    for (int i=1; i<((N-1)/4 +1); i++) {
        carte[(N/2)+i + (N/2) * N] = PION_BLANC;
        carte[(N/2)-i + (N/2) * N] = PION_BLANC;
        carte[(N/2) + ((N/2)-i) * N] = PION_BLANC;
        carte[(N/2) + ((N/2)+i) * N] = PION_BLANC;
    }

    /* AFFICHAGE DES POINTS NOIRS */
    for (int i=1; i<((N/2)-((N-1)/4)+1); i++) {
        carte[(N/2)+(((N-1)/4)+i) + ((N/2)) * N] = PION_NOIR;

        carte[(N/2)-(((N-1)/4)+i) + ((N/2)) * N] = PION_NOIR;

        carte[(N/2) + ((N/2)+(((N-1)/4)+i)) * N] = PION_NOIR;

        carte[(N/2) + ((N/2)-(((N-1)/4)+i)) * N] = PION_NOIR;
    }
    int PointNrestant = ((N-1)/2-((N/2)-((N-1)/4)));
    for (int i=0; i<PointNrestant +1; i++) {
        carte[((N/2)-PointNrestant/2)+i] = PION_NOIR;
        carte[((N/2 * N)+(PointNrestant/2)*N)-i*N] = PION_NOIR;
        carte[((N/2)-i)+(N*(N-1))+PointNrestant/2] = PION_NOIR;
        carte[(N/2 * N)+i*N+(N-1)-(PointNrestant/2*N)] = PION_NOIR;
    }
}
