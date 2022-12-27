#include "deplacement.h"


int main() {
    int index;
    int plateau[25] = {CASE_VIDE, NOIR, CASE_VIDE, CASE_VIDE, CASE_VIDE, CASE_VIDE, CASE_VIDE, CASE_VIDE, CASE_VIDE, CASE_VIDE,CASE_VIDE, CASE_VIDE, CASE_VIDE, CASE_VIDE, CASE_VIDE,CASE_VIDE, CASE_VIDE, CASE_VIDE, CASE_VIDE, CASE_VIDE,CASE_VIDE, CASE_VIDE, CASE_VIDE, CASE_VIDE, CASE_VIDE};
    deplacement(5, 3, 4, 3, 4, plateau);
    for (index = 0; index < 25; index++){
        printf("%d ", plateau[index]);
    }
    return 0;
}
