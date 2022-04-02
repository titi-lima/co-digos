#include <stdio.h>

int main(){
    float A, B, C;
    printf("\nZerinho ou... Um!\n");
    printf("\nEscolha 0 ou 1 para Alice: ");
    (scanf("%f", &A));
    printf("Escolha 0 ou 1 para Beto: ");
    scanf("%f", &B);
    printf("Escolha 0 ou 1 para Clara: ");
    scanf("%f", &C);
    
    if (B==1) {
        if (A==1) {
            if (C==0) {
                printf("\nC\n");
            }
            else if (C==1) {
                printf("\n*\n");
            }
            else printf("\nNúmeros inválidos. Tente novamente usando 0 ou 1.\n");
        }
        else if (A==0) {
                if (C==0) {
                printf("\nB\n");
            }
                else if (C==1) {
                printf("\nA\n");
            }
                else printf("\nNúmeros inválidos. Tente novamente usando 0 ou 1.\n");
        }
        else printf("\nNúmeros inválidos. Tente novamente usando 0 ou 1.\n");
    
    }
    else if (B==0) {
        if (A==1) {
            if (C==0) {
                printf("\nA\n");
            }
            else if (C==1) {
                printf("\nB\n");
            }
            else printf("\nNúmeros inválidos. Tente novamente usando 0 ou 1.\n");
        }
        else if (A==0) {
                if (C==0) {
                printf("\n*\n");
            }
                else if (C==1) {
                printf("\nC\n");
            }
                else printf("\nNúmeros inválidos. Tente novamente usando 0 ou 1.\n");
        }
        else printf("\nNúmeros inválidos. Tente novamente usando 0 ou 1.\n");
    }
    else if (A==0) {
        if (B==1) {
            if (C==0) {
                printf("\nB\n");
            }
            else if (C==1) {
                printf("\nA\n");
            }
            else printf("\nNúmeros inválidos. Tente novamente usando 0 ou 1.\n");
        }
        else if (B==0) {
                if (C==0) {
                printf("\n*\n");
            }
                else if (C==1) {
                printf("\nC\n");
            }
                else printf("\nNúmeros inválidos. Tente novamente usando 0 ou 1.\n");
        }
        else printf("\nNúmeros inválidos. Tente novamente usando 0 ou 1.\n");
    }
    else if (A==1) {
        if (B==1) {
            if (C==0) {
                printf("\nC\n");
            }
            else if (C==1) {
                printf("\n*\n");
            }
            else printf("\nNúmeros inválidos. Tente novamente usando 0 ou 1.\n");
        }
        else if (B==0) {
                if (C==0) {
                printf("\nA\n");
            }
                else if (C==1) {
                printf("\nB\n");
            }
                else printf("\nNúmeros inválidos. Tente novamente usando 0 ou 1.\n");
        }
        else printf("\nNúmeros inválidos. Tente novamente usando 0 ou 1.\n");
    
    }
    else if (C==1) {
        if (A==1) {
            if (B==0) {
                printf("\nB\n");
            }
            else if (B==1) {
                printf("\n*\n");
            }
            else printf("\nNúmeros inválidos. Tente novamente usando 0 ou 1.\n");
        }
        else if (A==0) {
                if (B==0) {
                printf("\nC\n");
            }
                else if (B==1) {
                printf("\nA\n");
            }
                else printf("\nNúmeros inválidos. Tente novamente usando 0 ou 1.\n");
        }
        else printf("\nNúmeros inválidos. Tente novamente usando 0 ou 1.\n");
    
    }
    else if (C==0) {
        if (B==1) {
            if (A==0) {
                printf("\nB\n");
            }
            else if (A==1) {
                printf("\nC\n");
            }
            else printf("\nNúmeros inválidos. Tente novamente usando 0 ou 1.\n");
        }
        else if (B==0) {
                if (A==0) {
                printf("\n*\n");
            }
                else if (A==1) {
                printf("\nA\n");
            }
                else printf("\nNúmeros inválidos. Tente novamente usando 0 ou 1.\n");
        }
        else printf("\nNúmeros inválidos. Tente novamente usando 0 ou 1.\n");
    }
    else printf("\nNúmeros inválidos. Tente novamente usando 0 ou 1.\n");
    
    return 0;
}