#include <stdio.h>
#include <string.h>
int main() {
    // para definir quais são diagonal principal: somar a coordenada da posicao na matriz +1
    int d, k, somador = 0;
    printf("Digite a dimensão da matriz: ");
    scanf("%d", &d);
    int daux = d, i = d, z = 0, flag = 0;
    char mat[d][d][31], senha[10000][10000][10000];
    printf("Digite agora as 4 strings que comporão a matriz %d x %d: ", d, d);
    for (d = 0; d < i; ++d) {
        for (daux = 0; daux < i; ++daux) {
            if (d == daux) {
                for (k = 0; k < (d + daux + 1); ++k) {
                    scanf(" %c", &mat[d][daux][k]);
                    if ((mat[d][daux][k]) < 97 || mat[d][daux][k] > 122)
                        printf("Caracter(es) invalido(s).\n");
                }
            } else
                scanf(" %[^\n]", mat[d][daux]);
            //printf("%s\n", &mat[0][0][0]);
        }
    }
    //printf("A:%c\n", mat[0][0][0]);
    for (d = 0; d < i; ++d) {
        for (daux = 0; daux < i; ++daux) {
            if (d == daux) {
                strncat(senha[d][daux], mat[d][daux][k], d + daux + 1); //concatenar os elementos da diagonal principal na senha
            } else {
                int q = strlen(mat[d][daux]), Q = q;
                for (q = 0; q < Q; ++q) {
                    int T = mat[d][daux][q];
                    somador += T; //inteiro que soma os valores ascii de elementos fora da diagonal principal
                }

                for (q = 0; q < Q; ++q) {
                    char var[q] = somador % 10;
                    somador /= 10;
                    strncat(senha[d][daux], var[q]); //concatenando os valores ascii somados à string da senha
                }
            }
        }
    }
    for (d = 0; d < i; ++d) {
        for (daux = 0; daux < i; ++daux) {
            printf("Sua senha é %s\n", senha[d][daux]);
        }
    }

    return 0;
}