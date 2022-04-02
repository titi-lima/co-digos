#include <stdio.h>

int main(){
    float A, B, C;
    printf("\nZerinho ou... Um!\n"); // fora do thehuxley
    printf("\nEscolha 0 ou 1 para Alice: "); // fora do thehuxley
    (scanf("%f", &A));
    printf("Escolha 0 ou 1 para Beto: "); // fora do thehuxley
    scanf("%f", &B);
    printf("Escolha 0 ou 1 para Clara: "); // fora do thehuxley
    scanf("%f", &C);
    
    if (B!=C) {
        if (A==B) {
            printf("\nC\n");
        }
        else 
            if (A!=B) {
                printf("\nB\n");            }
      }
    else
        if (A==B) {
            printf("*\n");
        }
        else printf("\nA\n");

    return 0;
}