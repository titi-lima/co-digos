#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    int pontuacao;
    int tentativas;
} Competidor;

Competidor *leCompetidores(Competidor *competidores, int qtdAtual, int qtdTotal) {
    int aux;
    static int cont = 0;
    if (cont == 0) {
        competidores = (Competidor *)malloc(sizeof(qtdAtual * sizeof(char[50])));
        if (competidores == NULL) {
            printf("Erro na alocacao.\n");
            exit(1);
        }
    } else
        competidores = (Competidor *)realloc(competidores, sizeof(qtdAtual * sizeof(char[50])));

    for (aux = 0; aux < qtdAtual; ++aux) {
        printf("\nDigite o nome do competidor: ");
        scanf(" %29[^\n]", competidores[aux].nome);
        competidores[aux].pontuacao = 0;
    }
    ++cont;
    return competidores;
}

int **colocarTesouros(int **matriz, int n, int *numTesouros) {
    int aux, aux2;
    for (aux = 0; aux < n; ++aux) { // zera a matriz
        for (aux2 = 0; aux2 < n; ++aux2) {
            matriz[aux][aux2] = 0;
        }
    }

    for (aux = 0; aux < n; ++aux) { // o ovo sera identificado por ter valor 1
        for (aux2 = 0; aux2 < n; ++aux2) {
            if ((4 * aux * aux + 3 * aux2) % 11 == 0) {
                matriz[aux][aux2] = 1;
            }
        }
    }
    return matriz;
}
void acharVencedor(Competidor *competidores, int qtdTotal) {
    int aux;
    char vencedor[30];
    int pvencedor = competidores[aux + 1].pontuacao;
    strcpy(vencedor, competidores[0].nome);    // no for abaixo, nenhum nome vai ser copiado caso esteja em ordem decrescente. inicializar o vencedor como o primeiro competidor eh uma forma de contornar esse problema.
    for (aux = 0; aux < qtdTotal - 1; ++aux) { //-1 previne overflow quando aux == qtdTotal-1 procurar competidores[aux+1].pontuacao.
        if (competidores[aux].pontuacao < competidores[aux + 1].pontuacao) {
            strcpy(vencedor, competidores[aux + 1].nome);
            pvencedor = competidores[aux + 1].pontuacao;
        }
    }
    printf("\nvencedor: %s\n", vencedor);
    printf("pontuacao do vencedor: %d\n", pvencedor);
}

int main() {
    int qtdAtual, qtdTotal = 0, n, m, numTesouros = 0, cont = 0, aux, aux2, **matriz, x, y, pvencedor;
    printf("Digite o tamanho n para a matriz quadrada nxn: ");
    scanf("%d", &n);
    while (n != EOF) {
        if (cont == 0) { // aloca matriz pela primeira vez via malloc
            int **matriz = (int **)malloc(sizeof(n * sizeof(int *)));
            *matriz = (int *)malloc(sizeof(n * sizeof(int)));
            if (*matriz == NULL) {
                printf("Erro na alocacao.\n");
                exit(1);
            }
            if (matriz == NULL) {
                printf("Erro na alocacao.\n");
                exit(1);
            }
        } else { // a partir da segunda rodada, realoca a matriz
            int **matriz = (int **)realloc(*matriz, n * sizeof(int));
            matriz = (int **)realloc(*matriz, n * sizeof(int *));
            if (*matriz == NULL) {
                printf("Erro na alocacao.\n");
                exit(1);
            }
            if (matriz == NULL) {
                printf("Erro na alocacao.\n");
                exit(1);
            }
        }
        for (aux = 0; aux < n; ++aux) { // encontrar o numero de tesouros
            for (aux2 = 0; aux2 < n; ++aux2) {
                if ((4 * aux * aux + 3 * aux2) % 11 == 0) {
                    ++numTesouros;
                }
            }
        }
        matriz = colocarTesouros(matriz, n, &numTesouros);
        printf("\nDigite o numero de competidores na rodada: ");
        scanf("%d", &qtdAtual);
        qtdTotal += qtdAtual;

        Competidor *competidores;
        Competidor *leCompetidores(Competidor * competidores, int qtdAtual, int qtdTotal);

        printf("\nDigite o numero de tentativas para cada participante: ");
        scanf("%d", &m);
        for (aux = (qtdTotal - qtdAtual); aux < qtdTotal; ++aux) { // estabelece "m" como o numero de tentativas a cada participante do jogo atual
            competidores[aux].tentativas = m;
            for (aux2 = 0; aux2 < m; ++aux2) { // cada competidor joga m vezes e obtem a pontuacao da rodada
                printf("\nCompetidor %s, insira suas coordenadas no formato 'x, y' %d vezes: ", competidores[aux].nome, m);
                scanf("%d, %d", &x, &y);
                if (matriz[x][y] == 1) {
                    ++competidores[aux].pontuacao;
                    matriz[x][y] = 0;
                }
            }
        }
        ++cont;
    }
    Competidor *competidores;
    acharVencedor(competidores, qtdTotal);
    free(matriz);
    free(*matriz);
    free(competidores);

    return 0;
}