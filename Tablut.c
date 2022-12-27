/* IMPORTAION DE FONCTION EXTERNE */
#include "Fonction.c"

int* carte = NULL;
int N;
int JOUEUR;

void mon_fonction_de_sortie(void) {
    printf("Le programme se termine maintenant.\n");
    printf("%d", JOUEUR);
    for (int i = 0; i < N*N; i++) {
        printf("%c", carte[i]);
    }

    FILE *f = fopen("text.txt", "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(f, "%d", JOUEUR);
    for (int i = 0; i < N * N; i++) {
        fprintf(f, "%c", carte[i]);
    }

    fclose(f);
}

int main () {
    /*Voulez-vous remprendre votre partie ?*/
    char sav; 
    N = 2;

    atexit(mon_fonction_de_sortie);

    printf("Voulez-vous prendre votre ancienne partie sauvegarder ? (O/N)");
    while (sav != 79 & sav != 78 & sav != 110 & sav != 111) {
        scanf("%c", &sav);
    }

    if (sav == 79 || sav == 111) {
        FILE* F = fopen("text.txt","r");

        int taille = 0;
        if (F != NULL)
        {
            while(fgetc(F) != EOF) {taille ++;}
        }

        taille = sqrt(taille-1);
        carte = malloc(taille * taille * sizeof(int));
        int caract = 0;
        int position = 0;

        fclose(F);

        F = fopen("text.txt","r");
        JOUEUR = fgetc(F) - 48;
        if (F != NULL)
        {
            do
            {
                caract = fgetc(F);
                carte[position] = caract;
                position = position +1;
            } while (caract != EOF);
        }
    
        N = taille;
        fclose(F);
    }

    else if (sav == 78 || sav == 110)
    {
        JOUEUR = 1;
        N = N;
        do {
        printf("\nDonner la valeur N pour la largeur et longeur du plateau \n");
        printf("La valeur doit etre une valeur positive et impaire () : ");
        scanf("%d", &N);
        } while (N%2 == 0);

        carte = malloc(N * N * sizeof(int));
        Plateau(N, carte);
    }

    Afficher_Plateau(N, carte);

    while (GAME == TRUE) {
        printf("\n%d JOUEUR", JOUEUR);
        int quit=1;

        if (JOUEUR == 1) {
            printf("\nJOUEUR 1");
            Deplacement_Pion_Blanc (N, carte);
            Afficher_Plateau(N, carte);
        }

        if (JOUEUR == 2) {
            printf("\nJOUEUR 2");
            Deplacement_Pion_Noir (N, carte);
            Afficher_Plateau(N, carte);
        }

        JOUEUR += 1;
        if (JOUEUR >= 3) {
            JOUEUR = 1;
        }

        printf("\nVoulez-vous quitter ? (O/N)");

        do {
            scanf("%c", &quit);
        }
        while (quit != 79 & quit != 78 & quit != 110 & quit != 111);

        if (quit == 79 || quit == 111) {
            break;
        }
    }
}