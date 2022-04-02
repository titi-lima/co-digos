#include <stdio.h>
#include <stdlib.h>

int **leMatriz(int **matriz) {
    int aux, aux2;
    matriz = (int **)realloc(matriz, 9 * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro na alocacao.\n");
        exit(1);
    }
    for (aux = 0; aux < 9; ++aux) {
        matriz[aux] = (int *)realloc(matriz[aux], 9 * sizeof(int));
        if (matriz[aux] == NULL) {
            printf("Erro na alocacao.\n");
            exit(1);
        }
        for (aux2 = 0; aux2 < 9; ++aux2) {
            scanf("%d", &matriz[aux][aux2]);
        }
    }
    return matriz;
}

void liberarMatriz(int **matriz) {
    int aux;
    for (aux = 0; aux < 9; ++aux) {
        free(matriz[aux]);
    }
    free(matriz);
}

int verificaMatrizGlobal(int **matriz) {
    int aux, aux2, aux3;
    for(aux=0; aux<9; ++aux) {
        for(aux2=0; aux2<9; ++aux2) {
            for(aux3=aux2+1; aux3<9; ++aux3) { //checa na horizontal
                if(matriz[aux][aux2] == matriz[aux][aux3]) {
                    printf("NO\nGLOBAL\n");
                    return 1;
                }
            }
            for(aux3=aux1+1; aux3<9; ++aux3) { //checa na vertical
                if(matriz[aux][aux2] == matriz[aux3][aux2]) {
                    printf("NO\nGLOBAL\n");
                    return 1;
                }
            }
        }
    }
    return 0;
}

int verificaMatrizInterna(int **matriz) {
    int aux, x, auy=0, aux2, y=0, j, k;
    for(aux=0; aux<3; ++aux) { // tem 9 blocos 3x3 pra procurar e cada for roda 3 vezes
        for(aux2=0; aux2<7; aux2+=3) { // entra na "posicao 0, 0" de cada bloco
            for(x=aux2; x<aux2+3; ++x) { // percorre cada bloco no eixo x
                for(y=auy; y<auy+3; ++y) { // percorre cada bloco no eixo y
                    for(j=x; j<x+3; ++j) {
                        for(k=y+1; k<y+3; ++k) {
                            if(matriz[x][y] == matriz[j][k]) {
                                printf("NO\nLOCAL\n");
                                return 1;
                            }
                        }
                    }
                }
            }
        }
        if(x==9) {
            auy+=3; // depois de olhar todos os 3 blocos horizontais, pula para o proximo bloco verticalmente
        }
    }
    return 0;
}

int main() {
    int **matriz = NULL, aux;
    matriz = leMatriz(matriz);
    aux = verificaMatrizGlobal(matriz);
    if(aux==0) {
        aux = verificaMatrizInterna(matriz);
    }
    liberarMatriz(matriz);
    if (aux == 0) {
        printf("YES\n");
    }
    return 0;
}